#include <iostream>
#include <queue>
#include <vector>

using namespace std;
#define MAX 100
const int INF = 1e9;
vector< vector< pair<int, int> > > Graph;
vector<int> dist(MAX, INF);
int path[MAX];
int numberOfVertices, weight, startVertex, endVertex;

//pair : vertex, distance
//adjacent edges list
struct option {
    bool operator()(
        pair<int, int> const& a,
        pair<int, int> const& b)
        const 
    {
        return a.second > b.second;
    }
};

void Dijkstra(int vertex){
    priority_queue< pair<int, int>, vector< pair<int, int> >, option > pq;
    dist[vertex] = 0;
    pq.push(make_pair(vertex, 0));

    while (!pq.empty()){
        pair<int, int> value = pq.top();
        pq.pop();
        int u = value.first;
        int w = value.second;

        for (int i = 0; i < Graph[u].size(); i++){
            pair<int, int> nextVertex = Graph[u][i];

            if (w + nextVertex.second < dist[nextVertex.first]){
                dist[nextVertex.first] = w + nextVertex.second;
                pq.push(make_pair(nextVertex.first, (w + nextVertex.second)));
                path[nextVertex.first] = u;
            }
        }
    }
}

void input(){
    Graph = vector< vector< pair<int, int> > > (MAX + 5, vector< pair<int, int> >());
    memset(path, -1, sizeof(path));
    cin >> numberOfVertices;
    for (int i = 0; i < numberOfVertices; i++){
        for (int j = 0; j < numberOfVertices; j++){
            cin >> weight;

            if (weight > 0){
                Graph[i].push_back(make_pair(j, weight));
            }
        }
    }
}

void printMinPath(int start, int end){
    Dijkstra(start);
    int cost = end; 
    vector<int> pathWay;

    while (true){
        if (start == end){
            pathWay.push_back(end);
            break;
        }

        if (path[end] == -1){
            cout << "There are no paths" << endl;
            return;
        }

        pathWay.push_back(end);
        end = path[end];
    }

    cout << "The optimized path from " << pathWay[pathWay.size() - 1] << " to " << pathWay[0] << " is: ";
    for (int i = pathWay.size() - 1; i >= 0; i--){
        cout << pathWay[i] << " ";
    }

    cout << endl << "The cost is " << dist[cost] << endl;

    return;
}

int main(){
    input();
    cout << "Start " << endl;
    cin >> startVertex;
    cout << "End " << endl;
    cin >> endVertex;

    printMinPath(startVertex, endVertex);
    
    return 0;
}
