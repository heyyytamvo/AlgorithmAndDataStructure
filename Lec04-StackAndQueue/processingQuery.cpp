#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;
#define MAX 101


int n, b;
long long clockTime = 0;
queue<long long> q;
queue< pair<int, int> > Data;




int main(){
    cin >> n >> b;
    q.push(0);
    for (int i = 1; i <= n; i++){
        long long t, d;
        cin >> t >> d;

        while (!q.empty() && q.front() <= t) {
            //cout << "queue front is: " << q.front() << endl;
            q.pop();
        }

        if (q.size() <= b){
            clockTime = max(clockTime, t) + d;
            cout << clockTime << " ";
            q.push(clockTime);
        }else{
            cout << -1 << " ";
        }
        
    }
    return 0;
}