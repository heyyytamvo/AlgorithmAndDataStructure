#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int binarySearchFirst(vector<int> &box,int begin, int end, int target){
    if (begin <= end){
        int mid = begin + (end - begin) / 2;

        if ((mid == 0 || target > box[mid - 1]) && target == box[mid]){
            return mid;
        }

        if (target > box[mid]){
            return binarySearchFirst(box, mid + 1, end, target);
        }else{
            return binarySearchFirst(box, begin, mid -1, target);
        }
    }

    return -1;
}


int numberOfTestCase;
int n, m;

int main(){
    cin >> numberOfTestCase;
    for (int i = 0; i < numberOfTestCase; i++){
        cin >> n >> m;
        int res = 0;
        vector<int> friendsList;
        for (int j = 0; j < n; j++){
            int value;
            cin >> value;
            friendsList.push_back(value);
        }

        sort(friendsList.begin(), friendsList.end());
        for (int j = 0; j < n; j++){
            int currentFriend = friendsList[j];
            int neededMoney = m - currentFriend;

            int temp = binarySearchFirst(friendsList, 0, n, neededMoney);
            if (temp != -1){
                res++;
            }
        }

        cout << res / 2 << endl;
    }

    return 0;
}