#include <iostream>
#include <vector>
#define maxN 1000001
using namespace std;

long long Data[maxN];
long long m, n;
long long maxHei = 0;

bool enough(int maxHeight){
    long long sum = 0;
    for (int i = 0; i < n; i++){
        if (Data[i] > maxHeight){
            sum += (Data[i] - maxHeight);
        }
    }

    if (sum >= m){
        return true;
    }

    return false;
}

int main(){
    cin >> n >> m;

    for (int i = 0; i < n; i++){
        cin >> Data[i];
        maxHei = max(maxHei, Data[i]);
    }

    int left = 0;
    int right = maxHei;
    int mid = left + (right - left) / 2;
    int ans;
    while (left <= right){
        if (enough(mid)){
            left = mid + 1;
            ans = mid;
        }else{
            right = mid - 1;
        }

        //cout << "Now mid is: " << mid << endl;

        mid = left + (right - left) / 2;
    }

    cout << ans << endl;
    return 0;

}
