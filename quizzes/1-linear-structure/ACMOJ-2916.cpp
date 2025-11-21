// acmoj: 2916
#include <bits/stdc++.h>
#define N 109
using namespace std;
int T;

struct Task {
    int priority;
    int _id;
}sorted[N]; // or simply use pair<int, int>
queue<Task> q;

bool cmp(const Task &a, const Task &b) {
    return a.priority > b.priority;
}

int main() {
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        for (int i = 0, x; i < n; i ++) {
            cin >> x;
            sorted[i] = Task{x, i};
            q.push(sorted[i]);
        }
        sort(sorted, sorted+n, cmp);
        int cnt = 0;
        while (!q.empty()) {
            if (q.front().priority == sorted[cnt].priority) { // pop
                if (q.front()._id == m) {
                    cout << cnt + 1 << endl;
                    break;
                }
                q.pop();
                cnt += 1;
            } else { // move to back
                Task tmp = q.front();
                q.pop();
                q.push(tmp);
            }
        }
    }
    return 0;
}