// acmoj: 2973
// 2973. 课程安排
// https://acm.sjtu.edu.cn/OnlineJudge/problem/2973
#include <iostream>
#include <queue>
#define N 100009
using namespace std;
int n, m, in[N];
vector<int> e[N];
queue<int> q;
int main() {
    cin >> n >> m;
    for (int i = 0, a, b; i < m; i ++) {
        cin >> a >> b;
        e[a].push_back(b);
        in[b]++;
    }
    int cnt = 0;
    for (int i = 0; i < n; i ++) {
        if (!in[i]) q.push(i);
    }
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        cnt++;
        for (int i = 0; i < e[u].size(); i ++) {
            int v = e[u][i];
            if (--in[v] == 0) q.push(v);
        }
    }
    cout << (cnt == n ? "true" : "false") << endl;
    return 0;
}