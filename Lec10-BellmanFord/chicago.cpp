#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <map>
#include <cmath>
using namespace std;
#define MAX 101
#define INF 1e9


struct edge
{
    /* data */
    int A, B;
    double C;
};

int n, m;
vector<edge> Data;

void input(){
    Data.clear();
    for (int i = 0; i < m; i++){
        int a, b;
        double p;
        cin >> a >> b >> p;
        Data.push_back((edge){a, b, p*0.01});
        Data.push_back((edge){b, a, p*0.01});
    }
}

double BellManFord(int start, int end){
    vector<double> Prob(MAX, -INF);
    Prob[1] = 1;

    for (int i = 0; i < n - 1; i++){
        for (int j = 0; j < 2*m; j++){
            edge current = Data[j];
            int u = current.A;
            int v = current.B;
            double w = current.C;

            if (Prob[u] != -INF && Prob[u] * w > Prob[v]){
                Prob[v] = Prob[u] * w;
                //cout << "v is " << v << " " << Prob[v] << endl;
            } 
        }
    }

    return Prob[end] * 100;

}

int main(){
    while (cin >> n && n != 0){
        cin >> m;
        input();
        double result = BellManFord(1, n);
        cout.precision(6);
        cout << fixed << result;
        cout << " percent" << endl;
    }

    return 0;
}