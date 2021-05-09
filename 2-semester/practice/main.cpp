#if defined(_WIN32)
    #define _CRT_SECURE_NO_WARNINGS
    #define CLEAR "cls"
#elif defined(_WIN64)
    #define _CRT_SECURE_NO_WARNINGS
    #define CLEAR "cls"
#elif defined(__unix__)
    #define CLEAR "clear"
#endif

#define SIZE 256

#include <iostream>
#include <ctime>
#include <cmath>
#include <iomanip>

using namespace std;

void FirstTask();

void SecondTask();

bool IsVowelEng(const char& c);
bool IsVowelRus(const wchar_t& c);

int Random(int min, int max); // Возвращает псевдослучайное число из диапазона [min, max)

void ThirdTask();

int main(){
    setlocale(LC_ALL, "");
    char input = 1;
    
    while(input){
        system(CLEAR);
        cout<<"Выберите номер задания\n"
        <<"1. log(x+1)\n"
        <<"2. Значения и график функции\n"
        <<"3. Посчитать количество двубуквенных сочетаний, состоящих из гласных\n\n"
        <<"0. Выход\n\n"
        <<"Ввод: ";
        cin>>input;
        system(CLEAR);
        switch(input){
            case '0':
                return 0;
            case '1':
                FirstTask();
                break;
            case '2':
                SecondTask();
                break;
            case '3':
                ThirdTask();
                break;
            default:
                cout<<"Ошибка: неверный номер задания\nВыберите из перечня\n\n";
                main();
        }
        cin.ignore();
        cout<<endl<<"Нажмите Enter для перехода в меню."<<endl;
        getchar();
    }
    return 0;
}

void FirstTask(){
    cout<<"Выбрано задание №1"<<endl;
    cout<<"log(x+1)\n\n";
   bool flag = 0;
   double x;
   cout<<"Ввести значение х с клавиатуры или принять за 0.65 [0/1]: "; cin>>flag;
   if(!flag){
       cout<<"Введите х: "; cin>>x;
   } else {
       x = 0.65;
   }
   
   double E = pow(10, -6);
   double y = 1;
   double sum = 0;
   int k = 1;
   
   cout<<endl<<endl;
   cout<<"x\ty"<<endl;
   while(abs(y) >= E){
      y = pow(-1, k+1) * pow(x, k)/k;
      sum += y;
      cout<<x<<'\t'<<y<<endl;
      ++k;
   }
   //cout<<endl<<"ln("<<x<<" + 1) = "<<log(x+1)<<endl<<endl;
   cout<<"Сумма ряда: "<<sum<<endl;
   cout<<"При точности Е: "<<E<<endl;
   cout<<"\nЗаписаить полученные значения в файл? (Да/Нет) [0/1]: "; cin>>flag;
   if(!flag){
       FILE *output;
       output = fopen("output.txt", "a+");
       if(output){
           fputs("\n\nЗадание №1\nlog(x+1)\n\n", output);
           fprintf(output, "Сумма ряда: %lf\nПри значении х: %lf\nПри точности Е: %lf\n\n", sum, x, E);
            fclose(output);
            cout<<"Информация успешно записана в файл \"output.txt\""<<endl;
       } else {
           cout<<"Ошибка записи в файл"<<endl;
       }
   }
   return;
}

void SecondTask(){
    cout<<"Выбрано задание №2"<<endl;
    cout<<"Значения и график функции\n\n";

    bool flag = 0;
    size_t size;
    cout<<"Введите размер матрицы: "; cin>>size;
    float **matrix = new float *[size];
    cout<<"Ввести матрицу вручную или сгенерировать случайно [0/1]: "; cin>>flag;
    cout<<endl;
    if(!flag){
        for(size_t i = 0; i<size; ++i){
            matrix[i] = new float [2];
            cout<<"x["<<i<<"] = "; cin >> matrix[i][0];
        }  
    } else {
        srand(time(NULL));
        for(size_t i = 0; i<size; ++i){
            matrix[i] = new float [2];
            matrix[i][0] = rand()%6 + 2 + (rand()%10)/10.0;
            cout<<"x["<<i<<"] = "<< matrix[i][0]<<endl;
        }
    }
    cout<<endl;
    cout<<"\nЗаписаить полученные значения в файл? (Да/Нет) [0/1]: "; cin>>flag;
   
       FILE  *output;
       output = fopen("output.txt", "a+");
     if(!flag){  
         if(output){
           fputs("\n\nЗадание №2\nЗначения и график функции\n\n", output);
           fputs("x   |\ty\n", output);
       } else {
           cout<<"Ошибка записи в файл"<<endl;
       }
     } else{
         fclose(output);
     }
    cout<<"Вычислим значение функции по формуле y = 2*x + \u221A(x^3)"<<endl<<endl; // \u221A в кодировке KOI8-R означает знак корня
    cout<<"x   |\ty"<<endl;
    for(size_t i = 0; i<size; ++i){
        cout<<"----|--------"<<endl;
        matrix[i][1] = 2*matrix[i][0] + sqrt(pow(matrix[i][0], 3));
        cout<<setw(3)<<matrix[i][0]<<" | "<<matrix[i][1]<<endl;
        if(!flag){
            if(output){
                fputs("----|--------\n", output);
                fprintf(output, "%.1f | %f\n", matrix[i][0], matrix[i][1]);
            } 
        }
    }
    if(!flag){
            if(output){
                    fclose(output);
                    cout<<"Информация успешно записана в файл \"output.txt\""<<endl;
            } else {
                cout<<"Ошибка записи в файл"<<endl;
            }
        }
    cout<<endl<<endl<<"Построим график"<<endl<<endl<<endl;
    cout<<'^'<<endl<<'|'<<endl;
    for(size_t i = size; i>0; i--){
        cout<<'|'<<setw(static_cast<int>(matrix[i - 1][0])*2)<<('*')<<endl; // [i - 1], чтобы не было проблем с приведением типов, 
                                                                          // т.к. в противном случае счётчике i перед выходом попытается принять отрицательное значение, чего не допускает тип size_t
    }
    for(size_t i = size - 1; i>0; --i){
        cout<<"----";
    }
    cout<<"->"<<endl;
    for (int i = 0; i<size; ++i){
        delete []matrix[i];
    }
    delete []matrix;
    return;
}

bool IsVowelEng(const char& c){
    char vowels[] = {'a', 'e', 'i', 'o', 'u', 'y'};
    for(size_t i = 0; i<(sizeof(vowels)/sizeof(char)); ++i){
        if((c == vowels[i])||(c == static_cast<char>(static_cast<int>(vowels[i] - 32)))) 
            return 1;
    }
    return 0;
}
bool IsVowelRus(const wchar_t& c){
    wchar_t vowels[] = {L'у', L'е', L'ы', L'а', L'о', L'я', L'и', L'ю', L'э'};
    for(size_t i = 0; i<(sizeof(vowels)/sizeof(wchar_t)); ++i){
        if((c == vowels[i])||(c == static_cast<wchar_t>(static_cast<int>(vowels[i] - 32)))) 
            return 1;
    }
    return 0;
}
// Возвращает псевдослучайное число из диапазона [min, max)
int Random(int min, int max) {
    max++;
  return min + rand() % (max - min);
}

void ThirdTask(){
    cout<<"Выбрано задание №3"<<endl;
    cout<<"Посчитать количество двубуквенных сочетаний, состоящих из гласных\n\n";
    
    wchar_t string[SIZE] = {0};
    unsigned string_length = 0;
    bool flag = 0;
    bool language = 0;
    unsigned vowel_pairs_counter = 0;
    printf("Ввести строку вручную или сгенерировать случайно [0/1]: "); cin >> flag;
    printf("На английском языке или русском [0/1]: "); cin >> language;
    cin.ignore();
    cout<<endl;
    if(!flag){
        printf("\nВведите строку: ");
        while(1) {
            scanf("%lc", &string[string_length]); // Посимвольно считываем строку в бесконечном цикле
            if ((int)string[string_length] == 10){ // Если встретили символ с кодом 10 (возврат каретки по таблице ASCII)
                string_length++; // К длине строки добавляется 0-байт
                break; // Выходим из цикла
            }
            string_length++; // Перезаписываем количество введённых символов
        }
        printf("Введена строка: ");
            for(size_t i = 0; i<string_length; ++i){
                printf("%lc", string[i]);
            }
    } else {
        srand(time(NULL));
        string_length = rand()%20+5;
        if(!language){ // Eng
            printf("Сгенерированная строка: ");
            for(size_t i = 0; i<string_length; ++i){
                // Случайный символ по формуле rand()%[Количество символов в языке - 1] + Порядковый номер в таблице ASCII (+32 для добавления маленьких буковок)
              string[i] = static_cast<char>(rand()%25+65 + (rand()%2)*32); // Заглавные и строчные буквы
                printf("%lc", string[i]);
            }
        } else { // Rus
                printf("Сгенерированная строка: ");
                for(size_t i = 0; i<string_length; ++i){
                     // Случайный символ по формуле rand()%[Количество символов в языке - 1] + Порядковый номер в таблице KOI8-R (+32 для добавления маленьких буковок)
                    string[i] = static_cast<wchar_t>(Random(1040, 1103)); // Заглавные и строчные буквы
                    printf("%lc", string[i]);
                }
        }
        
    }
    printf("\n");
    
    if(!language){ // Eng
        for(size_t i = 1; i<string_length; ++i){
            if(IsVowelEng(string[i-1]) && IsVowelEng(string[i])){
                ++vowel_pairs_counter;
            }
        }
    } else { // Rus
        for(size_t i = 1; i<string_length; ++i){
            if(IsVowelRus(string[i-1]) && IsVowelRus(string[i])){
                //printf("%lc", string[i-1]);
                //printf("%lc\n", string[i]);
                ++vowel_pairs_counter;
            }
        }
    }
    
    printf("Количество двубуквенных сочетаний из гласных: %u\n", vowel_pairs_counter);
    
    cout<<"\nЗаписаить полученные значения в файл? (Да/Нет) [0/1]: "; cin>>flag;
    if(!flag){  
       FILE  *output;
       output = fopen("output.txt", "a+");
         if(output){
           fputs("\n\nЗадание №3\nПосчитать количество двубуквенных сочетаний, состоящих из гласных\n\n", output);
           fprintf(output, "Строка: ");
           for(size_t i = 0; i<string_length; ++i){
                    fprintf(output, "%lc", string[i]);
            }
           fprintf(output, "\nДвубуквенных сочетаний из гласных: %d", vowel_pairs_counter);
           fclose(output);
            cout<<"Информация успешно записана в файл \"output.txt\""<<endl;
       } else {
           cout<<"Ошибка записи в файл"<<endl;
       }
     }
    return;
}
