#include <iostream>
#include <vector>
#include <string>
#define INF 999999999

using namespace std;

int testCaseOrder = 1;
int graph[21][21];
int X, N;

void initialze(){
    for (int i = 1; i < 21; i++){
        for (int j = 1; j < 21; j++){
            if (i == j){
                graph[i][j] = 0;
                continue;
            }
            graph[i][j] = INF;
        }
    }
}

void FloydWarshall(){
    for (int k = 1; k < 21; k++){
        for (int i = 1; i < 21; i++){
            for (int j = 1; j < 21; j++){
                graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
            }
        }
    }
}

string formatted(int n) {
    return (n >= 10 ? to_string(n) : " " + to_string(n));
}

void printAnswer(int start, int end){
    cout << formatted(start) << " to " << formatted(end) << ": " << graph[start][end] << endl; 
}

int main(){
    
    while (true){
        initialze();
        for (int i = 1; i < 20; i++){
            if (!(cin >> X)) {
                return 0;
            }

            for (int j = 1; j <= X; j++){
                int adjCountry;
                cin >> adjCountry;
                graph[i][adjCountry] = 1;
                graph[adjCountry][i] = 1;
            }
        }
        FloydWarshall();
        cin >> N;
        cout << "Test Set #" << testCaseOrder << endl;
        for (int i = 0; i < N; i++){
            int start, end;
            cin >> start >> end;
            printAnswer(start, end);
        }
        cout << endl;
        testCaseOrder++;
    }
    return 0;
}