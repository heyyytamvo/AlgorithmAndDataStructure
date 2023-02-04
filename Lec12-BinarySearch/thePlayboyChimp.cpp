#include <iostream>
#include <vector>

using namespace std;

int N, Q;
vector<long long> ladyChimp;
vector<long long> chimpanzeesHeight;

int binarySearchShorter(long long currentHeight){
    int left = 0;
    int right = N - 1;
    int mid = left + (right - left) / 2;
    int ans;

    // if all ladies are shorter than current chimpanzee
    if (ladyChimp[right] < currentHeight){
        return ladyChimp[right];
    }

    // if all ladies are taller than current chimpanzee
    if (ladyChimp[left] >= currentHeight){
        return -1;
    }

    while (left <= right){
        if (ladyChimp[mid] < currentHeight){
            ans = mid;
            left = mid + 1;
        }else{
            right = mid - 1;
        }
        mid = left + (right - left) / 2;
    }
    return ladyChimp[ans];
}


int binarySearchTaller(long long currentHeight){
    int left = 0;
    int right = N - 1;
    int ans;
    int mid = left + (right - left) / 2;

    //if all ladies are shorter than current height
    if (ladyChimp[right] <= currentHeight){
        return -1;
    }

    //if all ladies are taller than current height 
    if (ladyChimp[left] > currentHeight){
        return ladyChimp[left];
    }

    while (left <= right){
        if (ladyChimp[mid] <= currentHeight){
            left = mid + 1;
        }else{
            ans = mid;
            right = mid - 1;
        }

        mid = left + (right - left) / 2;
    }

    return ladyChimp[ans];
}

int main(){
    cin >> N;
    for (int i = 0; i < N; i++){
        long long value;
        cin >> value;
        ladyChimp.push_back(value);
    }

    cin >> Q;
    for (int i = 0; i < Q; i++){
        long long value;
        cin >> value;

        chimpanzeesHeight.push_back(value);
    }

    for (int i = 0; i < Q; i++){
        long long currentHeight = chimpanzeesHeight[i];
        if (binarySearchShorter(currentHeight) != -1){
            cout << binarySearchShorter(currentHeight) << ' ';
        }else{
            cout << 'X' << ' ';
        }

        if (binarySearchTaller(currentHeight) != -1){
            cout << binarySearchTaller(currentHeight);
        }else{
            cout << 'X';
        }

        cout << endl;
    }

    cout << endl;
    return 0;
}