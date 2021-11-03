#include <iostream>
#include <cstring>

#define INF INT32_MAX
#define SIZE 10

using namespace std;

//#define V 5

struct Edge {
  int u;  // Начальная вершина ребра
  int v;  // Конечная вершина ребра
  int w;  // Вес ребра (u, v)
};

struct Graph{
    Graph(int _V, int _E, Edge* _edge) : V(_V), E(_E), edge(_edge) {}
    int V; // Количество вершин
    int E; // Количество рёбер
    Edge* edge; // Указатель на массив рёбер
};

Graph* CreateGraph(int V, int E){
    Graph* graph = new Graph(V, E, new Edge[E]);
    return graph;
}

void PrintArray(int* arr, int size){
    for (int i = 0; i < size; ++i){
        arr[i] == INF ? cout << "INF\t" : cout << arr[i] << '\t';
    }
    cout << endl;
}


void BellmanFord(Graph* graph, int src);

void Prim(int G[SIZE][SIZE], int V);



int main(){

  /* =============================================
  * А Л Г О Р И Т М   Б Е Л Л М А Н А - Ф О Р Д А
  =============================================== */
  cout << "Алгоритм Беллмана-Форда" << endl;
  // Создать граф
  int V = 10;  // Всего вершин
  int E = 14;  // Всего рёбер

  Graph* graph = CreateGraph(V, E);

  // Добавления вершин в граф
  /*
		Ребро представлено структурой ребра edge(u, v),
		где 	u = начальная вершина ребра edge (u,v)
				  v = конечная вершина ребра edge (u,v)
		      w = вес ребра edge (u,v)
	*/

  // Далее следует определение графа

  //edge 0 --> 1
  graph->edge[0].u = 0;
  graph->edge[0].v = 1;
  graph->edge[0].w = 1;

  //edge 0 --> 3
  graph->edge[1].u = 0;
  graph->edge[1].v = 3;
  graph->edge[1].w = 2;

  //edge 1 --> 3
  graph->edge[2].u = 1;
  graph->edge[2].v = 3;
  graph->edge[2].w = 3;

  //edge 3 --> 2
  graph->edge[3].u = 3;
  graph->edge[3].v = 2;
  graph->edge[3].w = 5;

  //edge 3 --> 4
  graph->edge[4].u = 3;
  graph->edge[4].v = 4;
  graph->edge[4].w = 7;

  //edge 4 --> 6
  graph->edge[5].u = 4;
  graph->edge[5].v = 6;
  graph->edge[5].w = -4;

  //edge 2 --> 6
  graph->edge[6].u = 2;
  graph->edge[6].v = 6;
  graph->edge[6].w = 4;
  
  //edge 6 --> 5
  graph->edge[7].u = 6;
  graph->edge[7].v = 5;
  graph->edge[7].w = 6;

  //edge 6 --> 7
  graph->edge[8].u = 6;
  graph->edge[8].v = 7;
  graph->edge[8].w = 8;

  //edge 5 --> 7
  graph->edge[9].u = 5;
  graph->edge[9].v = 7;
  graph->edge[9].w = 1;

  //edge 5 --> 8
  graph->edge[10].u = 5;
  graph->edge[10].v = 8;
  graph->edge[10].w = 9;

  //edge 7 --> 8
  graph->edge[11].u = 7;
  graph->edge[11].v = 8;
  graph->edge[11].w = -7;

  //edge 7 --> 9
  graph->edge[12].u = 7;
  graph->edge[12].v = 9;
  graph->edge[12].w = -5;

  //edge 8 --> 9
  graph->edge[13].u = 8;
  graph->edge[13].v = 9;
  graph->edge[13].w = -2;

  int edges = 0;


  BellmanFord(graph, 0);  // 0 - начальная вершина
  cout << endl << endl << endl;

   /* =============================================
  *           А Л Г О Р И Т М   П Р И М А
  =============================================== */
  cout << "Алгоритм Прима" << endl << endl;
    int G[SIZE][SIZE] = {
                    {0, 1, 0, 2, 0, 0, 0, 0, 0, 0},
                    {1, 0, 0, 3, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 5, 0, 0, 4, 0, 0, 0},
                    {2, 3, 5, 0, 7, 0, 0, 0, 0, 0},
                    {0, 0, 0, 7, 0, 0,-4, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 6, 1, 9, 0},
                    {0, 0, 4, 0,-4, 6, 0, 8, 0, 0},
                    {0, 0, 0, 0, 0, 1, 8, 0,-7,-5},
                    {0, 0, 0, 0, 0, 9, 0,-7, 0,-2},
                    {0, 0, 0, 0, 0, 0, 0,-5,-2, 0},
                }; // Матрица смежности для графа

    Prim(G, V);
    return 0;
}

  /* =============================================
  * А Л Г О Р И Т М   Б Е Л Л М А Н А - Ф О Р Д А
  =============================================== */
void BellmanFord(Graph* graph, int src){
    int V = graph->V;
    int E = graph->E;

    int p[V]; // Массив, в котором индекс будет соответствовать вершине, 
              // в которую можно попасть из вершины, которая соответствует значению индекса массива
    memset(p, -1, sizeof(p));

    // Шаг 1: Расстояние до всех вершин в графе равно бесконечности
    //        (а до начального равно 0)
    int dist[V];
    for (int i = 0; i < V; ++i){
      dist[i] = INF;
    }
    dist[src] = 0;

    // Шаг 2: Вызов процедуры Relax(u, v) |V| - 1 раз
    //        для каждого ребра (u, v) из E
    for (int i = 1; i <= V - 1; ++i){
        bool found = false;
        for (int j = 0; j < E; ++j){
            if (dist[graph->edge[j].u] + graph->edge[j].w < dist[graph->edge[j].v]){ // Если расстояние от начальной вершины + вес будет меньше конечной вершины
                dist[graph->edge[j].v] = dist[graph->edge[j].u] + graph->edge[j].w;  // Обновляем значение минимального расстояния до конечной вершины
                p[graph->edge[j].v] = graph->edge[j].u; // Запоминаем, из какой вершины мы пришли в вершину v
                found = true;
                PrintArray(dist, V);
            }
        }
        if (!found) break;
    }

    // Шаг 3: Проверить на наличие отрицательных циклов
    for (int i = 0; i < E; ++i){
        if (dist[graph->edge[i].u] + graph->edge[i].w < dist[graph->edge[i].v]){ // Если снова удалось уменьшить расстояние
            cerr << "Граф содержит циклы с отрицательным весом" << endl;
            return;
        }
    }

    cout << endl << endl;
    cout << "Расстояние от нуля до вершины: " << endl;
    for (int i = 0; i < V; ++i){
      cout << i << '\t';
    }
    cout << endl;
    PrintArray(dist, V);
    cout << endl << endl;

    for (int i = 0; i < V; ++i){
      if(p[i] == INF) {
        cout << "Из вершины " << src << " нет пути до вершины " << p[i] << endl;
      } else {
        int path[V]; // Массив, в который будут записываться пройденные вершины
        memset(path, -1, sizeof(path));
        int k = V - 1;
        for (int j = i; j != -1; j = p[j]){
          path[k] = j;
          --k;
        }
        cout << "Из вершины " << src << " до вершины " << i << " путь проходит через: ";
        for (int i = 0; i < V; ++i){
          if(path[i] != -1){
            cout << path[i] << ' ';
          }
        }
        cout << endl;
      }
    }


    return;
}


   /* =============================================
  *           А Л Г О Р И Т М   П Р И М А
  =============================================== */

void Prim(int G[SIZE][SIZE], int V){
  // Создаём массив, чтобы отслеживать пройденныевершины
  // Выбранные - истина, иначе - ложь
  bool selected[V]; 

  memset(selected, false, sizeof(selected));

  // Количество рёбер
  int no_edge = 0;

  // Вершина, из которой начинаем обход
  selected[0] = true;

  int x;  // Строки (начальная вершина)
  int y;  // Столбцы (конечная вершина)

  cout << "Edge"
     << "  : "
     << "Weight";
  cout << endl;

  while (no_edge < V - 1) {
    // Для каждой вершины найти все смежные вершины,
    // вычислить расстояние от вершины, выбранной на шаге 1.
    // Если вершина уже обработана, отбросить ее, в противном случае
    // выбирать другую вершину, ближайшую к выбранной вершине на шаге 1

    int min = INF;
    x = 0;
    y = 0;

    for (int i = 0; i < V; i++) {
      if (selected[i]) {
        for (int j = 0; j < V; j++) { // Для каждой вершины перебираем другие
          if (!selected[j] && G[i][j]) {  // Не была выбрана раньше и вершины i и j соединены
            if (min > G[i][j]) {
              min = G[i][j]; // Запоминаем новый минимальный вес 
              x = i; // Запомнили начальную вершину
              y = j; // Запомнили конечную вершину
            }
          }
        }
      }
    }
    cout << x << " - " << y << " :  " << G[x][y];
    cout << endl;
    selected[y] = true; // Вершину, в которую пришли помечаем пройденной
    no_edge++;
  }
}