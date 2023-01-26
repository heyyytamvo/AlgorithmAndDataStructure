#include <iostream>
#include <vector>
#include <algorithm>
#define INF 9999999
#define MAXCITIES 91
using namespace std;


int numberOfRoads;
char cityMe, cityProf;
vector< vector<int> > graphForY = vector< vector<int> > (MAXCITIES, vector<int>(MAXCITIES));
vector< vector<int> > graphForM = vector< vector<int> > (MAXCITIES, vector<int>(MAXCITIES));
struct Place {
    int cost, id;

    bool operator<(const Place &other) const {
        return cost < other.cost || (cost == other.cost && id < other.id);
    }
};
vector<Place> Result;

void reset(){
    Result.clear();
    for (int i = 65; i <= 90; i++){
        for (int j = 65; j <= 90; j++){
            if (i == j){
                graphForM[i][j] = 0;
                graphForY[i][j] = 0;
                continue;
            }
            graphForM[i][j] = INF;
            graphForY[i][j] = INF;
        }
    }
}

void input(){
    for (int i = 0; i < numberOfRoads; i++){
        char streetType, direction, city1Input, city2Input;
        int city1, city2, length;
        cin >> streetType >> direction >> city1Input >> city2Input >> length;

        city1 = city1Input;
        city2 = city2Input;
        if (streetType == 'Y'){
            graphForY[city1][city2] = min(length, graphForY[city1][city2]);

            if (direction == 'B'){
                graphForY[city2][city1] = min(length, graphForY[city2][city1]);
            }
        }else{
            graphForM[city1][city2] = min(length, graphForM[city1][city2]);

            if (direction == 'B'){
                graphForM[city2][city1] = min(length, graphForM[city2][city1]);
            }
        }
    }

    cin >> cityMe >> cityProf;
}

void FloydWwarshall(vector< vector<int> > &graph){
    for (int k = 65; k < MAXCITIES; k++){
        for (int i = 65; i < MAXCITIES; i++){
            for (int j = 65; j < MAXCITIES; j++){
                graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
            }
        }
    }
}

int main(){
    while (cin >> numberOfRoads && numberOfRoads != 0){
        reset();
        input();
        FloydWwarshall(graphForY);
        FloydWwarshall(graphForM);
        
        int distance = INF;
        int cityMeEncode, cityProfEncode;
        cityMeEncode = cityMe;
        cityProfEncode = cityProf;
        for (int i = 65; i < 91; i++){
            //cout << temp << endl;
            if (graphForY[cityMeEncode][i] != INF && graphForM[cityProfEncode][i] != INF && graphForM[cityProfEncode][i] + graphForY[cityMeEncode][i] <= distance){
                Result.push_back(Place{graphForM[cityProfEncode][i] + graphForY[cityMeEncode][i], i});
                distance = graphForM[cityProfEncode][i] + graphForY[cityMeEncode][i];
            }
        }

        if(Result.empty()){
            cout << "You will never meet." << endl;
        }
        else{
            sort(Result.begin(), Result.end());
            cout << distance << ' ';

            for (Place &place : Result) {
                if (place.cost != distance){
                    break;
                }
                cout << char(place.id);
            }
            cout << endl;
        }

        /*
        for (int i = 65; i < 91; i++){
            for (int j = 65; j < 91; j++){
                if (graphForY[i][j] == INF){
                    cout << -1 << ' ';
                    continue;
                }
                cout << graphForY[i][j] << ' ';
            }
            cout << endl;
        }

        cout << "----------" << endl;

        for (int i = 65; i < 91; i++){
            for (int j = 65; j < 91; j++){
                if (graphForM[i][j] == INF){
                    cout << -1 << ' ';
                    continue;
                }
                cout << graphForM[i][j] << ' ';
            }
            cout << endl;
        }*/
    }

    return 0;
}
