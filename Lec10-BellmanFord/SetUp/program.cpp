#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <map>
#define MAX 10000000
#define INF 1e9

struct Edge
{
    int node1, node2, length;
    /* data */
};


using namespace std;
//vector< vector< pair<int, int> > > Graph;  //city + length
vector<int> Dist(MAX, INF);
vector<int> path(MAX, -1);
vector<Edge> Data;
int numberOfNodes, numberOfEdges;

void input(){
    //Graph = vector< vector< pair<int, int> > > (MAX, vector< pair<int, int> >());
    cin >> numberOfEdges;
    for (int i = 0; i < numberOfEdges; i++){
        int node1, node2, length;

        cin >> node1 >> node2 >> length;
        Data.push_back((Edge){node1, node2, length});
    }
}

bool BellmanFord(int vertex){
    Dist[vertex] = 0;

    for (int i = 0; i < numberOfEdges; i++){
        for (int j = 0; j < numberOfEdges; j++){
            int nodeA = Data[j].node1;
            int nodeB = Data[j].node2;
            int cost = Data[j].length;

            if (Dist[nodeA] != INF && Dist[nodeB] > Dist[nodeA] + cost){
                Dist[nodeB] = Dist[nodeA] + cost;
                path[nodeB] = nodeA;
            }
        }
    }

    for (int i = 0; i < numberOfEdges; i++){
        int u = Data[i].node1;
        int v = Data[i].node2;
        int w = Data[i].length;

        if (Dist[u] != INF && Dist[u] + w < Dist[v]){
            return false;
        } 
    }
    return true;
}

void printPath(int start, int end){
    vector<int> b;

    /* code */
    if (path[end] == -1){
        cout << "no path";
        return;
    }

    while (true)
    {
        //cout << end << endl;
        b.push_back(end);
        end = path[end];

        if (start == end){
            b.push_back(start);
            break;
        }
    }

    int count = b.size() - 1;
    while (count >= 0){
        cout << b[count] << " ";
        count--;
    }
    
}

int main(){
    input();
    bool hasNegativeWeight = BellmanFord(0);

    cout << "Cost is: " << Dist[4] << endl;
    cout << "Path is: " << endl;
    //cout << path[4];
    printPath(0, 4);

    return 0;
}