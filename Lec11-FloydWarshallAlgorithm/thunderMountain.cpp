#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <iomanip>
#define INF 99999
#define MAX 102
using namespace std;
double grid[MAX][MAX];
int numberOfTestCase;
int testCaseOrder = 1;
int numberOfTown;
int a = numberOfTestCase;
vector< pair<int, int> > townLists;     //(x, y) is a pair

double distanceBetween(pair<int, int> A, pair<int, int> B){
    double distance;
    distance = sqrt(pow(A.first - B.first, 2) + pow(A.second - B.second, 2));
    return distance;
}


void FloydWarshall(){
    for (int k = 0; k < numberOfTown; k++){
        for (int i = 0; i < numberOfTown; i++){
            for (int j = 0; j < numberOfTown; j++){
                grid[i][j] = min(grid[i][j], grid[i][k] + grid[k][j]);
            }
        }
    }
}


void input(){
    townLists.clear();
    for (int i = 0; i < MAX; i++){
        for (int j = 0; j < MAX; j++){
            if (i == j){
                grid[i][j] = 0;
                continue;
            }
            grid[i][j] = INF;
        }
    }

    cin >> numberOfTown;

    for (int i = 0; i < numberOfTown; i++){
        int x, y;
        cin >> x >> y;
        townLists.push_back(make_pair(x, y));
    }

    for (int i = 0; i < numberOfTown; i++){
        pair<int, int> currentTown = townLists[i];
        for (int j = i + 1; j < numberOfTown; j++){
            pair<int, int> checkingTown = townLists[j];
            double distFromItoJ = distanceBetween(currentTown, checkingTown);
            if (distFromItoJ > 10){
                continue;
            }else{
                grid[i][j] = distFromItoJ;
                grid[j][i] = distFromItoJ;
            }
        }
    }
}




int main(){
    cin >> numberOfTestCase;
    while (numberOfTestCase > 0){
        input();
        FloydWarshall();
        double res = 0;
        for (int i = 0; i < numberOfTown; i++){ 
            for (int j = 0; j < numberOfTown; j++){
                res = max(res, grid[i][j]);
            }           
        }
        cout << "Case #" << testCaseOrder << ":" << endl;
        if (res != INF){
            cout << fixed << setprecision(4) << res << endl;
        }else{
            cout << "Send Kurdy" << endl;
        }

        cout << endl;

        numberOfTestCase--;
        testCaseOrder++;
    }

    return 0;
}
