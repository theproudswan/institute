#define _REENTRANT
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <time.h>
#include <math.h>
#include <pthread.h>

#define MAX_DIGITS 	6	//Максимальное количество цифр в размерах изображения - должно быть больше 3
#define CLEAR 		clear(in_file, out_file, w, h);	//Закрытие файлов и отчистка динамической памяти
#define WRITE_ERR 	print_error("Ошибка записи в файл.\n");
#define	READ_ERR	print_error("Неожиданный конец файла.\n");
#define SELCLOCK	CLOCK_REALTIME

int core[3][3] = {	{ -1, -2, -1 },
					{  0,  0,  0 },
					{  1,  2,  1 }};
float intensity[3]	=	{0.2126, 0.7152, 0.0722};	//Интенсивность разных цветов
unsigned char** pic = NULL;
int** res = NULL;


unsigned char brightness(unsigned char r, unsigned char g, unsigned char b);	//Яркость точки 
int convolution(unsigned char** arr, char direction, int x, int y);	//Свертка изображения.
void* filter(void* args);	//Обработка полоски изображения
void print_error(char* err_text);	//Вывод ошибки из библиотеки errno, либо err_text, если errno = 0
void clear(int fd1, int fd2, int w, int h);

//Аргументы:
//tsobel <input file> <output file> [threads]

int main(int argc, char* argv[])
{
	int w = 0, h = 0;
	int thread_count = 1;
	if (argc < 3)
	{
		printf("Недостаточно аргументов.\n");
		return 1;
	}
	if (argc > 3)
	{
		thread_count = atoi(argv[3]);
		if (thread_count < 1)
		{
			printf("Неправильно указано количество потоков.\n");
			return 1;
		}
	}
	int in_file = open(argv[1], O_RDONLY);
	if (in_file < 0)
	{
		perror("Ошибка открытия файла.");
		return errno;
	}
	int out_file = open(argv[2], O_CREAT | O_WRONLY, 0666);
	if (out_file < 0)
	{
		perror("Ошибка создания файла.");
		return errno;
	}
	char buf[MAX_DIGITS];
	char temp;
	buf[0] = '\0';
	buf[1] = '\0';
	if (read(in_file, buf, 3) != 3 || buf[0] != 'P' || buf[1] != '6')	//Чтение метки
	{
		printf("Неподдерживаемый формат файла. Поддерживаются только файлы PNM формата P6.\n");
		CLEAR
		return EBADF;
	}
	if (write(out_file, "P6\n", 3) != 3)
	{
		CLEAR		
		WRITE_ERR
	}
	int i;
	for (i = 0; i < MAX_DIGITS; i++)	
	{
		if (read(in_file, &temp, 1) != 1)
		{
			CLEAR
			READ_ERR
		}
		if (i == 0 && temp == '#')	//Пропуск комментариев
		{
			while (temp != '\n')
			{
				if (read(in_file, &temp, 1) != 1)
				{
					CLEAR
					READ_ERR
				}
			}
			i = -1;	//Следующая итерация будет тоже с i == 0
			continue;
		}
		if (temp < '0' || temp > '9')
		{
			buf[i] = '\0';
			break;
		}
		else 
			buf[i] = temp;
	}
	if (i == MAX_DIGITS)
	{
		CLEAR
		printf("Файл слишком большой. Увеличьте MAX_DIGITS для поддержки больших изображений.\n");
		return 1;
	}
	if (write(out_file, &buf, strlen(buf)) != strlen(buf))
	{
		CLEAR
		WRITE_ERR
	}
	if (write(out_file, " ", 1) != 1)
	{
		CLEAR
		WRITE_ERR
	}
	w = atoi(buf);
	if (w <= 0)
	{
		printf("Некорректное значение ширины файла.\n");
		CLEAR
		return EDOM;
	}
	for (i = 0; i < MAX_DIGITS; i++)
	{
		if (read(in_file, &temp, 1) != 1)
		{
			CLEAR
			READ_ERR
		}
		if (temp < '0' || temp > '9')
		{
			buf[i] = '\0';
			break;
		}
		else 
			buf[i] = temp;
	}
	if (i == MAX_DIGITS)
	{
		CLEAR
		printf("Файл слишком большой. Увеличьте MAX_DIGITS для поддержки больших изображений.\n");
		return 1;
	}
	if (write(out_file, &buf, strlen(buf)) != strlen(buf))
	{
		CLEAR
		WRITE_ERR
	}
	if (write(out_file, "\n", 1) != 1)
	{
		CLEAR
		WRITE_ERR
	}
	h = atoi(buf);
	if (h <= 0)
	{
		printf("Некорректное значение высоты файла.\n");
		CLEAR
		return EDOM;
	}
	pic = malloc(w * sizeof(char*));
	res = malloc(w * sizeof(int*));
	if (pic == NULL || res == NULL)
	{
		CLEAR
		print_error("Ошибка выделения памяти");
	}
	for (int i = 0; i < w; i++)
	{
		pic[i] = malloc(h * sizeof(char));	//pic[w][h]
		res[i] = malloc(h * sizeof(int));
		if (pic[i] == NULL || res[i] == NULL)
		{
			for (int j = 0; j < i; j++)	//Очистка выделенной в предыдущих итерациях памяти
			{
				free(pic[j]);
				free(res[j]);
			}
			if (pic[i] != NULL)
				free(pic[i]);
			else
				free(res[i]);
			free(res);
			free(pic);
			print_error("Ошибка выделения памяти");
		}
	}
	printf("%ix%i\n", w, h);
	if (read(in_file, buf, 4) != 4)
	{
		CLEAR
		READ_ERR
	}
	buf[3] = '\0';
	if (atoi(buf) != 255)
	{
		CLEAR
		printf("Неправильный формат изображения.\n");
		return EBADF;
	}
	if (write(out_file, "255\n", 4) != 4)
	{
		CLEAR
		READ_ERR
	}
	for (int i = 0; i < h; i++)	//Чтение из файла в массив
	{
		for (int j = 0; j < w; j++)
		{
			unsigned char r, g, b;
			r = 0;
			g = 0;
			b = 0;
			if (read(in_file, &r, 1) != 1 || read(in_file, &g, 1) != 1 || read(in_file, &b, 1) != 1)
			{
				CLEAR
				READ_ERR
			}
			pic[j][i] = brightness(r, g, b);	//Запись в ч/б
		}
	}
	//Непосредственно сама обработка
	printf("Количество потоков: %i\n", thread_count);
	pthread_t* threads;
	int** args;
	int strip = 0;
	int max = 0;
	if (thread_count > 1)	//Подготовка к потокам
	{
		if (w * h > thread_count)
		{
			strip = w * h / thread_count;
			printf("Длина потоковой полосы: %i\n", strip);
		}
		else
		{
			thread_count = w * h;
			printf("В связи с малым размером файла, количество потоков урезано до %i\n", thread_count);
		}
		threads = malloc((thread_count - 1) * sizeof(pthread_t));
		args = malloc((thread_count - 1) * sizeof(int*));		
		if (threads == NULL || args == NULL)
		{
			CLEAR
			if (threads == NULL)
				free(args);
			else{
				free(threads);
				print_error("Ошибка выделения памяти.\n");
			    }
		}
		for (int i = 0; i < (thread_count - 1); i++)
		{
			args[i] = malloc (4 * sizeof(int));
			if (args[i] == NULL)
			{
				free(args);
				free(threads);
				CLEAR
				print_error("Ошибка выделения памяти.\n");
			}
			args[i][0] = w;
			args[i][1] = h;
			args[i][2] = strip;
			args[i][3] = i;
		}
	}
	int* return_max;
	clockid_t timer = SELCLOCK;
	struct timespec time;
	struct timespec st_time;
	clock_getres(timer, &time);
	printf("Запуск таймера, точность: %li с. %li нс.\n\n", time.tv_sec, time.tv_nsec);
	time.tv_nsec = 0;
	time.tv_sec = 0;	
	clock_gettime(timer, &st_time);	//Запуск таймера
	if (thread_count > 1)	//Запуск потоков
	{
		for (int i = 0; i < (thread_count - 1); i++)
		{
			if (pthread_create(threads + i, NULL, filter, (void*)args[i]) != 0)
			{
				CLEAR
					for (int j = 0; j < i; j++)
					{
						pthread_cancel(threads[j]);
						free(args[j]);
					}
				free(threads);
				free(args);
				print_error("Ошибка создания потоков.\n");
			}
		}
	}
	for (int i = (thread_count - 1) * strip; i < w * h; i++)	//Обработка последней полосы
	{
		int sobel = 0;		
		int x = i % w;
		int y = i / w;	
		if (x == 0 || x == w-1 || y == 0 || y == h-1)	//Края не обрабатываются
			sobel = 0;
		else
		{
			int gy = convolution(pic, 0, x, y);
			int gx = convolution(pic, 1, x, y);
			long catets = gx*gx + gy*gy;
			sobel = sqrt(catets);
			if (sobel > max)
				max = sobel;	//Нормализация	
		}	
		res[x][y] = sobel;
	}
	if (thread_count > 1)	//Соединение потоков
	{
		for (int i = 0; i < (thread_count - 1); i++)
		{
			if (pthread_join(threads[i], (void*) &return_max) != 0)
			{
				CLEAR
				for (int j = 0; j < (thread_count - 1); j++)
				{
					if (j > i)
						pthread_cancel(threads[j]);
					free(args[j]);
				}
				free(threads);			
				free(args);
				print_error("Ошибка обьединения потоков.\n");
			}
			if (*return_max > max)
				max = *return_max;
		}
	}
	clock_gettime(timer, &time);
	double nano = time.tv_sec * 1000000000 - st_time.tv_sec * 1000000000 + time.tv_nsec - st_time.tv_nsec;
	printf("Прошло %g нс.\n", nano);
	//Освобождение памяти
	if (thread_count > 1)	//Соединение потоков
	{
		for (int i = 0; i < (thread_count - 1); i++)
		{
			free(args[i]);
		}
		free(args);
		free(threads);
	}
	printf("Запись в файл...\n");
	for (int y = 0; y < h; y++)
		for (int x = 0; x < w; x++)
		{
			unsigned char normal = ((double) res[x][y] / (double) max) * 255;
			for (int k = 0; k < 3; k++)
			{
				if (write(out_file, &normal, 1) != 1)
				{
					CLEAR
					WRITE_ERR
				}
			}
		}
	CLEAR
	return 0;
}

unsigned char brightness(unsigned char r, unsigned char g, unsigned char b)	//Яркость точки 
{
	return r * intensity[0] + g * intensity[1] + b * intensity[2];
}

int convolution(unsigned char** arr, char direction, int x, int y)	//Свертка изображения
{
	int result = 0;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			if (direction == 0)	//Вертикальная свертка
				result += core[i][j] * arr[x+i-1][y+i-1];
			else
				result += core[j][i] * arr[x+i-1][y+i-1];
	return result;
}

void* filter(void* args)	//Аргументы - длина, ширина, размер полосы, номер потока
{
	int max = 0;
	int w = ((int*)args)[0];
	int h = ((int*)args)[1];
	int strip = ((int*)args)[2];
	int thread_n = ((int*)args)[3];
	for (int i = thread_n * strip; i < (thread_n + 1) * strip; i++)
	{
		int sobel = 0;		
		int x = i % w;
		int y = i / w;	
		if (x == 0 || x == w-1 || y == 0 || y == h-1)	//Края не обрабатываются
			sobel = 0;
		else
		{
			int gy = convolution(pic, 0, x, y);
			int gx = convolution(pic, 1, x, y);
			sobel = sqrt(gx*gx + gy*gy);
			if (sobel > max)
				max = sobel;	//Нормализация
		}
		res[x][y] = sobel;
	}
	int* res = malloc(sizeof(int));
		*res = max;
	pthread_exit(res);
}

void print_error(char* err_text)
{
	if (errno == 0)
		printf("%s", err_text);
	else
		perror("");
	exit(errno);
}

void clear(int fd1, int fd2, int w, int h)
{
	close(fd1);
	close(fd2);
	//Освобождение памяти
	if (pic != NULL)
	{
		for (int i = 0; i < w; i++)
		{
			free(pic[i]);
		}
		free(pic);
		pic = NULL;
	}
	if (res != NULL)
	{
		for (int i = 0; i < w; i++)
		{
			free(res[i]);
		}
		free(res);
		res = NULL;
	}
}
