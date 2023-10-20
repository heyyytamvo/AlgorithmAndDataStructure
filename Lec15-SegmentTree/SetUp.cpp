#include <iostream>
#include <vector>
#include <cmath>

using namespace std;


class MinSegmentTree{
    private:
        vector<int> SegmentTree;

        void ConstructSegmentTree(vector<int> &segmentTree, vector<int> inputArray, int start, int end, int pos){
            if (start == end){
                segmentTree[pos] = inputArray[start];
                return;
            }

            int mid = (start + end) / 2;

            ConstructSegmentTree(segmentTree, inputArray, start, mid, (2 * pos + 1));
            ConstructSegmentTree(segmentTree, inputArray, mid + 1, end, (2 * pos + 2));
            segmentTree[pos] = min(segmentTree[(2 * pos + 1)], segmentTree[(2 * pos + 2)]);
        }

    public:
        MinSegmentTree(vector<int> inputArray){
            int numberOfNode = 2 * pow(2, ceil(log2(inputArray.size()))) - 1;
            SegmentTree = vector<int>(numberOfNode, -1);
            ConstructSegmentTree(SegmentTree, inputArray, 0, inputArray.size() - 1, 0);
        }

        int RangeMinimumQuery(int startQ, int endQ, int startR, int endR, int pos){
            
            /// no overlap
            if (((startQ < startR) && (endQ < startR)) || ((startQ > endR) && (endQ > endR))){
                return 99999999;
            }

            /// total overlap
            if ((startQ <= startR) && (endQ >= endR)){ 
                return SegmentTree[pos];
            }
            
            /// partial overlap

            int leftChildStart = startR;
            int leftChildEnd = (startR + endR) / 2;
            int minOfLeftChild = RangeMinimumQuery(startQ, endQ, leftChildStart, leftChildEnd, (2 * pos + 1));
            
            int rightChildStart = leftChildEnd + 1;
            int rightChildEnd = endR;
            int minOfRightChild = RangeMinimumQuery(startQ, endQ, rightChildStart, rightChildEnd, (2 * pos + 2));
            

            return min(minOfLeftChild, minOfRightChild);
        }
};


// int main(){
//     vector<int> input;
//     int num;
//     cin >> num;

//     for (int i = 0; i < num; i++){
//         int temp;
//         cin >> temp;
//         input.push_back(temp); 
//     }

//     MinSegmentTree myMinSegmentTree = MinSegmentTree(input);
//     // cout << myMinSegmentTree.SegmentTree.size() << endl;
    
//     int startQ, endQ;
//     cin >> startQ >> endQ;

//     cout << myMinSegmentTree.RangeMinimumQuery(startQ, endQ, 0, input.size() - 1, 0) << endl;

//     return 0;
// }