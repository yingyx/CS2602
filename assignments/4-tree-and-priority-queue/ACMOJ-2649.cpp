// acmoj: 2649
// 2649. 最近公共祖先（LCA）
// https://acm.sjtu.edu.cn/OnlineJudge/problem/2649

#include <iostream>
#define N 1009
using namespace std;
int child[N][2], parent[N], depth[N];
int n, x, y;
void dfs(int p, int d) {
    depth[p] = d;
    if (child[p][0]) dfs(child[p][0], d + 1);
    if (child[p][1]) dfs(child[p][1], d + 1);
}
int main() {
    cin >> n >> x >> y;
    for(int i = 1, a, b; i <= n; i ++) {
        cin >> a >> b;
        child[i][0] = a;
        child[i][1] = b;
        parent[a] = i;
        parent[b] = i;
    }
    // find root
    int p = 1;
    while (parent[p]) p = parent[p];
    // compute depth
    dfs(p, 0);
    // move to same depth
    while (depth[x] > depth[y] && parent[x]) x = parent[x];
    while (depth[y] > depth[x] && parent[y]) y = parent[y];
    // go up together
    while (x != y && parent[x] && parent[y]) {
        x = parent[x];
        y = parent[y];
    }
    cout << x << endl;
    return 0;
}