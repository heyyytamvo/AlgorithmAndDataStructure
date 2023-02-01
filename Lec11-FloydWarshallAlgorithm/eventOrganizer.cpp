#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <iomanip>
#define INF -99999999
#define MAX 49
using namespace std;

int grid[MAX][MAX];
int T, N;

void input(){
    for (int i = 0; i < MAX; i++){
        for (int j = 0; j < MAX; j++){
            grid[i][j] = 0;
        }
    }

    cin >> N;
    for (int i = 0; i < N; i++){
        int S, E, C;
        cin >> S >> E >> C;

        if (grid[S][E] != 0){
            grid[S][E] = max(grid[S][E], C);
        }else{
            grid[S][E] = C;
        }
    }
}

void FloydWarshall(){
    for (int k = 0; k < MAX; k++){
        for (int i = 0; i < MAX; i++){
            for (int j = 0; j < MAX; j++){
                if (i <= k && k <= j){
                    grid[i][j] = max(grid[i][j], grid[i][k] + grid[k][j]);
                }
            }
        }
    }
}



int main(){
    cin >> T;
    while (T > 0){
        input();
        FloydWarshall();
        int res = 0;
        for (int i = 0; i < MAX; i++){
            for (int j = 0; j < MAX; j++){
                res = max(res, grid[i][j]);
            }
        }

        cout << res << endl;
        T--;
    }

    return 0;
}