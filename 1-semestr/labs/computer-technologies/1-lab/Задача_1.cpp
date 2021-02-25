#include <iostream>

using namespace std;

int main(){

  float A, B, DEL, a,b,c,x, F; // Инициализируем входные данные

  cout<<"Начало интервала: ";
  cin>>A;
  cout<<"Конец интервала: ";
  cin>>B;
  cout<<"Шаг: ";
  cin>>DEL;
  cout<<endl;

  cout<<"Коэф а: ";
  cin>>a;
  cout<<"Коэф b: ";
  cin>>b;
  cout<<"Коэф c: ";
  cin>>c;

  cout<<endl<<endl<<"Цикл for: "<<endl;

  for (x=A; x<=B; x+=DEL){ // Решение задачи циклом for
    if ((x+c<0)&&(a!=0)){ // В случае, если соблюдается условие, считаем F1
      F=-a*x*x*x - b;
      cout<< "F1: "<<F<<endl;
    } else {

        if ((x+c>0)&&(a==0)){
          if(x-c != 0){ // В случае, если соблюдается условие, считаем F2
            F=(x-a)/(x-c);
            cout<< "F2: "<<F<<endl;
          } else {
            cout<<"Ошибка! Деление на ноль."<<endl;
          }
        } else { // Если предыдущие условия не прошли, считаем F3
          F = x*c + x*b;
          cout<< "F3: "<<F<<endl;
        }

    }
  }


  cout<<endl<<endl<<"Цикл while: "<<endl;

  x=A; // Возвращаемся в исходную позицию

  while (x<=B) { //Решение задачи циклом while() с предусловием
    if ((x+c<0)&&(a!=0)){
      F=-a*x*x*x - b;
      cout<< "F1: "<<F<<endl;
    } else {

        if ((x+c>0)&&(a==0)){
          if(x-c != 0){
            F=(x-a)/(x-c);
            cout<< "F2: "<<F<<endl;
          } else {
            cout<<"Ошибка! Деление на ноль."<<endl;
          }
        } else {
          F = x*c + x*b;
          cout<< "F3: "<<F<<endl;
        }

    }

    x+=DEL;
  }

  cout<<endl<<endl<<"Цикл do while: "<<endl;

  x=A;// Возвращаемся в исходную позицию

  do { //Решение конструкцией do while
    if ((x+c<0)&&(a!=0)){
      F=-a*x*x*x - b;
      cout<< "F1: "<<F<<endl;
    } else {

        if ((x+c>0)&&(a==0)){
          if(x-c != 0){
            F=(x-a)/(x-c);
            cout<< "F2: "<<F<<endl;
          } else {
            cout<<"Ошибка! Деление на ноль."<<endl;
          }
        } else {
          F = x*c + x*b;
          cout<< "F3: "<<F<<endl;
        }

    }
    x+=DEL;
  } while(x<=B);

cout<<endl<<endl;

return 0;
}
