#include <iostream>
#include <fstream>
#include <iomanip>
#include <ctime>

#define N 15

using namespace std;

bool FillArray(int temp[N][4], int new_numb){
    for (int i = 0; i < N; ++i){
        if(temp[i][0]==new_numb){
            return 0;
        }
    }
    return 1;
}

int main(){
    srand(time(NULL));
    ofstream output("database.txt");
    if(!output){
        cout<<"\nFile not found\n";
        return 0;
    }
    output<<"Номер рейса / Забронировано билетов / Куплено билетов / Всего билетов"<<endl;
    int temp[N][4];
    int buf = 0;
    for (int i = 0; i < N; ++i){
    repeat:
        buf = (rand()%98) + 1;
        if (buf<10){
            goto repeat;
        }
        if(FillArray(temp, buf)){
            temp[i][0]=buf;
        } else{
            goto repeat;
        }
        temp[i][1] = rand()%100;
        temp[i][2] = rand()%100;
        temp[i][3] = temp[i][1]+temp[i][2]+rand()%50;
        output<<setw(2)<<to_string(temp[i][0])<< "                 " << setw(3)<<to_string(temp[i][1]) << "                 " << setw(3)<<to_string(temp[i][2])<<"                 "<< setw(3)<<to_string(temp[i][3])<<endl;
    }
    output.close();
    return 0;
}
