#include <iostream>
#include <vector>

using namespace std;


int num;
vector<int> list;

int main(){
    cin >> num;
    for (int i = 0; i < num; i++){
        int l;
        cin >> l;
        list.push_back(l);
    }

    int peopleIsKilled = 0;
    int j = num - 1;
    int lastKilledPosition = 0;
    for (int i = num - 1; i >= 0; i--){
        j = min(j, i);
        lastKilledPosition = max(0, i - list[i]);

        if (lastKilledPosition < j){
            peopleIsKilled += (j - lastKilledPosition);
            j = lastKilledPosition;
        }
    }


    cout << num - peopleIsKilled << endl;
    return 0;
}