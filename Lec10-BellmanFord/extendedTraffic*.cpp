#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <map>
#include <cmath>

#define MAX 1000
#define INF 1e9

using namespace std;

struct edge{
    int node1, node2, length;
};

int numberOfTestCase;
int numberOfQueries, numberOfJunctions, numberOfRoads;
vector<int> Busy;
vector<int> Cost;
vector<edge> Roads;
vector<int> CostResult;
vector<int> queries;
bool hasNegativeCycle;


void input(){
    Cost = vector<int> (MAX, INF);
    Busy = vector<int> (MAX, -1); 
    //CostResult = vector<int> (MAX, INF);
    Roads.clear();
    queries.clear();
    hasNegativeCycle = false;

    cin >> numberOfJunctions;
    for (int i = 1; i <= numberOfJunctions; i++){
        int busyness;
        cin >> busyness;
        Busy[i] = busyness;
    }

    cin >> numberOfRoads;
    for (int i = 0; i < numberOfRoads; i++){
        int junctionA, junctionB;
        cin >> junctionA >> junctionB;
        Roads.push_back((edge){junctionA, junctionB, pow((Busy[junctionB] - Busy[junctionA]), 3)});
    }

    cin >> numberOfQueries;
    for (int i = 0; i < numberOfQueries; i++){
        int destination;
        cin >> destination;
        queries.push_back(destination);
    }
}


void BellManFord(){
    Cost[1] = 0;
    //CostResult[1] = 0;
    for (int i = 1; i <= numberOfJunctions - 1;i++){
        for (int j = 0; j < numberOfRoads; j++){
            edge current = Roads[j];
            int u = current.node1;
            int v = current.node2;
            int cost = current.length;
            /*
            cout << "u is " << u << endl;
            cout << "v is " << v << endl;
            cout << "cost is " << cost << endl;
            cout << "cost of u is " << Cost[u] << endl;
            cout << "cost of v is " << Cost[v] << endl;
            */

            if (Cost[u] != INF && cost + Cost[u] < Cost[v]){
                //CostResult[v] = cost + CostResult[u];
                Cost[v] = cost + Cost[u];
                //cout << "Now cost of v is: " << Cost[v] << endl;
            }
        }
    }

    for (int i = 0; i < numberOfRoads; i++){
        edge current = Roads[i];
        int u = Roads[i].node1;
        int v = Roads[i].node2;
        int w = Roads[i].length;

        if (Cost[u] != INF && Cost[v] > Cost[u] + w){
            hasNegativeCycle = true;
        }
    }
}



int main(){
    cin >> numberOfTestCase;
    int index = 1;
    while (numberOfTestCase > 0){
        input();
        BellManFord();
        cout << "Case " << index << ":" << endl;

        /*
        for (int i = 0; i < numberOfRoads; i++){
            cout << Roads[i].length << endl;
        }*/
        for (int i = 0; i < numberOfQueries; i++){
            int nextDestination = queries[i];
            //cout << CostResult[nextDestination] << endl;
            if (Cost[nextDestination] < 3 || Cost[nextDestination] == INF || hasNegativeCycle){
                cout << "?" << endl;
            }else{
                cout << Cost[nextDestination] << endl;
            }
            
        }

        index++;
        numberOfTestCase--;
    }

    return 0;
}