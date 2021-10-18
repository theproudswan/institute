#include <iostream>
#include <utility>
#include <iomanip>

#define NOT_FOUND -1
#define FUNCTIONS_NUMBER 4
#define PRINT_FUNC_NAME(var) std::cout << setw(20) << var
#define ARR_SIZE_MANUAL 30
#define LETTERS_COUNT 26
#define ARR_SIZE_AUTO 500000
#define KEYS_COUNT 15
using namespace std;

template <typename T>
pair<int, uint> SentinelLinearSearch(T* input, size_t size, T key);

template <typename T>
pair<int, uint> BinarySearch(T* input, size_t size, T key);

template <typename T>
pair<int, uint> AnotherLinearSearch(T* input, size_t size, T key);

template <typename T>
pair<int, uint> BetterLinearSearch(T* input, size_t size, T key);

//template <typename T>
typedef pair<int, uint>(*INT_SEARCH)(int* input, size_t size, int key);
typedef pair<int, uint>(*CHAR_SEARCH)(char* input, size_t size, char key);


int main(){
    //size_t size;
    char char_sought;
    CHAR_SEARCH char_funcs[] = {BetterLinearSearch, SentinelLinearSearch, AnotherLinearSearch, BinarySearch};
    bool creation_flag = 0;
    // cout << "Введите размер массива для поиска: ";
    // cin >> size;
    // int* arr = new int [size];
    // for (size_t i = 0; i < size; ++i){
    //     arr[i] = i;
    // }
    cout << "Сгенерировать массив автоматически или ввести вручную? (0/1): ";
    cin >> creation_flag;
    char* char_array = new char[ARR_SIZE_MANUAL];
    if(!creation_flag){
        for (size_t i = 0; i < ARR_SIZE_MANUAL; ++i)
            //char_array[i] = static_cast<char>(rand()%25+65 + (rand()%2)*32); // Заглавные и строчные буквы
            char_array[i] = static_cast<char>(i%LETTERS_COUNT + 97);
    } else {
        for (size_t i = 0; i < ARR_SIZE_MANUAL; ++i)
            cin >> char_array[i];
    }

    cout << endl << "Сформированный массив: " << endl;
    for (int i = 0; i < ARR_SIZE_MANUAL; ++i){
        cout << char_array[i] << ' ';
    }
    cout << endl;
    cout << endl << "Введите искомый элемент: ";
    cin >> char_sought;


    #define OCCURRENCES


    pair<int, uint> result;
    cout << endl;
    cout << setw(20) << "Алгоритм поиска" << "\t\t" << "Результат" << "\t\t" << "Количество вхождений" << endl;
    for (size_t i = 0; i < FUNCTIONS_NUMBER; ++i){
        result = char_funcs[i](char_array, ARR_SIZE_MANUAL, char_sought);
        cout<< '\t' << setw(7) << result.first << setw(20) << result.second << endl;
    }
    #undef OCCURENCES
    
    delete[] char_array;

    cout << "\n\n\n\n";

    INT_SEARCH int_funcs[] = {BetterLinearSearch, SentinelLinearSearch, AnotherLinearSearch, BinarySearch};

    int* int_array = new int[ARR_SIZE_AUTO];
    int int_sought;

    for (size_t i = 0; i < ARR_SIZE_AUTO; ++i){
        int_array[i] = i;
    }

    cout << setw(20) << "Алгоритм поиска" << "\t\t" << "Результат" << "\t\t" << "Количество сравнений" << endl;
    for (int i = KEYS_COUNT; i >= 0; --i){
        int_sought = ARR_SIZE_AUTO / i;
        if(!i) int_sought = ARR_SIZE_AUTO + 1;
        for (size_t j = 0; j < FUNCTIONS_NUMBER; ++j){
            result = int_funcs[j](int_array, ARR_SIZE_AUTO, int_sought);
            cout<< '\t' << setw(7) << result.first << setw(20) << result.second << endl;
        }
        cout << endl;
    }
    
    delete[] int_array;
    return 0;
}
template <typename T>
pair<int, uint> BinarySearch(T* input, size_t size, T key){
    PRINT_FUNC_NAME(__func__);     
    uint comparisons = 0;
    size_t left = 0, right = size - 1;
    while (left <= right){
        comparisons++;
        size_t middle = (left + right)/2;
        if (input[middle] == key) {
            comparisons++;
            return {middle, comparisons};
        } else if(input[middle] != key) {
            comparisons++;
            if(input[middle] > key){
                comparisons++;
                right = middle - 1;
            } else {
                comparisons++;
                left = middle + 1;
            }
            
        } 
    }
    comparisons++;
    return {NOT_FOUND, comparisons};
}

template <typename T>
pair<int, uint> BetterLinearSearch(T* input, size_t size, T key){
    PRINT_FUNC_NAME(__func__); 
    int occurrences_count = 0;
    uint comparison = 0;
    for (size_t i = 0; i < size; ++i){
        #ifndef OCCURENCES
            comparison += 2;
            if(input[i] == key) return {i, comparison};
        #else
            if(input[i] == key) {
                occurrences_count++;
                if(i + 1 < size){
                    if(input[i+1] != key){
                        return {i, occurrences_count};
                    } 
                } else {
                    return {i, occurrences_count};
                }
            }
        #endif
    }
    #ifndef OCCURENCES
        return {NOT_FOUND, comparison};
    #else
        return {NOT_FOUND, occurrences_count};
    #endif
}

template <typename T>
pair<int, uint> SentinelLinearSearch(T* input, size_t size, T key){
    PRINT_FUNC_NAME(__func__); 
    uint comparison = 0;
    T last = input[size - 1];
    input[size - 1] = key;
    size_t i = 0;
    while(input[i] != key){
        i++;
    }
    comparison = i;
    input[size - 1] = last;
    comparison += 2;
    if(i < size - 1 || input[size - 1] == key) return {i, comparison};
    return {NOT_FOUND, comparison};
}

template <typename T>
pair<int, uint> AnotherLinearSearch(T* input, size_t size, T key){
    PRINT_FUNC_NAME(__func__); 
    uint comparison = 0;
    size_t i = 0;
    while(key >= input[i]){
        i++;
    }
    comparison = i + 1;
    if (input[i] == key) return {i, comparison};
    return {NOT_FOUND, comparison};
}
