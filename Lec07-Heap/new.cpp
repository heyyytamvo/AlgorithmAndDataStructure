#include <iostream>
#include <queue>
#include <cstdio>
#include <iomanip>
#define MAX 100005
using namespace std;

struct Job {
    int a, b, d;
    bool operator<(const Job &other) const {
        return a < other.a;
    }
};

bool wayToSort(const Job &x, const Job &y) {
    return x.d < y.d;
}

 int main() {
    int t, N;
    cin >> t;

    while (t--) {
        cin >> N;
        Job job[MAX];
        priority_queue<Job> pq;

        for (int i = 0; i < N; i++) {
            cin >> job[i].a >> job[i].b >> job[i].d;
        }

        sort(job, job + N, wayToSort);
        double money = 0;
        int time = 0;

        for (int i = 0; i < N; i++) {
            time += job[i].b;
            pq.push(job[i]);
            
            while (time > job[i].d) {
                Job top = pq.top();
                pq.pop();

                if (top.b > time - job[i].d) {
                    money += (time - job[i].d) * 1.0 / top.a;
                    top.b -= time - job[i].d;
                    pq.push(top);
                    time = job[i].d;
                }
                else {
                    money += top.b * 1.0 / top.a;
                    time -= top.b;
                    top.b = 0;
                }
            }
        }

        cout << fixed << setprecision(2) << money << endl;
        
        while (!pq.empty()) {
            pq.pop();
        }
    }
    return 0;
}