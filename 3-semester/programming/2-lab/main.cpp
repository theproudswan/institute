#include <iostream>
#include <utility>
#include <iomanip>

#define NOT_FOUND -1
#define FUNCTIONS_NUMBER 4
#define PRINT_FUNC_NAME(var) std::cout << setw(20) << var

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
typedef pair<int, uint>(*SEARCH)(int* input, size_t size, int key);

int main(){
    size_t size;
    int sought;
    SEARCH funcs[] = {BetterLinearSearch, SentinelLinearSearch, AnotherLinearSearch, BinarySearch};
    cout << "Введите размер массива для поиска: ";
    cin >> size;
    int* arr = new int [size];
    for (size_t i = 0; i < size; ++i){
        arr[i] = i;
    }

    cout << endl << "Сформированный массив: " << endl;
    for (int i = 0; i < size; ++i){
        cout << arr[i] << ' ';
    }
    cout << endl;
    cout << endl << "Введите искомый элемент: ";
    cin >> sought;

    pair<int, uint> result;
    cout << endl;
    cout << setw(20) << "Алгоритм поиска" << "\t\t" << "Позиция" << "\t\t" << "Количество сравнений" << endl;
    for (size_t i = 0; i < FUNCTIONS_NUMBER; ++i){
        result = funcs[i](arr, size, sought);
        cout<< '\t' << setw(7) << result.first << setw(20) << result.second << endl;
    }
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
    uint comparison = 0;
    for (size_t i = 0; i < size; ++i){
        comparison += 2;
        if(input[i] == key) return {i, comparison};
    }
    return {NOT_FOUND, comparison};
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
