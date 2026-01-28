// acmoj: 2648
// 2648. 二叉树深度
// https://acm.sjtu.edu.cn/OnlineJudge/problem/2648
#include <iostream>
#define ll long long
#define N 1000009
using namespace std;

int n, child[N][2], d[N], ans;

void f(int u, int fa) {
    if (!u) return;
    d[u] = d[fa] + 1;
    if (d[u] > ans) ans = d[u];
    f(child[u][0], u);
    f(child[u][1], u);
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i ++) cin >> child[i][0] >> child[i][1];
    f(1, 0);
    cout << ans << endl;
    return 0;
}