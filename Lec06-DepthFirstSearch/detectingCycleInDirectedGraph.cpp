#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <cstring>
using namespace std; 
#define MAX 100000


int numberOfNodes, numberOfEdges;
int hasCycle = 0;
vector< vector<int> > Graph;
int visited[MAX];
void initialize(){
    Graph = vector< vector<int> > (MAX, vector<int> ());
    memset(visited, false, sizeof(visited));

    cout << "Enter number of nodes: ";
    cin >> numberOfNodes;
    cout << endl << "Enter number of edges: ";
    cin >> numberOfEdges;

    for (int i = 0; i < numberOfEdges; i++){
        int node1, node2, length;
        cin >> node1 >> node2;
        Graph[node1].push_back(node2);
    }
}

void DFScycle(int start){

    vector<int> adjNode = Graph[start];
    visited[start] = true;

    for (int i = 0; i < adjNode.size(); i++){
        int nextNode = adjNode[i];

        if (visited[nextNode] == true){
            hasCycle = 1;
            return;
        }

        if (visited[nextNode] == false){
            DFScycle(nextNode);
        }
    }
    visited[start] = false;
}



int main(){
    initialize();
    for (int i = 0; i < numberOfNodes; i++){
        memset(visited, false, sizeof(visited));
        int currentNode = i;
        DFScycle(currentNode);
        if (hasCycle == 1){
            cout << "YES, It has cycle" << endl;
            break;
        }
    }

    if (hasCycle == 0){
        cout << "NO, It does not have cycle";
    }

    return 0;
}