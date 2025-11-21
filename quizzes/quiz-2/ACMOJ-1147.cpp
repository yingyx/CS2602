// acmoj: 1147
#include <iostream>
#define N 1000009
using namespace std;
int n, v[N], child[N][2], ans;
bool symmetric(int l, int r) {
    if (v[l] != v[r]) return false;
    if (!l && !r) return true;
    if (!l || !r) return false;
    return symmetric(child[l][0], child[r][1]) && symmetric(child[l][1], child[r][0]);
}
int sz(int u) {
    if (!u) return 0;
    return 1 + sz(child[u][0]) + sz(child[u][1]);
}
int main() {
    cin >> n;
    for (int i = 1; i <= n; i ++) cin >> v[i];
    for (int i = 1, l, r; i <= n; i ++) {
        cin >> l >> r;
        if (l == -1) l = 0;
        if (r == -1) r = 0;
        child[i][0] = l;
        child[i][1] = r;
    }
    for (int i = 1; i <= n; i ++) {
        if (!symmetric(child[i][0], child[i][1])) continue;
        ans = max(ans, sz(i));
    }
    cout << ans << endl;
    return 0;
}