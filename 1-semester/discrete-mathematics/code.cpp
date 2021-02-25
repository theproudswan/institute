#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <climits>

#define SIZE 9

using namespace std;

int main()
{
    vector<int> parent(SIZE,-1);    // объявили и сразу заполнили -1-цами в кол-ве 5 штук
    int big_num(10000);
    int cost[SIZE][SIZE] = {
                        {0, 3, 0, 0, 0, 0, 0, 0, 0},
                        {3, 0, 4, 0, 0, 2, 0, 0, 0},
                        {0, 4, 0, 8, 1, 0, 0, 0, 0},
                        {0, 0, 8, 0, 0, 16, 7, 0, 22},
                        {0, 0, 1, 0, 0, 2, 32, 40, 0},
                        {0, 2, 0, 16, 2, 0, 0, 0, 0},
                        {0, 0, 0, 7, 32, 0, 0, 9, 1},
                        {0, 0, 0, 0, 40, 0, 9, 0, 5},
                        {0, 0, 0, 22, 0, 0, 1, 5, 0}
                       };

    int pos[SIZE],node[SIZE],min(0),index_min(0);
    for(int i = 0;i<SIZE;++i){
        pos[i] = big_num;
        node[i] = 0;
    }
    for(int i = 0;i<SIZE;++i){
        for(int j = 0;j<SIZE;++j){
            cout << setw(4) << cost[i][j];
        }
        cout << "\n";
    }
    pos[0] = 0;            // наш узел
    cout << "\n";
    for(int i = 0;i<SIZE-1;++i){
        min = big_num;
        for(int j = 0;j<SIZE;++j){
            if(!node[j] && pos[j] < min){
                min = pos[j];
                index_min = j;
            }
        }
        node[index_min] = true;
        for(int j = 0;j<SIZE;++j){
            if(!node[j] && cost[index_min][j] > 0 && pos[index_min] != big_num && pos[index_min] + cost[index_min][j] < pos[j]){
                pos[j] = pos[index_min] + cost[index_min][j];
                parent.at(j) = index_min;    // запоминаем предка вершины j
            }
        }
    }
    int n(0);
    cout << "\nВ какую вершину нужно попасть: ";
    cin >> n;

    vector<int>temp;     // n - 1, так как не забываем про индексацию
    for(int i = n-1;i != -1;i = parent.at(i))
        temp.push_back(i+1);
    reverse(temp.begin(),temp.end());
    cout<<"Вершины, через которые нужно пройти:\n";
    for(int i = 0;i<temp.size();++i)
        cout << temp.at(i) << endl;

    cout << "\n\nДлина пути: " << pos[n-1] << "\n";
    ///////////////////////////////////////////////////////
    min = INT_MAX;
    int max = INT_MIN;
    int m[SIZE];
    for (int i=0;i<SIZE;i++) // Max in string AND print cost
    {
      m[i]=cost[i][0];
      for (int j=0;j<SIZE; j++)
       {
         if(cost[i][j]>m[i])
            m[i]=cost[i][j];
       }
    }
    for (int i=0;i<SIZE;i++)
    {
       if (min>m[i]) min=m[i];
       if (max<m[i]) max=m[i];
    }
    printf("\n\nРадиус графа: %i",min);
    printf("\nДиаметр графа: %i",max);

    printf("\n\nЦентральные вершины:\n");
    for (int i=0;i<SIZE;i++)
      if (m[i]==min) printf("Вершина №%i \nРадиус графа: %i\n",i+1,m[i]);
    cout << endl;


///////////////////////////////////////////////////////////
int a,b,u,v,i,j,ne=1;
int visited[SIZE]={0},mincost=0;
min = INT_MAX;
n = SIZE;
int path[100]={0}; //В этот массив будут записываться вершины, по которым составиться путь
int path_index=0;
for(i=0;i<n;i++)
    for(j=0;j<n;j++)
    {
        if(cost[i][j]==0)
            cost[i][j]=INT_MAX; //MAX_INT - это что-типа бесконечности. Должно быть больше чем значения веса каждого из ребер в графе
    }
visited[1]=1; // visited[1]=1
cout<<"\n";
cout<<"    "<<'a'<<' '<<"b   "<<"min";
while(ne < n)
{
    for(i=0,min=INT_MAX;i<n;i++)
        for(j=0;j<n;j++)
            if(cost[i][j]< min)
                if(visited[i]!=0)
                {
                    min=cost[i][j];
                    a=u=i;
                    b=v=j;
                }
    if(visited[u]==0 || visited[v]==0)
    {
    path[path_index]=b;
    path_index++;
    cout<<"\n "<<ne++<<": "<<a+1<<" "<<b+1<<"    "<<min; //Можно вывести так
    //ne++; //если строчку выше раскомментировать - эту закомментировать
    mincost+=min;
    visited[b]=1;

    }
    cost[a][b]=cost[b][a]=INT_MAX;
}

cout<<"\n Минимальная стоимость остовного дерева: "<<mincost<<endl;

    return 0;
}
