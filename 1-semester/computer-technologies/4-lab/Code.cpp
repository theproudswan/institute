// Вариант 2

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main(){

  srand(time(NULL));

  int SIZE; // Размер массива
  float *A; // Создаём пустой динамический массив

  float min; // Поиск минимального значения
  int min_pos; // Место минимального элемента

  float max; // Поиск максимального значения
  int max_pos; // Место максимального элемента

  float buf = 0;

  bool flag; // Флаг, отвечающий, хотим ли мы ввести массив с клавиатуры или сгенерировать

  cout<<"Ввести массив с клавиатуры (0) или сгенерировать автоматически (1): ";
  cin>>flag;

  if (flag == 0){
      cout<<"Введите размер массива: ";
      cin>>SIZE;
      A = new float [SIZE]; // Инициализация массива

      cout<<"\nВведите массив:"<<endl;
      for (int i=0; i<SIZE; ++i){ // В цикле вводим массив
        cout<<"A["<<i<<"] = ";
        cin>>A[i];
      }
  } else {
      SIZE = rand()%10 + 1;
      A = new float [SIZE]; // Инициализация массива
      cout<<"Сгенерирован массив из "<<SIZE<<" элементов\n";
      for (int i=0; i<SIZE; ++i){ // В цикле вводим массив
        A[i] = (rand()%100)/10.0; // Заполняем массив рандомными дробными числами
        cout<<"A["<<i<<"] = "<<A[i]<<endl;
      }
  }

  min = A[0];
  min_pos = 0;

  max = A[0];
  max_pos = 0;

  for (int i = 0; i<SIZE; ++i){ // Перебираем все элементы массива
      if (A[i]>max){ // Если встретился элемент больше текущего максимума
          max = A[i]; // Перезаписываем текущий максимум
          max_pos = i; // Запоминаем индекс нового максимума
      }
  }
  // Меняем местами последний и максимальный элемент
  buf = A[SIZE - 1];
  A[SIZE - 1] = A[max_pos];
  A[max_pos] = buf;

  for (int i = 0; i<SIZE; ++i){ // Перебираем все элементы массива
      if (A[i]<min){ // Если встретился элемент меньше текущего минимума
          min = A[i]; // Перезаписываем текущий минимум
          min_pos = i; // Запоминаем индекс нового минимума
      }
  }
  // Меняем местами нулевой и минимальный элемент
  buf = A[0];
  A[0] = min;
  A[min_pos] = buf;

  if (min == max){
      cout <<"\nВ полученном массиве все значения одинаковы.\nМинимум равен максимуму.\n";
      return 0;
  }

  cout << "\nМассив после замены:\n";
  for (int i=0; i<SIZE; ++i){ //В цикле вводим массив
    cout<<"A["<<i<<"] = "<<A[i]<<endl;
  }

  cout<<"\nСортировка массива начата";
  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j < SIZE - i - 1; j++) {
      if (A[j] < A[j + 1]) {
        buf = A[j]; // Записали в дополнительную переменную
        A[j] = A[j + 1]; // Меняем местами
        A[j + 1] = buf; // Значения элементов
      }
    }
  }
  cout<<"\n...\nСортировка массива окончена\n";

  cout<<"\nМассив после сортировки:\n";
  for (int i=0; i<SIZE; ++i){ //В цикле вводим массив
    cout<<"A["<<i<<"] = "<<A[i]<<endl;
  }

    return 0;
}
