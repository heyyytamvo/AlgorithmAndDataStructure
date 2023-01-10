#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


vector<bool> Exist = vector<bool> (1001, false);
vector<int> height = vector<int> (1001, 0);
int counting = 0;
int maxHeight = 0;
int N;

int main(){
    cin >> N;
    for (int i = 0; i < N; i++){
        int value;
        cin >> value;
        if (Exist[value] == false){
            Exist[value] = true;
            height[value] += 1;
            counting += 1;
        }else{
            height[value] += 1;
        }

        maxHeight = max(maxHeight, height[value]);
    }

    cout << maxHeight << " " << counting;
    return 0;
}