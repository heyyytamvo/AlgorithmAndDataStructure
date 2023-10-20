// 339D
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
typedef int ll;


int n, m;
vector<ll> arr;
vector<ll> segmentTree;

ll ORoperation(ll a, ll b){
    return a | b;
}

ll XORoperation(ll a, ll b){
    return a ^ b;
}

void constructSegmentTreeN(vector<ll> &segmentTree, vector<ll> inputArray, int start, int end, int pos, bool XOR){
    if (start == end){
        segmentTree[pos] = inputArray[start];
        return;
    }

    ll mid = (start + end) / 2;
    constructSegmentTreeN(segmentTree, inputArray, start, mid, (2 * pos + 1), !XOR);
    constructSegmentTreeN(segmentTree, inputArray, mid + 1, end, (2 * pos + 2), !XOR);

    ll leftChild = segmentTree[(2 * pos + 1)];
    ll rightChild = segmentTree[(2 * pos + 2)];

    if (XOR){
        segmentTree[pos] = XORoperation(leftChild, rightChild);
        return;
    }
    segmentTree[pos] = ORoperation(leftChild, rightChild);
    return;
}

void Query(vector<ll> &segmentTree, int qStart, int qEnd, int start, int end, bool XOR, int pos, ll b){
    if ((qStart == start) && (qEnd == end)){
        segmentTree[pos] = b;
        return;
    }
    
    // stop
    if ((qStart > end) || (start > qEnd)){
        return;
    }

    
    int mid = (start + end) / 2;
    int leftEnd = mid;
    Query(segmentTree, qStart, qEnd, start, mid, !XOR, (2 * pos + 1), b);
    Query(segmentTree, qStart, qEnd, mid + 1, end, !XOR, (2 * pos + 2), b);

    if (XOR){
        segmentTree[pos] = XORoperation(segmentTree[(pos * 2 + 1)], segmentTree[(pos * 2 + 2)]);
        return;
    }
    segmentTree[pos] = ORoperation(segmentTree[(pos * 2 + 1)], segmentTree[(pos * 2 + 2)]);

    return;
}

int main(){
    cin >> n >> m;
    for (int i = 0; i < pow(2, n); i++){
        ll temp;
        cin >> temp;
        arr.push_back(temp);
    }

    int numberOfNode = 2 * pow(2, ceil(log2(arr.size()))) - 1;
    segmentTree = vector<ll>(numberOfNode, -1);
    
    if (n % 2 == 0){
        constructSegmentTreeN(segmentTree, arr, 0, arr.size() - 1, 0, true);
    }else{
        constructSegmentTreeN(segmentTree, arr, 0, arr.size() - 1, 0, false);
    }

    int p, b;
    for (int i = 0; i < m; i++){
        cin >> p >> b;
        if (n % 2 == 0){
            Query(segmentTree, p - 1, p - 1, 0, arr.size() - 1, true, 0, b);
        } else{
            Query(segmentTree, p - 1, p - 1, 0, arr.size() - 1, false, 0, b);
        }

        cout << segmentTree[0] << endl;
    }

    return 0;
}