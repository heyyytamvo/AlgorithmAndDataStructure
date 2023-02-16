#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <queue>

using namespace std;



int numberOfTeam;
map<string, int> encoded;
set<string> nameList;
vector<int> adj[300];
bool visited[300];
vector<int> path = vector<int>(300, -1);


void BFS(int vertexOfIsenbaev){
    queue<int> q;
    q.push(vertexOfIsenbaev);
    visited[vertexOfIsenbaev] = true;


    while (!q.empty()){
        int current = q.front();
        q.pop();

        for (int neighbour : adj[current]){
            if (visited[neighbour] == false){
                visited[neighbour] = true;
                path[neighbour] = current;
                q.push(neighbour);
            }
        }
    }
}

int result(int vertexI, int target){
    int finalRes = 0;
    while (true){
        if (vertexI == target){
            break;
        }

        if (path[target] == -1){
            break;
        }

        target = path[target];
        finalRes++;
    }

    return finalRes;
}

bool alreadyExist(string name){
    if (encoded.find(name) == encoded.end()){
        return false;
    }
    return true;
}

int order = 0;
int main(){

    cin >> numberOfTeam;
    for (int i = 0; i < numberOfTeam; i++){
        string A, B, C;
        cin >> A >> B >> C;
        nameList.insert(A);
        nameList.insert(B);
        nameList.insert(C);
        if (!alreadyExist(A)){
            encoded.insert( pair<string, int>(A, order) );
            order++;
        }

        if (!alreadyExist(B)){
            encoded.insert( pair<string, int>(B, order) );
            order++;
        }

        if (!alreadyExist(C)){
            encoded.insert( pair<string, int>(C, order) );
            order++;
        }

        int vertexOfA = encoded[A];
        int vertexOfB = encoded[B];
        int vertexOfC = encoded[C];

        adj[vertexOfA].push_back(vertexOfB);
        adj[vertexOfA].push_back(vertexOfC);
        adj[vertexOfB].push_back(vertexOfA);
        adj[vertexOfB].push_back(vertexOfC);
        adj[vertexOfC].push_back(vertexOfA);
        adj[vertexOfC].push_back(vertexOfB);
    }

    if (alreadyExist("Isenbaev") == false){
        for (const string name : nameList){
            cout << name << " undefined"<< endl;
        }

        return 0;
    }

    BFS(encoded["Isenbaev"]);
    for (const string name : nameList){
        int res = result(encoded["Isenbaev"], encoded[name]);

        if (res == 0 && name != "Isenbaev"){
            cout << name << " undefined"<< endl;
        }else{
            cout << name << " " << res << endl;
        }
    }
    return 0;
}