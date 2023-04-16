#include <iostream>
#include <cstring>
#define MAX 26
using namespace std;

struct Dictionary{
    Dictionary* Children[MAX];
    int isAContact;
};

Dictionary* NewDictionary(){
    Dictionary* root = new Dictionary();
    for (int i = 0; i < MAX; i++){
        root->Children[i] = NULL;
    }

    root->isAContact = 0;
    return root;
}

void AddContact(Dictionary* Dict, string name){
    int index;
    Dictionary* temp = Dict;
    for (int i = 0; i < name.size(); i++){
        index = name[i] - 'a';

        if (temp->Children[index] == NULL){
            temp->Children[index] = NewDictionary();
        }

        temp = temp->Children[index];
        temp->isAContact += 1;
    }
}

int findAnswer(Dictionary* Dict, string name){
    int index;
    Dictionary* temp = Dict;
    for (int i = 0; i < name.size(); i++){
        index = name[i] - 'a';
        if (temp->Children[index] == NULL){
            return 0;
        }
        temp = temp->Children[index];
    }

    return temp->isAContact;
}

int numberOfOperations;


int main(){
    cin >> numberOfOperations;
    Dictionary* ContactList = NewDictionary();
    for (int i = 0; i < numberOfOperations; i++){
        string command;
        string word;
        cin >> command;
        cin >> word;
        //adding operation
        if (command[0] == 'a'){
            AddContact(ContactList, word);
        }else{
            cout << findAnswer(ContactList, word) << endl;
        }
    }

    return 0;
}
