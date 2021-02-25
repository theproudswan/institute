#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <exception>
#include <set>
#include <sstream>
#include <fstream>
#include <unistd.h>
#include <climits>
#include <iomanip>

using namespace std;

class Train{
public:
    explicit Train(){
        number = 0;
        capacity = 0;
        byed_tickets = 0;
        reserved_tickets = 0;
    }
    explicit Train(char new_number, int new_byed_tickets, int new_reserved_tickets, int new_capacity){
        number = new_number;
        byed_tickets = new_byed_tickets;
        reserved_tickets = new_reserved_tickets;
        capacity = new_capacity;
    }
    int GetTrainNumber(){
        return number;
    }
    int GetTotalTickets(){
        return byed_tickets + reserved_tickets;
    }
    int GetCapacity(){
        return capacity;
    }
    int GetReservedTickets(){
        return reserved_tickets;
    }
    int GetFreeSeats(){
        return capacity - byed_tickets - reserved_tickets;
    }
private:
    int number;
    int capacity;
    int byed_tickets;
    int reserved_tickets;
};

class Database {
public:
    void GetTrainList(string file_name, const int &flag) const{
        char buf[50];
        ifstream input (file_name);
        string line;
        if(!input){
            string err_msg = "File " + file_name + " not found";
            throw invalid_argument(err_msg);
        }
        int temp[4]={0};
        while (getline(input, line)){
            input>>buf;
            temp[0] = atoi(buf);
            input>>buf;
            temp[1] = atoi(buf);
            input>>buf;
            temp[2] = atoi(buf);
            input>>buf;
            temp[3] = atoi(buf);
            if(temp[1]+temp[2]>temp[3]){
                break;
            }
            if(flag == 0){
                cout<<"Номер поезда: "<<temp[0]<<endl;
                cout<<"Куплено билетов: "<<temp[1]<<endl;
                cout<<"Забронированно билетов: "<<temp[2]<<endl;
                cout<<"Всего мест: "<<temp[3]<<endl;
                cout<<endl<<endl;
            } else if (flag == 1){
                cout<<"В поезде №"<<temp[0]<<" свободно "<<setw(2)<<temp[3]-temp[2]-temp[1]<<" мест"<<endl;
            }
        }
    }
    string ChangeLine(string &line, const int &number, const int &count, const int &choise){
        int arr[4]={0}; //  Номер рейса / Забронировано билетов / Куплено билетов / Всего билетов
        int position = 0;
        int flag = 0;
        int temp = 0;
        line += " 1";
        for (int i = 0; i<line.size(); ++i){
            if(line[i] == ' '){
                flag += 1;
            }
            if ((flag!=0)&&(line[i]!=' ')){
                arr[position] = temp/10;
                temp = 0;
                position++;
                flag = 0;
            }
            if((flag==0)&&(line[i]!=' ')){
                temp += line[i] - '0';
                temp*=10;
            }
        }
        train = Train(arr[0], arr[1], arr[2],arr[3]);
        if(choise == 0){
            if(train.GetTotalTickets()+count>train.GetCapacity()){
                throw invalid_argument("Недопустимое количество билетов");
            }
            arr[1]+=count;
        } else if(choise == 1){
            if(train.GetTotalTickets()+count>train.GetCapacity()){
                throw invalid_argument("Недопустимое количество билетов");
            }
            arr[2]+=count;
        } else if(choise == 2){
            if(train.GetReservedTickets()-count < 0){
                throw invalid_argument("Недопустимое количество билетов");
            }
            arr[1]-=count;
        }
        string result = to_string(arr[0]) + "                  " + to_string(arr[1])+"                  " + to_string(arr[2])+"                 "+ to_string(arr[3]);
        return result;
    }

    void EditFile(string file_name, int i_number_line_delete, const int &number, const int &count, const int &choise){
        ifstream file_in;
        file_in.open(file_name);
        if(!file_in){
            string err_msg = "File " + file_name + " not found";
            throw invalid_argument(err_msg);
        }
          int i_number_line_now = 0; //счётчик строк
          string line; //для хранения строки
          string line_file_text; //для хранения текста файла
          string buf_line;
         while(getline(file_in,line))
         {
           i_number_line_now++;

           if(!(i_number_line_now == i_number_line_delete))
           {
               line_file_text.insert(line_file_text.size(),line); /*дабавить строку*/
               /*добавить перенос на слудующую строку*/
               line_file_text.insert(line_file_text.size(),"\n");
           } else {
               buf_line = line;
           }
         }
         file_in.close();
          //теперь в line_file_text будет содержаться измененный текст файла, теперь можно перезаписать файл
         std::ofstream file_out;
         file_out.open (file_name, std::ios::trunc | std::ios::binary); //открыть и обрезать
         //записать
         file_out.write(line_file_text.c_str(), line_file_text.size());
         file_out.write(ChangeLine(buf_line, number, count, choise).c_str(), ChangeLine(buf_line, number, count, choise).size());
         file_out.clear();
         file_out.close();
    }

    void BookTicket (const string & file_name, const int& choise){
        ifstream input (file_name);
        char buf[50];
        int number = INT_MIN;
        cout << "Номер рейса: ";
        cin >> number;
        int count = INT_MIN;
        cout << "\nКоличество билетов: ";
        cin >> count;
        int capasity;
        if(!input){
            string err_msg = "File " + file_name + " not found";
            throw invalid_argument(err_msg);
        }
        if (number < 1){
            stringstream string_error;
            string_error << "Некорректно введён номер рейса";
            throw invalid_argument(string_error.str());
        }
        if (count < 1){
            stringstream string_error;
            string_error << "Некорректное количество билетов для операции";
            throw invalid_argument(string_error.str());
        }
        bool flag = 0;
        string line;
        int line_number = 1;
        while (getline(input, line)){
            input>>buf;
            line_number++;
            if(atoi(buf) == number){
                input.close();
                EditFile(file_name, line_number, number, count, choise);
                cout<<"\033[1;32m"<<"\nРейс найден. Операция прошла успешно."<<"\033[0m\n"<<endl;
                flag = 1;
            } else {
                input.ignore(10);
            }
        }
        if(!flag){
            stringstream string_error;
            string_error << "Номер рейса не найден";
            throw invalid_argument(string_error.str());
        }
    }


    istream& operator >> (const string & file_name){
        int number;
        int capacity = -1;
        int byed_tickets = -1;
        int reserved_tickets = -1;

        ifstream input (file_name);
        string line;

            stringstream string_error;
            string data_str; // дата строкой
            string endError = ""; // ловим лишний символ в конце даты
            while (getline(cin, data_str)){
                if (input >> data_str) {
            		stringstream d(data_str); // парсим дату на значения год, мес, день
            		d >> number;
            		d >> byed_tickets;
            		d >> reserved_tickets;
                    d >> capacity;
            		d >> endError;
            		// проверяем и передаем корректные данные для работы
                    if (endError == ""){
                        train = Train(number, byed_tickets, reserved_tickets, capacity);
                	    //return input;
                    } else {
                		// если база не содержит данных, выбрасываем исключение
                        stringstream string_error;
                		string_error << "Wrong format: " + data_str;
                	    throw invalid_argument(string_error.str());   // ловит исключение
                	}

            	} else {
            		// если база не содержит данных, выбрасываем исключение
            		stringstream string_error;
            		string_error << "Wrong format: " + data_str;
            	    throw invalid_argument(string_error.str());   // ловит исключение
            	}
            }
    }

private:
    Train train;
    map <string, set<string>> trains;
};

int main() {
  Database db;
  string command;
  int operation = INT_MAX;
  char c[1];
  try {
      system("clear");
      cout<<"Информационная система по продаже билетов на железнодорожном вокзале\n\n";
      cout<<"Меню:\n"<<"0. Выход\n"<<"1. Узнать список рейсов\n"<<"2. Забронировать билет\n"<<"3. Купить билет\n"<<"4. Вернуть билет\n"<<"5. Узнать свободные места\n\n";
      cout<<"Необходимо (введите номер пункта меню): ";
      cin>>operation;
      cout<<endl<<endl;
      if ((operation < 0) || (operation > 5)){
          throw invalid_argument("Неизвестный номер операции");
      }
      switch (operation) {
          case 0: return 0;
          case 1:
            db.GetTrainList("database.txt", 0);
            cout<<endl<<"Нажмите Enter для перехода в меню."<<endl;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin.getline(c, 1);
            main();
            break;
          case 2:
            db.BookTicket("database.txt", 0);
            cout<<endl<<"Нажмите Enter для перехода в меню."<<endl;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin.getline(c, 1);
            main();
            break;
          case 3:
            db.BookTicket("database.txt", 1);
            cout<<endl<<"Нажмите Enter для перехода в меню."<<endl;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin.getline(c, 1);
            main();
            break;
          case 4:
            db.BookTicket("database.txt", 2);
            cout<<endl<<"Нажмите Enter для перехода в меню."<<endl;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin.getline(c, 1);
            main();
            break;
          case 5:
            db.GetTrainList("database.txt", 1);
            cout<<endl<<"Нажмите Enter для перехода в меню."<<endl;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin.getline(c, 1);
            main();
            break;
      }
	}
	catch (exception& ex) {
		cout <<"\033[1;5;31m"<< ex.what()<<"\033[0m\n"<<endl;
        sleep(4);
        system("clear");
        main();
	}
  return 0;
}
