#include <iostream>
#include <vector>
using namespace std;

int N;
vector<int> listNumber;
vector<int> Result;

int main(){
    cin >> N;
    for (int i = 0; i < N; i++){
        int num;
        cin >> num;
        listNumber.push_back(num);
    }
    int res = 0; 
    int Pointer1Index = 0;
    int Pointer2Index = 0;
    int currentMin;
    int currentMax;
    currentMin = min(listNumber[Pointer2Index], listNumber[Pointer1Index]);
    currentMax = max(listNumber[Pointer2Index], listNumber[Pointer1Index]);
    
    while (Pointer2Index < N){
        Pointer2Index++;
        currentMax = max(currentMax, listNumber[Pointer2Index]);
        if ((abs(listNumber[Pointer2Index] - currentMin) <= 1) && abs(currentMax - listNumber[Pointer2Index]) <= 1){
            continue;
        }else{
            Result.push_back(Pointer2Index - Pointer1Index);
            int targetMin = min(currentMin, listNumber[Pointer2Index]);
            currentMax = max(currentMax, listNumber[Pointer2Index]);
            while (currentMax - currentMin > 1){
                
            }

            
        }
    }

    for (int i = 0; i < Result.size(); i++){
        cout << Result[i] << endl;
    }
    //cout << Pointer1Index << endl;
    //cout << Pointer2Index << endl;
    return 0;

}