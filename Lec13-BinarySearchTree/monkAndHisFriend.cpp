#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <queue>

using namespace std;

int n, m;
int numberOfTestCase;
set<long long> classroom;

bool exist(long long candy){
    if (classroom.find(candy) == classroom.end()){
        return false;
    }
    return true;
}

int main(){
    cin >> numberOfTestCase;
    while (numberOfTestCase > 0){
        classroom.clear();
        cin >> n >> m;
        for (int i = 0; i < n; i++){
            long long value;
            cin >> value;
            classroom.insert(value);
        }

        for (int i = 0; i < m; i++){
            long long value;
            cin >> value;
            if (exist(value)){
                cout << "YES" << endl;
            }else{
                classroom.insert(value);
                cout << "NO" << endl;
            }
        }

        numberOfTestCase--;
    }

    return 0;
}