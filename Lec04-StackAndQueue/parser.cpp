#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;
#define MAX 101


int numberOfTestCase;
int main(){
    cin >> numberOfTestCase;
    for (int i = 0; i < numberOfTestCase; i++){
        int res = 0;
        stack<char> q;

        string input;
        cin >> input;
        for (int j = 0; j < input.length(); j++){
            char current = input[j];
            if (current == '<'){
                q.push(current);
            }else{
                if (q.empty()){
                    break;
                }else{
                    q.pop();
                    if (q.empty()){
                        res = j + 1;
                    }
                }
            }
        }
        cout << res << endl;
    }
}