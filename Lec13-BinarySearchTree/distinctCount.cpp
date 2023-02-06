#include <iostream>
#include <set>

using namespace std;

int numberOfTestCase;
int X, N;

void execute(){
    cin >> N >> X;
    set<int> box;
    for (int i = 0; i < N; i++){
        int value;
        cin >> value;
        box.insert(value);
    }

    if (box.size() == X){
        cout << "Good" << endl;
    }else if (box.size() < X){
        cout << "Bad" << endl;
    }else{
        cout << "Average" << endl;
    }
}

int main(){
    cin >> numberOfTestCase;
    for (int i = 0; i < numberOfTestCase; i++){
        execute();
    }

    return 0;
}