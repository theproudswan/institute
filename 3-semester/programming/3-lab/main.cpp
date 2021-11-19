//============================================================================
// Name        : list.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <iostream>
#include <string>
#include <limits>
#include <utility>

#define MAX_STRING_LENGTH 5
#define MAX_WORDS_COUNT 5
#define LETTERS_COUNT 26

using namespace std;

template <typename T>
class LinkedList {
public:
  struct Node {
    T value{};
    Node* next = nullptr;
    Node* prev = nullptr;
  };

  ~LinkedList(){
    while(head){
      PopFront();
    }
  }

  void PushFront(const T& value){
    Node* n_ptr = new Node{value};
    n_ptr->next = head;
    n_ptr->prev = nullptr;
    n_ptr->value = value;
    head = n_ptr;
    if (!GetSize())
    	head = tail = n_ptr;
    else
    	head = n_ptr;
    head->prev = tail;
    tail->next = head;
    size++;
  }

  void PushBack(const T& value){
	  Node* n_ptr = new Node{value};
	  if (IsEmpty()){
		  head = n_ptr;
		  tail = n_ptr;
		  size++;
		  return;
	  }
	  n_ptr->next = nullptr;
	  n_ptr->value = value;
	  n_ptr->prev = tail;

	  tail->next = n_ptr;
	  tail = n_ptr;
	  tail->next = head;
	  size++;
  }

  void InsertAfter(Node* node, const T& value){
      if(node == nullptr){
          PushFront(value);
      } else if(node == tail){
    	  PushBack(value);
      } else {
        Node* tmp = new Node{value};
        tmp->next = node->next;
        node->next = tmp;
      }
      size++;
  }
  void RemoveAfter(Node* node){
    if (!node){
      PopFront();
      size--;
    } else {
      if((node->next) != nullptr){
        Node* tmp = node->next;
        node->next = tmp->next;
        delete tmp;
        size--;
      }
    }
  }
  void PopFront(){
    if(head){
      Node* n_ptr = head->next;
      delete head;
      head = n_ptr;
      head->prev = tail;
      tail->next = head;
      size--;
    }
  }
  void PopBack(){
	  if(tail){
	      Node* n_ptr = tail->prev;
	      delete tail;
	      tail = n_ptr;
	      tail->next = head;
	      size--;
	  }
  }

  Node* GetHead() { return head; }
  const Node* GetHead() const { return head; }
  Node* GetTail() { return tail; }
  const Node* GetTail() const { return tail; }
  bool IsEmpty() const { return size == 0; }
  size_t GetSize() const { return size; };


  pair<size_t, T> FindMax(){
	  size_t index;
	  size_t iter_count = -1;
	  T max = numeric_limits<T>::min();
	  Node* tmp = head;
	  while(tmp){
		  iter_count++;
		  if (tmp->value > max){
			  max = tmp->value;
			  //cout << index << ": " << max << endl;
			  index = iter_count;
		  }
		  tmp = tmp->next;
	  }
	  return make_pair(index, max);
  }

  size_t LowerBound(const T& to_find) const{
	  Node* tmp = head;
	  size_t index = 0;
	  while(tmp){
	  		  if(tmp->value == to_find){
	  			  return index;
	  		  }
	  		  tmp = tmp->next;
	  		  index++;
	  }
	  return GetSize();
  }
  size_t UpperBound(const T& to_find) const {
  	  Node* tmp = tail;
  	  size_t index = GetSize() - 1;
  	  while(tmp){
  		  //cout << tmp->value << endl;
  	  		  if(tmp->value == to_find){
  	  			  //cout << tmp->value << " found!" << endl;
  	  			  return index;
  	  		  }
  	  		  tmp = tmp->prev;
  	  		  index--;
  	  }
  	  return GetSize();
   }

  Node* operator[] (size_t index) const {
	  if (index >= GetSize()) {
		  //cerr << "Невозможно обратиться к элементу: индекс " << index << " за пределами списка" << endl;
		 // return nullptr;
	  }
	  Node* tmp = head;
	  size_t i = 0;
	  while (i < index){
		  tmp = tmp->next;
		  i++;
	  }
	  return tmp;
  }

private:
  Node* head = nullptr;
  Node* tail = nullptr;
  size_t size = 0;
};

void Find(const LinkedList<string>& list) {
	string to_find;

	cout << "Введите имеющееся слово для поиска: ";
	cin >> to_find;
	cout << "Первое вхождение: " << list.LowerBound(to_find) << endl;
	cout << "Последнее вхождение: " << list.UpperBound(to_find) << endl;
	cout << endl;
	cout << "Введите отсутствующее слово для поиска: ";
	cin >> to_find;
	cout << "Первое вхождение: " << list.LowerBound(to_find) << endl;
	cout << "Последнее вхождение: " << list.UpperBound(to_find) << endl;
}

void RingPrint (const LinkedList<string>& list) {
	for (size_t i = 0; i < 2 * list.GetSize(); ++i){
		cout << "list[" << i << "] = " << list[i]->value << endl;
	}
}

void Ring (LinkedList<string>& list){
	cout << "Убедимся, что список кольцевой. Выведем элементы от 0 до "
		 << 2 * list.GetSize() - 1 << " включительно: " << endl;
	RingPrint(list);
	cout << endl << endl;
	cout << "Теперь добавим строку \"begin_test_string\" в начало и \"end_test_string\" в конец." << endl;
	list.PushFront("begin_test_string");
	list.PushBack("end_test_string");
	cout << "Проверим, не случилась ли инвалидация указателей:" << endl;
	RingPrint(list);
	cout << endl << endl << "Удалим вспомогательные строки и заново проверим целостность списка:\n";
	list.PopFront();
	list.PopBack();
	RingPrint(list);
}

void RunTests (LinkedList<string>& list){
	//Find(list);
	//Ring(list);

}

int main() {
	LinkedList<string> list;
	bool input_flag = 0;
	cout << "Выберите ручной или автоматический ввод (0/1) : ";
	cin >> input_flag;
	size_t list_size;
	cout << "Введите размер списка: ";
	cin >> list_size;
	if (!input_flag){
		for (size_t i = 0; i < list_size; ++i){
			string input_tmp;
			cin >> input_tmp;
			list.PushBack(input_tmp);
		}
	} else {
		for (size_t i = 0; i < list_size; ++i){
			string input_tmp = []{
				string result;
				short unsigned res_length = rand() % MAX_STRING_LENGTH + 1;
				for (short unsigned i = 0; i < res_length; ++i){
					result += static_cast<char>(rand() % (LETTERS_COUNT - 1) + 65 + (rand() % 2) * 32);
				}
				return result;
			}();
			list.PushBack(input_tmp);
		}
	}

	cout << "Сформирован список: " << endl;

	for (size_t i = 0; i < list_size; ++i){
		cout << "list[" << i << "] = " << list[i]->value << endl;
	}

	cout << endl << endl;

	RunTests(list);

	return 0;
}
