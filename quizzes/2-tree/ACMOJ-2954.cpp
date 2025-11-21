// acmoj: 2954
#include <iostream>
#define N 109
using namespace std;
int n, child[N][2], d[N], cnt[N], maxd, node[N];
void f(int u, int fa) {
    if (!u) return;
    d[u] = d[fa] + 1;
    cnt[d[u]] += 1;
    maxd = max(d[u], maxd);
    f(child[u][0], u);
    f(child[u][1], u);
}
int main() {
    cin >> n;
    for (int i = 1, x, y, z; i <= n; i ++) {
        cin >> x >> y >> z;
        if (y == -1) y = 0;
        if (z == -1) z = 0;
        child[x][0] = y;
        child[x][1] = z;
        node[i] = x;
    }
    f(1, 0);
    for (int i = 1; i <= maxd - 1; i ++) {
        if (cnt[i] != (1 << (i - 1))) {
            cout << "false" << endl;
            return 0;
        }
    }
    int lcnt = 0;
    for (int i = 1; i <= n; i ++) {
        if (d[node[i]] != maxd - 1) continue;
        for (int c = 0; c < 2; c ++) {
            if (child[node[i]][c]) lcnt += 1;
            else if (lcnt < cnt[maxd]) {
                cout << "false" << endl;
                return 0;
            }
        }
        if (lcnt == cnt[maxd]) break;
    }
    cout << "true" << endl;
    return 0;
}