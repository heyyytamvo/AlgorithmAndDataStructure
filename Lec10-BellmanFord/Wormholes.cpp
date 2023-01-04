#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <map>
#define MAX 10000000
#define INF 1e9


struct wormHole
{
    /* data */
    int star1, star2, year;
};

using namespace std;
int numberOfTestCase;
int numberOfPlanet, numberOfWormHoles;
vector<int> YearInPlanet;
vector<wormHole> Data;
void input(){
    Data.clear();
    cin >> numberOfPlanet >> numberOfWormHoles;
    YearInPlanet = vector<int> (MAX, INF);
    for (int i = 0; i < numberOfWormHoles; i++){
        int a, b, c;
        cin >> a >> b >> c;
        Data.push_back((wormHole){a, b, c});
    }
}

bool bellmanFord(){
    YearInPlanet[0] = 0;
    for (int i = 0; i < numberOfPlanet - 1; i++){
        for (int j = 0; j < numberOfWormHoles; j++){
            wormHole current = Data[j];
            int u = current.star1;
            int v = current.star2;
            int w = current.year;

            if (YearInPlanet[u] != INF && YearInPlanet[v] > YearInPlanet[u] + w ){
                YearInPlanet[v] = YearInPlanet[u] + w;
            }
        }
    }
    
    for (int i = 0; i < numberOfWormHoles; i++){
        wormHole current = Data[i];
        if (YearInPlanet[current.star1] != INF && YearInPlanet[current.star1] + current.year < YearInPlanet[current.star2]){
            return true;
        }
    }

    return false;
}


int main(){
    

    cin >> numberOfTestCase;
    while (numberOfTestCase > 0){
        input();    
        bool res = bellmanFord();
        if (res){
            cout << "possible" << endl;
        }else{
            cout << "not possible" << endl;
        }

        numberOfTestCase--;
    }
    
}


