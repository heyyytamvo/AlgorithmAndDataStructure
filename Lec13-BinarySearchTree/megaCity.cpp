#include <iostream>
#include <cmath>
#include <iomanip>
#include <map>

using namespace std;

map<int, int> graph;  //radius + population
int n, s;

bool alreadyExist(int radius){
    if (graph.find(radius) == graph.end()){
        return false;
    }
    return true;
}

int main(){
    cin >> n >> s;
    for (int i = 0; i < n; i++){
        int x, y, k;
        cin >> x >> y >> k;

        int rad = x*x + y*y;
        if (alreadyExist(rad)){
            graph[rad] += k;
        }else{
            graph.insert(pair<int, int>(rad, k));
        }
    }

    /*
    for (auto ele : graph){
        cout << ele.first << endl;
    }*/
    int res = -1;
    for (auto element : graph){
        s += element.second;

        if (s >= 1000000){
            res = element.first;
            break;
        }
    }

    if (res != -1){
        double result = sqrt(double(res));
        cout << setprecision(7) << result;
    }else{
        cout << res;
    }


    return 0;
}