#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <map>
#include <cmath>
#define MAX_V 205
#define MAX_E 205 * 204
using namespace std;
const int INF = 1e9 + 7;

struct Edge {
    int source, target, weight;
};

int n, m;
int weight[MAX_V];
int dist[MAX_V];
Edge graph[MAX_E];

void BellmanFord(int s) {
    fill(dist, dist + (n + 1), INF);
    dist[s] = 0;

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < m; j++) {
            int u = graph[j].source;
            int v = graph[j].target;
            int w = graph[j].weight;

            if (dist[u] != INF) {
                dist[v] = min(dist[v], dist[u] + w);
            }
        }
    }
}

int main() {
    int T, q, u, v, f;
    cin >> T;

    for (int t = 1; t <= T; t++) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> weight[i];
        }

        cin >> m;
        for (int i = 0; i < m; i++) {
            cin >> u >> v;
            graph[i] = (Edge) {u, v, int(pow(weight[v] - weight[u], 3))};
        }

        BellmanFord(1);
        cin >> q;
        cout << "Case " << t << ":" << endl;

        for (int i = 0; i < q; i++) {
            cin >> f;

            if (dist[f] != INF && dist[f] >= 3) {
                cout << dist[f] << endl;
            }
            else {
                cout << "?" << endl;
            }
        }
    }
    return 0;
}