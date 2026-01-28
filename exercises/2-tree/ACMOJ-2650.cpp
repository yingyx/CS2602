// acmoj: 2650
// 2650. 二叉树营救
// https://acm.sjtu.edu.cn/OnlineJudge/problem/2650
#include <iostream>
#define N 1009
using namespace std;
int n, child[N][2], fa[N], x, y, d[N], cnt[N];
void f(int u, int fa) {
    if (!u) return;
    d[u] = d[fa] + 1;
    cnt[d[u]] += 1;
    f(child[u][0], u);
    f(child[u][1], u);
}
int main() {
    cin >> n;
    for (int i = 0, u, v; i < n - 1; i ++) {
        cin >> u >> v;
        if (child[u][0]) child[u][1] = v;
        else child[u][0] = v;
        fa[v] = u;
    }
    cin >> x >> y;
    f(1, 0);
    int depth = 0, width = 0;
    for (int i = 1; i <= n; i ++) {
        if (!cnt[i]) break;
        depth = i;
        width = max(width, cnt[i]);
    }
    cout << depth << endl << width << endl;
    int step_x = 0, step_y = 0;
    while (d[x] > d[y]) {
        x = fa[x];
        step_x ++;
    }
    while (d[y] > d[x]) {
        y = fa[y];
        step_y ++;
    }
    while (x != y) {
        x = fa[x];
        y = fa[y];
        step_x ++;
        step_y ++;
    }
    cout << step_x * 2 + step_y << endl;
    return 0;
}