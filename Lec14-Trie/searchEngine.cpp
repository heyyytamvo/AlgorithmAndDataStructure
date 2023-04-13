#include <iostream>
#include <queue>
#define MAX 26
using namespace std;

struct TrieNode{
    int priority;
    TrieNode* Children[MAX];
};

TrieNode* NewNode(){
    TrieNode* root = new TrieNode();
    root->priority = 0;
    for (int i = 0; i < MAX; i++){
        root->Children[i] = NULL;
    }

    return root;
}

void insertWord(TrieNode* root, string word, int _priority){
    int character;
    TrieNode* temp = root;
    for (int i = 0; i < word.size(); i++){
        character = word[i] - 'a';

        //if there are no prefix
        if (temp->Children[character] == NULL){
            temp->Children[character] = NewNode();
        }

        temp = temp->Children[character];
    }

    temp->priority = _priority;
}

int findMaxPriority(TrieNode* root, string word){
    int character;
    int output = -1;
    TrieNode* temp = root;
    for (int i = 0; i < word.size(); i++){
        character = word[i] - 'a';
        if (temp->Children[character] == NULL){
            return -1;
        }
        temp = temp->Children[character];
    }

    //now, we reached the end of the keyword, BFS
    int lastCharacter = word[word.size() - 1];
    queue<TrieNode*> waitingQueue;
    waitingQueue.push(temp);

    while (waitingQueue.empty() == false){
        TrieNode* currentChecking = waitingQueue.front();
        waitingQueue.pop();
        output = max(output, currentChecking->priority);

        for (int i = 0; i < MAX; i++){
            TrieNode* child = currentChecking->Children[i];
            if (child == NULL){
                continue;
            }

            waitingQueue.push(child);
        }
    }

    return output;
}

int n, p;
TrieNode* dictionary;

int main(){
    cin >> n >> p;
    dictionary = NewNode();

    for (int i = 0; i < n; i++){
        string keyWord;
        int prio;

        cin >> keyWord >> prio;
        insertWord(dictionary, keyWord, prio);
    }

    for (int i = 0; i < p; i++){
        string keyWord;
        cin >> keyWord;

        cout << findMaxPriority(dictionary, keyWord) << endl;
    }

    return 0;
}