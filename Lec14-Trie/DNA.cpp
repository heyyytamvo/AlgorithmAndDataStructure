#include <iostream>
#include <map>
#define MAX 4
//A C G T
using namespace std;
map<char, int> Encode;
int result = 0;

struct TrieNode{
    TrieNode* children[MAX];
    int count;
};

TrieNode* NewNode(){
    TrieNode* root = new TrieNode();
    for (int i = 0; i < MAX; i++){
        root->children[i] = NULL;
    }
    root->count = 0;
    return root;
}

void AddDNA(TrieNode* root, string DNA){
    int index;
    TrieNode* temp = root;
    for (int i = 0; i < DNA.size(); i++){
        index = Encode[DNA[i]];
        
        if (temp->children[index] == NULL){
            temp->children[index] = NewNode();
        }
        temp = temp->children[index];
        temp->count += 1;
        int level = i + 1;
        //cout << "Current Result: " << result << endl;
        //cout << "Temp :" << level * temp->count << endl;
        result = max(result, level * temp->count);
        //cout << "New Result: " << result << endl;
    }
    
}



int numberOfTestCase, n;


int main(){
    cin >> numberOfTestCase;
    //numberOfTestCase = 1;
    Encode['A'] = 0;
    Encode['C'] = 1;
    Encode['G'] = 2;
    Encode['T'] = 3;
    
    for (int i = 0; i < numberOfTestCase; i++){
        cin >> n;
        //new root
        TrieNode* root = NewNode();
        //n = 4;
        for (int j = 0; j < n; j++){
            string DNA;
            cin >> DNA;
            AddDNA(root, DNA);
            //cout << result << endl;
        }
        cout << "Case " << i + 1 << ": " << result << endl;
        result = 0;
        delete (root);
    }
/*DEBUG
    string testString;
    cin >> testString;
    TrieNode* root = NewNode();
    AddDNA(root, testString);
    TrieNode* temp = root;
    for (int i = 0; i < testString.size(); i++){
        char character = testString[i];
        int index = Encode[character];
        cout << temp->count << endl;
        temp = temp->children[index];
    }

    cout << temp->count;
*/
    return 0;
}