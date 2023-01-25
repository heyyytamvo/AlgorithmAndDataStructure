#include <iostream>
#include <vector>
#include <string>
#define INF 999999999

using namespace std;

int numberOfTestCase;
vector< vector<string> > Data;
vector< vector< vector<int> > > matricies;
void input(){
    cin >> numberOfTestCase;

    for (int i = 0; i < numberOfTestCase; i++){
        string firstPerson;
        cin >> firstPerson;
        vector<string> testCase;
        testCase.push_back(firstPerson);
        for (int j = 1; j < firstPerson.length(); j++){
            string temp;
            cin >> temp;
            testCase.push_back(temp);
        }
        Data.push_back(testCase);
    }
}

void initialize(){
    for (int i = 0; i < numberOfTestCase; i++){
        vector<string> currentTestCase = Data[i];
        int numberOfPeople = currentTestCase[0].size();
        vector< vector<int> > matrix = vector< vector<int> > (numberOfPeople, vector<int>(numberOfPeople)); ;
        for (int j = 0; j < numberOfPeople; j++){
            int currentPossibleFriends = 0;
            for (int k = 0; k < numberOfPeople; k++){
                char status = currentTestCase[j][k];
                if (j == k){
                    matrix[j][k] = 0;
                    continue;
                }
                if (status == 'Y'){
                    matrix[j][k] = 1;
                }else{
                    matrix[j][k] = INF;
                }
            }
        } 
        matricies.push_back(matrix);
    }
}

void FloydWarshall(vector< vector<int> > matrix, int numberOfPeople){
    vector< vector<int> > Dist = vector< vector<int> > (numberOfPeople, vector<int>(numberOfPeople, INF));
    int personID;
    int possibleFriends = -1;
    for (int i = 0; i < numberOfPeople; i++){
        for (int j = 0; j < numberOfPeople; j++){
            Dist[i][j] = matrix[i][j];
        }
    }

    for (int k = 0; k < numberOfPeople; k++){
        for (int i = 0; i < numberOfPeople; i++){
            for (int j = 0; j < numberOfPeople; j++){
                Dist[i][j] = min(Dist[i][j], Dist[i][k] + Dist[k][j]);
            }
        }
    }

    for (int i = 0; i < numberOfPeople; i++){
        int temp = 0;
        for (int j = 0; j < numberOfPeople; j++){
            if (Dist[i][j] == 2){
                temp++;
            }
        }

        if (temp > possibleFriends){
            possibleFriends = temp;
            personID = i;
        }
    }

    cout << personID << " " << possibleFriends << endl;
}

int main(){
    input();
    initialize();
    for (int i = 0; i < numberOfTestCase; i++){
        vector< vector<int> > matrix = matricies[i];
        int numberOfPerson = matrix[0].size();
        FloydWarshall(matrix, numberOfPerson);
    }


    return 0;
}