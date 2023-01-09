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
int adjMatrix[MAX][MAX];
vector<int> TimeFrom1 = vector<int> (MAX, INF);
vector<int> TimeFromN = vector<int> (MAX, INF);

bool isNumber(const string& s)
{
    for (char const &ch : s) {
        if (isdigit(ch) == 0)
            return false;
    }
    return true;
}

void DijkstraFrom1(){
    TimeFrom1[1] = 0;
    queue<int> q;
    q.push(1);

    while (!q.empty()){
        int current = q.front();
        q.pop();
        //cout << "Checking from current " << current << endl;

        for (int i = 1; i <= n; i++){
            int checking = adjMatrix[current][i];

            if (checking != 0 && checking != -1){
                if (TimeFrom1[current] != INF && TimeFrom1[current] + checking < TimeFrom1[i]){
                    //cout << "Changing time, From " << current << " to " << i << ": " << TimeFrom1[i] << " -> ";
                    TimeFrom1[i] = TimeFrom1[current] + checking;
                    //cout << TimeFrom1[i] << endl;
                    q.push(i);
                }
            }
        }
    }
}

void DijkstraFromN(int end){
    TimeFromN[end] = 0;
    queue<int> q;
    q.push(end);

    while (!q.empty()){
        int current = q.front();
        q.pop();

        for (int i = 1; i <= n; i++){
            int checking = adjMatrix[current][i];

            if (checking != 0 && checking != -1){
                if (TimeFromN[current] != INF && TimeFromN[current] + checking < TimeFromN[i]){
                    TimeFromN[i] = TimeFromN[current] + checking;
                    q.push(i);
                }
            }
        }
    }
}

void input(){
    memset(adjMatrix, 0, sizeof(adjMatrix));
    cin >> n;
    for (int i = 2; i <= n; i++){
        for (int j = 1; j < i; j++){
            string value;
            cin >> value;
            if (isNumber(value)){
                int num;
                num = stoi(value);
                adjMatrix[i][j] = num;
                adjMatrix[j][i] = num;
            }else{
                adjMatrix[i][j] = -1;
                adjMatrix[j][i] = -1;
            }
        }
    }
}

int main(){

    input();
    DijkstraFrom1();
    //DijkstraFromN(4);

    int result = 0;

    for (int i = 1; i <= n; i++){
        result = max(result, TimeFrom1[i]);
    }
    
    cout << result << endl;

    //cout << TimeFrom1[5] << endl;

    return 0;
}