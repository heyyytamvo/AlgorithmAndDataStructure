#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int n, k;
vector<int> box;
bool visited[100001];
int maxInBox = 0;
int foundNumber(int target){
    int left = 0;
    int right = n - 1;
    int mid;
    while (left <= right){
        mid = left + (right - left) / 2;
        if (box[mid] == target /*&& visited[box[mid]] == false*/){
            //cout << "Found " << target << " in the box" << endl;
            //visited[box[mid]] = true;
            return 1;
        }
        

        if (target < box[mid]){
            right = mid - 1;
            continue;
        }else if (target > box[mid]){
            left = mid + 1;
            continue;
        }
    }


    return 0;
}

int main(){
    cin >> n >> k;
    for (int i = 1; i <= n; i++){
        int value;
        cin >> value;
        box.push_back(value);
        maxInBox = max(maxInBox, value);

    }

    sort(box.begin(), box.end());
    int res = 0;
    for (int i = 0; i < n; i++){
        int currentValue = box[i];
        int target;
        //there are 2 targets, we need to check whether the target is positive or not
        target = currentValue - k;
        if (target > 0){
            res += foundNumber(target);
        }
        target = currentValue + k;
        
        //cout << "Now, we are checking " << currentValue << ", we need to find " << target << endl;
        res += foundNumber(target);
    }

    res = res / 2;
    cout << res << endl;
    return 0;
}