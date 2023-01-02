#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <map>

using namespace std;

int main(){
    string value;
    cin >> value;
    int result = 1;

    for (int i = 0; i < value.length(); i++){
        int asciiValue = value[i];
        if (65 <= asciiValue && asciiValue <= 90){
            result += 1;
        }
    }

    cout << result << endl;
    return 0;
}
