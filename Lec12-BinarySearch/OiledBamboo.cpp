#include <iostream>
#include <vector>

using namespace std;

int numberOfTestCase;
int testCaseOrder = 1;
int n;
vector<int> Data; 


bool CanBeK(int number){
    int temp = number;
    for (int i = 0; i < n; i++){
        if (i == 0){
            if (Data[i] > temp){
                return false;
            }

            if (Data[i] == temp){
                temp--;
                continue;
            }else{
                continue;
            }
        }

        int previousHeight = Data[i - 1];
        int currentHeight = Data[i];

        //can not jump any more
        if (currentHeight - previousHeight > temp){
            return false;
        }

        if (currentHeight - previousHeight == temp){
            temp--;
        }else{
            continue;
        }
    }

    if (temp >= 0){
        return true;
    }

    return false;
}

int main(){

    cin >> numberOfTestCase;


    while (numberOfTestCase > 0){
        Data.clear();
        cin >> n;
        for (int i = 0; i < n; i++){
            int value;
            cin >> value;
            Data.push_back(value);
        }
        
        int left = 0;
        int right = Data[n - 1];
        int mid = left + (right - left) / 2;
        int ans;
        while (left <= right){
            if (CanBeK(mid)){
                ans = mid;
                right = mid - 1;
            }else{
                left = mid + 1; 
            }
            mid = left + (right - left) / 2;
        }

        cout << "Case " << testCaseOrder << ": " << ans << endl;
        testCaseOrder++;
        numberOfTestCase--;
    }
    return 0;
}