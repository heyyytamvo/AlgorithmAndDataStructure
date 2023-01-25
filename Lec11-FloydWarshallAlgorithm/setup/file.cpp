#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define INF 1000000

vector< vector<int> > graph;
vector< vector<int> > dist;
vector< vector<int> > path;

int V;

void printPath(vector< vector<int> > &path, int start, int end){
    if (start == end){
        cout << ' ' << end;
        return;
    }

    if (path[start][end] == -1){
        cout << "No path" << endl;
        return;
    }

    printPath(path, start, path[start][end]);
    cout << ' ' << end;
}

void printSolution(vector< vector<int> > &path, int start, int end){
    cout << "The path is: ";
    printPath(path, start, end);
    cout << endl << "Total length is: " << dist[start][end] << endl;
    return;
}


bool FloydWarshall(vector< vector<int> > &graph, vector< vector<int> > &dist){
    for (int k = 0; k < V; k++){
        for (int i = 0; i < V; i++){
            dist[k][i] = graph[k][i];
            if (graph[k][i] != INF && (i != k)){
                path[k][i] = k;
            }else{
                path[k][i] = -1;
            }
        }
    }

    for (int k = 0; k < V; k++){
        for (int i = 0; i < V; i++){
            if (dist[i][k] == INF) continue;
            for (int j = 0; j < V; j++){
                if (dist[k][j] != INF && dist[i][j] > dist[i][k] + dist[k][j]){
                    dist[i][j] = dist[i][k] + dist[k][j];
                    path[i][j] = path[k][j];
                }
            }
        }
    }

    for (int i = 0; i < V; i++){
        if (dist[i][i] < 0){
            return false;
        }
    }
    return true;
}

int main(){
    cin >> V;
    graph = vector< vector<int> > (V, vector<int>(V));
    dist = vector< vector<int> > (V, vector<int>(V));
    path = vector< vector<int> > (V, vector<int>(V));

    for (int i = 0; i < V; i++){
        for (int j = 0; j < V; j++){
            int value;
            cin >> value;

            if (value == 0 && i != j){
                graph[i][j] = INF;
            }else{
                graph[i][j] = value;
            }
        }
    }

    bool DoesNotHaveNegativeCycle = FloydWarshall(graph, dist);
    if (DoesNotHaveNegativeCycle){
        printSolution(path, 0, 3);
    }else{
        cout << "None" << endl;
    }

    for (int i = 0; i < V; i++){
        for (int j = 0; j < V; j++){
            cout << path[i][j] << ' ';
        }

        cout << endl;
    }

    return 0;
}