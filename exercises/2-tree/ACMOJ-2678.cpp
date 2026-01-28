// acmoj: 2678
// 2678. 最大路径和
// https://acm.sjtu.edu.cn/OnlineJudge/problem/2678
#include <iostream>
#define ll long long
#define N 100009
using namespace std;

int n, child[N][2];
ll w[N], sum[N], ans = -1e10;

void f(int u, int fa) {
    if (!u) return;
    sum[u] = sum[fa] + w[u];
    if (sum[u] > ans) ans = sum[u];
    f(child[u][0], u);
    f(child[u][1], u);
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i ++) cin >> child[i][0] >> child[i][1];
    for (int i = 1; i <= n; i ++) cin >> w[i];
    f(1, 0);
    cout << ans << endl;
    return 0;
}