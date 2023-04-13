#include <iostream>
#include <string>
#define MAX 26
using namespace std;


struct Node
{
    /* data */
    struct Node* child[MAX];
    int countWord;
};

Node *NewNode(){
    Node *node = new Node;
    node->countWord = 0;

    for (int i = 0; i < MAX; i++){
        node->child[i] = NULL;
    }

    return node;
}

bool findWord(Node* root, string word, int index){
    int character = word[index] - 'a';

    if (index == word.size() - 1 && root->child[character]->countWord > 0){
        return true;
    }

    if (root->child[character] == NULL){
        return false;
    }else{
        findWord(root->child[character], word, index + 1);
    }

    return true;
}

//determining leaf
bool isEmpty(Node* node){
    for (int i = 0; i < MAX; i++){
        if (node->child[i] != NULL){
            return false;
        }
    }
    return true;
}

void addWord(Node* root, string word){
    int character;
    Node *temp = root;

    for (int i = 0; i < word.size(); i++){
        character = word[i] - 'a';

        //there are no prefix
        if (temp->child[character] == NULL){
            temp->child[character] = NewNode();
        }
        temp = temp->child[character];
    }
    temp->countWord++;
}

bool isWord(Node* node){
    return (node->countWord > 0);
}

bool deleteWord(Node* root, string word, int level, int length){
    if (!root){
        return false;
    }

    if (level == length){
        if (root->countWord == 1){
            root->countWord--;
            return true;
        }

        return false;
    }

    int character = word[level] - 'a';
    int flag = deleteWord(root->child[character], word, level + 1, length);
    if (flag && !isWord(root->child[character]) && isEmpty(root->child[character])){
        delete root->child[character];
        root->child[character] = NULL;
    }

    return flag;
}




int main(){
    string word = "cart";
    string word1 = "care";
    Node* dictionary = NewNode();

    addWord(dictionary, word);
    addWord(dictionary, word1);
    //cout << dictionary->child[2]->countWord << endl;
    //cout << dictionary->child[2]->child[0]->countWord << endl;
    //cout << dictionary->child[2]->child[0]->child[17]->countWord << endl;
    //cout << dictionary->child[2]->child[0]->child[17]->child[19]->countWord << endl;
    //cout << dictionary->child[2]->child[0]->child[17]->child[4]->countWord << endl;
    cout << findWord(dictionary, word1, 0) << endl;
    cout << findWord(dictionary, "haha", 0) << endl;

    return 0;
}