#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

bool compareStringLength(const string& s1, const string& s2) {
    return s1.length() < s2.length(); // Use "<" to sort in ascending order
}


int n, k;
string password;
vector<string> enterList;
int bestIndex, worstIndex;

int timeResult(int target, int k){
    int output = 0;
    int temp = 0;
    for (int i = 1; i <= target; i++){
        if (temp == k){
            temp = 0;
            output += 5;
        }

        output++;
        temp++;
    }

    return output;
}

int main(){
    cin >> n >> k;

    for (int i = 0; i < n; i++){
        string enterPassword;
        cin >> enterPassword;
        enterList.push_back(enterPassword);
    }

    cin >> password;
    sort(enterList.begin(), enterList.end(), compareStringLength);

    //finding best index;
    for (int i = 0; i < n; i++){
        string currentCheck = enterList[i];
        if (currentCheck.size() == password.size()){
            bestIndex = i + 1;
            break;
        }
    }

    //finding worst index
    for (int i = 0; i < n - 1; i++){
        string worstCase = enterList[i];
        string next = enterList[i + 1];
        if (worstCase.size() == password.size() && worstCase.size() < next.size()){
            worstIndex = i + 1;
            break;
        }
    }

    //in case the password is at the end of the list
    if (enterList[n - 1].size() == password.size()){
        worstIndex = n;
    }

    int bestTime = timeResult(bestIndex, k);
    int worstTime = timeResult(worstIndex, k);

    cout << bestTime << " " << worstTime << endl;
    return 0;
}