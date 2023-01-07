#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <map>
#include <cmath>
using namespace std;
#define MAX 101
#define INF 1e9


struct trade{
    int item1, item2, cost;
};
int numberOfTestCase;
int N, M;
vector<int> Dist;
vector<trade> dataList;


bool BellManFord(int s){
    Dist[s] = 0;

    for (int i = 1; i < N; i++){
        for (int j = 0; j < M; j++){
            trade current = dataList[j];
            int u = current.item1;
            int v = current.item2;
            int w = current.cost;

            if (Dist[u] != -INF && Dist[u] + w > Dist[v]){
                Dist[v] = Dist[u] + w;
            }
        }
    }

    for (int i = 1; i < N; i++){
        for (int j = 0; j < M; j++){
            trade current = dataList[j];
            int u = current.item1;
            int v = current.item2;
            int w = current.cost;

            if (Dist[u] != -INF && Dist[u] + w > Dist[v]){
                //cout << "u is " << u << endl;
                //cout << "v is " << v << endl;
                //cout << "w is " << w << endl;
                //cout << "Dist[u] is " << Dist[u] << endl;
                //cout << "Dist[v] is " << Dist[v] << endl;
                return true;
            }
        }
    }

    if (N == 1 && M == 1 && dataList[0].cost > 0){
        return true;
    }
    if (N == 1 && M == 1 && dataList[0].cost < 0){
        return false;
    }
    

    return false;
}

void input(){
    Dist.clear();
    dataList.clear();
    cin >> N >> M;

    for (int i = 0; i <= N; i++){
        Dist.push_back(-INF);
    }
    for (int i = 0; i < M; i++){
        int a, b, c;
        cin >> a >> b >> c;
        dataList.push_back((trade){a, b, c});
    }
}



int main(){
    cin >> numberOfTestCase;

    while (numberOfTestCase > 0){
        input();
        bool result = BellManFord(1);
        if (result){
            cout << "Yes" << endl;
        }else{
            cout << "No" << endl;
        }
        numberOfTestCase--;
    }


    return 0;
}