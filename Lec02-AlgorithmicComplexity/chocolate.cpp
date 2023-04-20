#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> list;
bool cannotEat[100001];

int main(){
    cin >> N;
    for (int i = 0; i < N; i++){
        int num;
        cin >> num;
        list.push_back(num);
    }

    if (N == 1){
        cout << "1 0" << endl;
        return 0;
    }

    int i = 0;
    int j = N - 1;
    int timeA, timeB;
    int ChocoA = 0;
    int ChocoB;
    timeA = 0;
    timeB = 0;
    int clock = 0;

    while (i <= j){
        if (timeA <= timeB){
            ChocoA++;
            timeA += list[i];
            i++;
        }else{
            timeB += list[j];
            j--;
        }
    }

    cout << ChocoA << " " << N - ChocoA << endl;

    return 0;
}