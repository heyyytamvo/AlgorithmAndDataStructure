#include <iostream>
#include <queue>
#include <vector>
#define MAX 26

using namespace std;


struct TrieNode{
    TrieNode* children[MAX];
    int value;
};

TrieNode* newNode(){
    TrieNode* root = new TrieNode();
    for (int i = 0; i < MAX; i++){
        root->children[i] = NULL;
    }
    root->value = 0;
    return root;
}

bool Adding(TrieNode* root, string word){
    int index;
    TrieNode* temp = root;
    TrieNode* check = root;
    TrieNode* check1 = root;
    bool continueChecking = true;

    //its prefix is already contained in the root
    for (int i = 0; i < word.size(); i++){
        index = word[i] - 'a';
        
        if (check->children[index] == NULL){
            break;
        }
        
        if (check->children[index] != NULL && check->children[index]->value){
            return false;
        }
        check = check->children[index];
    }
    //cout << "HERE" << endl;

    //added word is the prefix of other words 
    for (int i = 0; i < word.size(); i++){
        index = word[i] - 'a';

        if (check1->children[index] == NULL){
            continueChecking = false;
            break;
        }

        check1 = check1->children[index];
    }

    if (continueChecking){
        for (int i = 0; i < MAX; i++){
            if (check1->children[i] != NULL){
                return false;
            }
        }
    }

    //adding
    for (int i = 0; i < word.size(); i++){
        index = word[i] - 'a';

        if (temp->children[index] == NULL){
            temp->children[index] = newNode();
        }
        temp = temp->children[index];
    }
    temp->value += 1;
    

    return true;
}



int n;
TrieNode* root;
vector<string> listWords;
int main(){
    cin >> n;
    root = newNode();

    for (int i = 0; i < n; i++){
        string word;
        cin >> word;
        listWords.push_back(word);
    }

    for (int i = 0; i < n; i++){
        string word = listWords[i];
        if (!Adding(root, word)){
            cout << "vulnerable" << endl;
            return 0;
        }
    }
    
    cout << "non vulnerable" << endl;

    return 0;
}