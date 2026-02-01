// acmoj: 1054
// 1054. 图的遍历 Hard
// https://acm.sjtu.edu.cn/OnlineJudge/problem/1054
#include <iostream>
#include <vector>
#include <stack>
#define N 100009
using namespace std;
int n, m;
vector<int> e[N], e_scc[N];
stack<int> st;
bool inst[N];
int cnt, low[N], dfn[N];
int cnt_scc, scc[N], max_id[N], ans[N];
void tarjan(int u) {
    cnt++;
    st.push(u);
    inst[u] = true;
    dfn[u] = cnt; 
    low[u] = cnt;
    for(int v : e[u]) {
        if (!dfn[v]) {
            tarjan(v);
            low[u] = min(low[u], low[v]);
        } else if (inst[v]) low[u] = min(low[u], dfn[v]);
    }
    if (dfn[u] == low[u]) {
        cnt_scc++;
        while (true) {
            int x = st.top(); st.pop();
            inst[x] = false;
            scc[x] = cnt_scc;
            max_id[cnt_scc] = max(max_id[cnt_scc], x);
            if (x == u) break;
        }
    }
}
int dfs(int u) {
    if (ans[u]) return ans[u];
    ans[u] = max_id[u];
    for (int v : e_scc[u]) ans[u] = max(ans[u], dfs(v));
    return ans[u];
}
int main() {
    cin >> n >> m;
    while (m--) {
        int u, v;
        cin >> u >> v;
        e[u].push_back(v);
    }
    for (int i = 1; i <= n; i ++) {
        if(!dfn[i]) tarjan(i);
    }
    for (int i = 1; i <= n; i ++) {
        for(int v : e[i]) {
            if (scc[i] != scc[v]) e_scc[scc[i]].push_back(scc[v]);
        }
    }
    for (int i = 1; i <= cnt_scc; i ++) {
        if (!ans[i]) dfs(i);
    }
    for (int i = 1; i <= n; i ++) cout << ans[scc[i]] << " ";
    return 0;
}