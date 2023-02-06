#include <iostream>
#include <vector>

using namespace std;

struct Node{
    int key;
    Node *left;
    Node *right;
};

//function creating node
Node* CreatingNode(int x){
    Node* newNode = new Node;
    newNode->key = x;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

//function inserting node
Node* InsertingNode(Node* root, int x){
    if (root == NULL){
        return CreatingNode(x);
    }

    //left node
    if (root->key > x){
        root->left = InsertingNode(root->left, x);
    }else{
        root->right = InsertingNode(root->right, x);
    }

    return root;
}

//creating binary tree
void CreeatingBinaryTree(Node* &root, int a[], int n){
    for (int i = 0; i < n; i++){
        root = InsertingNode(root, a[i]);
    }
}

//function searching a node given a value
Node* SearchNode(Node* root, int value){
    if (root == NULL || root->key == value){
        return root;
    }

    if (value < root->key){
        return SearchNode(root->left, value);
    }
    return SearchNode(root->right, value);
}

Node* minValueNode(Node* node){
    Node* current = node;

    while (current->left != NULL){
        current = current->left;
    }

    return current;
}

//function deleiting a node given a value
Node* DeleteNode(Node* &root, int value){
    if (root == NULL){
        return root;
    }

    if (value < root->key){
        root->left = DeleteNode(root->left, value);
    }else if (value > root->key){
        root->right = DeleteNode(root->right, value);
    }else{
        //this is when we find out the value
        if (root->left == NULL){
            Node* temp = root->right;
            delete root;
            return temp;
        }else if (root->right == NULL){
            Node* temp = root->left;
            delete root;
            return temp;
        }

        Node* temp = minValueNode(root->right);
        root->key = temp->key;
        root->right = DeleteNode(root->right, temp->key);
    }

    return root;
}

void travelsalTree(Node* &root){
    if (root != NULL){
        travelsalTree(root->left);
        cout << root->key << " ";
        travelsalTree(root->right);
    }
}


void deleteBinaryTree(Node* &root){
    if (root == NULL){
        return;
    }

    deleteBinaryTree(root->left);
    deleteBinaryTree(root->right);
    delete(root);
}

//int array1[7] = {30, 20, 40, 15, 25, 37, 45};
int array1[7] = {15, 20, 30, 25, 37, 40, 45};

int main(){
    Node* myBinanyTree;
    CreeatingBinaryTree(myBinanyTree, array1, 7);
    travelsalTree(myBinanyTree);
    cout << endl;
    DeleteNode(myBinanyTree, 37);
    cout << "After deleting 37 from the binary tree: " << endl;
    travelsalTree(myBinanyTree);
    return 0;    
}