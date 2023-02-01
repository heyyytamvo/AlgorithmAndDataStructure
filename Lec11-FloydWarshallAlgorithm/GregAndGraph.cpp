#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <iomanip>
#define INF 99999999
#define MAX 501
using namespace std;

int grid[MAX][MAX];
int copyOfGrid[MAX][MAX];
int numberOfVertices;

void input(){
    cin >> numberOfVertices;

    for (int i = 1; i <= numberOfVertices; i++){
        for (int j = 1; j <= numberOfVertices; j++){
            int value;
            cin >> value;
            grid[i][j] = value;
        }
    }



}

void FloydWarshall(){
    for (int i = 1; i <= numberOfVertices; i++){
        for (int j = 1; j <= numberOfVertices; j++){
            copyOfGrid[i][j] = grid[i][j];
        }
    }

    for (int k = 1; k <= numberOfVertices; k++){
        for (int i = 1; i <= numberOfVertices; i++){
            for (int j = 1; j <= numberOfVertices; j++){
                copyOfGrid[i][j] = min(copyOfGrid[i][j], copyOfGrid[i][k] + copyOfGrid[k][j]);
            }
        }
    }
}

int main(){
    input();


    for (int i = 0; i < numberOfVertices; i++){
        FloydWarshall();
        int minRes = 0;
        for (int i = 1; i <= numberOfVertices; i++){
            for (int j = 1; j <= numberOfVertices; j++){
                if (copyOfGrid[i][j] == INF){
                    continue;
                }
                minRes += copyOfGrid[i][j];
            }
        }
        int deletedVertex;
        cin >> deletedVertex;

        for (int i = 1; i <= numberOfVertices; i++){
            for (int j = 1; j <= numberOfVertices; j++){
                if (i == j){
                    continue;
                }

                if (i == deletedVertex || j == deletedVertex){
                    grid[i][j] = INF;
                }
            }
        }
        cout << minRes << " ";
    }

    return 0;
}