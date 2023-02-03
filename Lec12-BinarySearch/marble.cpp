#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, Q;
vector<int> box;
vector<int> q;
int caseOrder = 1;

int binarySearchFirst(int begin, int end, int target){
    if (begin <= end){
        int mid = begin + (end - begin) / 2;

        if ((mid == 0 || target > box[mid - 1]) && target == box[mid]){
            return mid;
        }

        if (target > box[mid]){
            return binarySearchFirst(mid + 1, end, target);
        }else{
            return binarySearchFirst(begin, mid -1, target);
        }
    }

    return -1;
}

int main(){
    while (true){
        cin >> N >> Q;
        if (N == 0 && Q == 0){
            return 0;
        }
        box.clear();
        q.clear();
        for (int i = 0; i < N; i++){
            int value;
            cin >> value;
            box.push_back(value);
        }

        sort(box.begin(), box.end());

        for (int i = 0; i < Q; i++){
            int value;
            cin >> value;
            q.push_back(value);
        }

        cout << "CASE# " << caseOrder << ":" << endl;

        for (int i = 0; i < Q; i++){
            int currentQ = q[i];
            int indexFound = binarySearchFirst(0, N - 1, currentQ);
            if (indexFound != -1){
                cout << currentQ << " found at " << indexFound + 1 << endl;
            }else{
                cout << currentQ << " not found" << endl;
            }
        }

        caseOrder += 1;
    }
}