#include <algorithm>
#include <iostream>
#include <vector>
#define MAX 10
using namespace std;

int numberOfTestCase;
int numberOfNumbers;
bool continueChecking;
struct TrieNode{
    TrieNode* children[MAX];
    int repeat;
};

TrieNode* NewTrieNode(){
    TrieNode* root = new TrieNode();
    for (int i = 0; i < MAX; i++){
        root->children[i] = NULL;
    }
    root->repeat = 0;
    return root;
}

void AddData(TrieNode* root, string number){
    TrieNode* temp = root;

    for (int i = 0; i < number.size(); i++){
        char current = number[i];
        int index = int(current) - 48;
        //cout << index << endl;
        if (temp->children[index] == NULL){
            temp->children[index] = NewTrieNode();
        }
        temp = temp->children[index];
        if (temp->repeat > 0){
            continueChecking = false;
        }
    }

    temp->repeat += 1;
}

TrieNode* root;
vector<long long> dataSet;
int main(){
    cin >> numberOfTestCase;
    for (int i = 0; i < numberOfTestCase; i++){
        root = NewTrieNode();
        cin >> numberOfNumbers;
        continueChecking = true;
        for (int j = 0; j < numberOfNumbers; j++){
            long long intputNumber;
            cin >> intputNumber;
            dataSet.push_back(intputNumber);
        }

        sort(dataSet.begin(), dataSet.end());

        for (int i = 0; i < dataSet.size(); i++){
            string inputNumber = to_string(dataSet[i]);
            if (continueChecking){
                AddData(root, inputNumber);
            }
        }

        if (continueChecking){
            cout << "Case " << i + 1 << ": " << "YES" << endl;
        }else{
            cout << "Case " << i + 1 << ": " << "NO" << endl;
        }

        delete (root);
        dataSet.clear();
    }
    return 0;
}