#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int binarySearch(vector<int> &a, int left, int right, int x){

    while (left <= right){
        int mid = (left + right) / 2;
        if (a[mid] == x){
            return mid;
        }

        if (x < a[mid]){
            right = mid - 1;
        }else if (x > a[mid]){
            left = mid + 1;
        }
    }

    return -1;
}

int binarySearchFirst(vector<int> a, int left, int right, int x){
    if (left <= right){
        int mid = left + (right - left) / 2;
        cout << "Mid is " << a[mid] << endl;

        if ((mid == 0 || x > a[mid - 1]) && x == a[mid]){
            return mid;
        }
        
        if (x > a[mid]){
            return binarySearchFirst(a, mid + 1, right, x);
        }else{
            return binarySearchFirst(a, left, mid - 1, x);
        }
    }
    return -1;
}


int binarySearchLast(vector<int> a, int left, int right, int x){
    if (left <= right){
        int mid = left + (right - left) / 2;

        if (mid == a.size() - 1 || x < a[mid + 1]){
            return mid;
        }
        
        if (x < a[mid]){
            return binarySearchLast(a, left, right - 1, x);
        }else{
            return binarySearchLast(a, mid + 1, right, x);
        }
    }
    return -1;
}
int main(){
    vector<int> arr;
    int test[10] = {1, 2, 2, 2, 2, 3, 4, 7, 8, 8 };

    for (int x : test){
        arr.push_back(x);
        cout << x << " ";
    }
    cout << endl;
    int first2 = binarySearchFirst(arr, 0, 9, 2);
    cout << first2 << endl;

    int last2 = binarySearchLast(arr, 0, 9, 2);
    cout << last2 << endl;
    return 0;
}