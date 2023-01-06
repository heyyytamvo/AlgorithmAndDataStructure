#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <map>
#include <cmath>
using namespace std;
#define MAX 101
#define INF 1e9


int n;
int energy, numberOfDoors;
vector< pair<int, int> > listOfEdges;
vector<int> EnergyList;
vector<int> Cost = vector<int> (MAX, INF);


void input(){
    for (int i = 0; i < MAX; i++){
        Cost[i] = -INF;
    }
    EnergyList.clear();
    EnergyList.push_back(-1); //index 0
    listOfEdges.clear();
    for (int i = 1; i <= n; i++){
        cin >> energy >> numberOfDoors;
        for (int j = 0; j < numberOfDoors; j++){
            int gate;
            cin >> gate;
            listOfEdges.push_back(make_pair(i, gate));
        }
        EnergyList.push_back(energy);
    }
}

bool hasPathBFS(int start, int end){
    vector<bool> visited(MAX, false);
    visited[start] = true;
    queue<int> q;
    q.push(start);

    while (!q.empty()){
        int current = q.front();
        q.pop();

        for (int i = 0; i < listOfEdges.size(); i++){
            pair<int, int> currentEdge = listOfEdges[i];
            int u = currentEdge.first;
            int v = currentEdge.second;
            int w = EnergyList[v];

            if (u == current){
                if (visited[v] == false){
                    visited[v] = true;
                    q.push(v);

                    if (v == end){
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

bool bellmanFord(int start, int end){
    Cost[start] = 100;

    for (int i = 1; i < n; i++){
        for (int j = 0; j < listOfEdges.size(); j++){
            pair<int, int> currentEdge = listOfEdges[j];

            int u = currentEdge.first;
            int v = currentEdge.second;
            int w = EnergyList[v];

            if (Cost[u] > 0 && Cost[u] + w > Cost[v]){
                Cost[v] = Cost[u] + w;
            }
        }
    }

    for (int i = 0; i < listOfEdges.size(); i++){
        pair<int, int> currentEdge = listOfEdges[i];
        int u = currentEdge.first;
        int v = currentEdge.second;
        int w = EnergyList[v];
        if (Cost[u] > 0 && Cost[u] + w > Cost[v] && hasPathBFS(u, end)){
            return true;
        } 

    }


    return Cost[n] > 0;
    
}


int main(){
    cin >> n;

    while (n != -1){
        input();
        int res = bellmanFord(1, n);
        if (res){
            cout << "winnable" << endl;
        }else{
            cout << "hopeless" << endl;
        }
        cin >> n;
    }

    return 0;
    
}

