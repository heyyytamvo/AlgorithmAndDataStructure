#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <map>
#include <cmath>
using namespace std;
#define MAX 101
#define INF 1e9

struct edge{
    int a, b, c;
};
int n, m, q, s;
vector<edge> listOfEdges;
vector<int> Dist;
vector<int> Dist0;
vector<int> listQueries;

void input(){
    listOfEdges.clear();
    Dist.clear();
    Dist0.clear();
    listQueries.clear();
    for (int i = 0; i < n; i++){
        Dist.push_back(INF);
        Dist0.push_back(-INF);
    }

    for (int i = 0; i < m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        listOfEdges.push_back((edge){a, b, c});
    }

    for (int i = 0; i < q; i++){
        int value;
        cin >> value;
        listQueries.push_back(value);
    }
}

void BellManFord(int start){
    Dist[start] = 0;

    for (int i = 1; i < n; i++){
        for (int j = 0; j < m; j++){
            edge currentEdge = listOfEdges[j];

            int u = currentEdge.a;
            int v = currentEdge.b;
            int w = currentEdge.c;

            if (Dist[u] != INF && Dist[u] + w < Dist[v]){
                Dist[v] = Dist[u] + w;
            }
        }
    }

    for (int i = 1; i < n; i++){
        for (int j = 0; j < m; j++){
            edge currentEdge = listOfEdges[j];

            int u = currentEdge.a;
            int v = currentEdge.b;
            int w = currentEdge.c;

            if (Dist[u] != INF && Dist[u] + w < Dist[v]){
                Dist[v] = -INF;
            }
        }
    }
}


int main(){
    while (cin >> n >> m >> q >> s && n != 0){
        input();
        BellManFord(s);
        for (int i = 0; i < q; i++){
            int currentDestination = listQueries[i];
            if (Dist[currentDestination] == INF){
                cout << "Impossible" << endl;
            }else if (Dist[currentDestination] == -INF){
                cout << "-Infinity" << endl;
            }else{
                cout << Dist[currentDestination] << endl;
            }
        }

        cout << endl;
    }
}