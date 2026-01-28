// acmoj: 2679
// 2679. 魔法森林
// https://acm.sjtu.edu.cn/OnlineJudge/problem/2679

#include <iostream>
#define N 1000009
using namespace std;
int n, child[N][2];
int depth[N], subDepth[N], otherDepth[N];
// depth[i]: depth of node i
// subdepth[i]: max depth of leaves in subtree i
// otherdepth[i]: max depth of leaves excluding those in subtree i
void f(int u, int fa) {
    if (!u) return;
    depth[u] = depth[fa] + 1;
    f(child[u][0], u);
    f(child[u][1], u);
}
int g(int u) {
    if (!u) return 0;
    if (!child[u][0] && !child[u][1]) return depth[u]; // leaf
    subDepth[u] = max(g(child[u][0]), g(child[u][1]));
    return subDepth[u];
}
void h(int u) {
    if (!u) return;
    otherDepth[child[u][0]] = max(depth[u], max(otherDepth[u], subDepth[child[u][1]]));
    otherDepth[child[u][1]] = max(depth[u], max(otherDepth[u], subDepth[child[u][0]]));
    h(child[u][0]);
    h(child[u][1]);
}
int main() {
    cin >> n;
    for (int i = 1; i <= n; i ++) cin >> child[i][0] >> child[i][1];
    
    f(1, 0); // compute depth
    g(1); // compute subtree depth
    h(1); // compute other depth
    
    // find shallowest leaf and deepest leaf
    // if subtree i contains a shallowest leaf,
    // apparently moving subtree i won't do any good
    // because node i is shallower than any leaf
    // so we just take the leaves of subtree i into account for convenience
    int minDepth = N, maxDepth = 0;
    for (int i = 1; i <= n; i ++) {
        if (!child[i][0] && !child[i][1]){ 
            if (depth[i] < minDepth) minDepth = depth[i];
            if (depth[i] > maxDepth) maxDepth = depth[i];
        }
    }

    // find answer
    int ans = maxDepth;
    for (int i = 2; i <= n; i ++) { // do not move root
        // try to move subtree i to the shallowest leaf
        if (!otherDepth[i]) continue; // do not move if all leaves are in this subtree
        ans = min(ans, max(minDepth + subDepth[i] - depth[i] + 1, otherDepth[i]));
    }

    cout << ans << endl;
    return 0;
}