// acmoj: 2974
// 2974. 连锁炸弹
// https://acm.sjtu.edu.cn/OnlineJudge/problem/2974
#include <iostream>
#include <queue>
#define N 309
using namespace std;
int n;
long long x[N], y[N], r[N];
bool e[N][N], vst[N];
int bfs(int i) {
    fill(vst, vst + N, false);
    queue<int> q;
    q.push(i);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        vst[u] = true;
        for (int v = 0; v < n; v++) {
            if (!vst[v] && e[u][v]) q.push(v);
        }
    }
    int cnt = 0;
    for (int i = 0; i < n; i ++) cnt += vst[i];
    return cnt;
}
int main() {
    cin >> n;
    for (int i = 0; i < n; i ++) cin >> x[i] >> y[i] >> r[i];
    for (int i = 0; i < n; i ++) {
        for (int j = i + 1; j < n; j ++) {
            long long sq_dis = (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]);
            if (sq_dis <= r[i] * r[i]) e[i][j] = true;
            if (sq_dis <= r[j] * r[j]) e[j][i] = true;
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i ++) ans = max(ans, bfs(i));
    cout << ans << endl;
    return 0;
}