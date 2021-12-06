#pragma once

#include "LinkedList.h"

template <typename T> 	// Шаблон класса
class Deque{			// Класс Дек
public:					// Публичная секция
	Deque () = default;	// Конструктор по умолчанию нас устраивает стандартный
	Deque (const Deque<T>& lhs) = delete;
	void Clear();
	const T GetFirst() const;
	T& GetFirst();
	const T GetLast() const;
	T& GetLast();
	void PushBack(const T& _value);
	void PushFront(const T& _value);
	void PopFront();
	void PopBack();
	const T operator[] (const size_t index) const;
	T& operator[] (const size_t index);
	void Print();
private:
	LinkedList<T> data;
};
template <typename T>
void Deque<T>::Clear() {
    if (!data.GetSize()) cerr << "Ошибка! Нечего удалять, дек пуст" << endl;
    while (data.GetHead()) {
        data.PopFront();
    }
}
template <typename T>
const T Deque<T>::GetFirst() const {
    return data.GetHead() -> value;
}
template <typename T>
T & Deque<T>::GetFirst() {
    return data.GetHead() -> value;
}
template <typename T>
const T Deque<T>::GetLast() const {
    return data.GetTail() -> value;
}
template <typename T>
T & Deque<T>::GetLast() {
    return data.GetTail() -> value;
}
template <typename T>
void Deque<T>::PushBack(const T & _value) {
    data.PushBack(_value);
}
template <typename T>
void Deque<T>::PushFront(const T & _value) {
    data.PushFront(_value);
}
template <typename T>
void Deque<T>::PopFront() {
    data.PopFront();
}
template <typename T>
void Deque<T>::PopBack() {
    data.PopBack();
}
template <typename T>
const T Deque<T>::operator[](const size_t index) const {
    if (index >= data.GetSize()) {
        cerr << "Ошибка! Индекс за пределами дека." << endl;
        return numeric_limits < T > ::min();
    }
    return data[index];
}
template <typename T>
T & Deque<T>::operator[](const size_t index) {
    if (index >= data.GetSize()) {
        cerr << "Ошибка! Индекс за пределами дека." << endl;
        return data[index] -> value;
    }
    return data[index] -> value;
}
template <typename T>
void Deque<T>::Print() {
    if (!data.GetSize()) cerr << "Ошибка! Дек пустой" << endl;
    for (size_t i = 0; i < data.GetSize(); ++i) {
        cout << "deque[" << i << "] = " << data[i] << endl;
    }
}
