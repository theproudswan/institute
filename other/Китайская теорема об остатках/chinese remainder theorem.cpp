#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n;
    cout<<"Введите количесвто уравнений: "; cin>>n;
    cout<<"Введите пары чисел вместо \"?\" в уравнениях, разделяя пробелами"<<endl;
    cout<<"x ≡ ? (mod ?)"<<endl<<endl;
    vector<int> a(n);
    vector<int> m(n);
    int M = 1;
    for(unsigned i = 0; i<n; ++i){
        cin>>a[i]>>m[i];
        M*=m[i];
    }
    //TODO
    // Проверка на взаимную простоту чисел в векторе m
    cout<<endl;
    cout<<"M = "<<M<<endl;
    for(unsigned i = 0; i<n; ++i){
        cout<<"M["<<i+1<<"] = "<<M/m[i]<<endl;
    }
    return 0;
}