// acmoj: 2975
// 2975. 省份统计
// https://acm.sjtu.edu.cn/OnlineJudge/problem/2975
#include <iostream>
#include <queue>
#define N 1009
using namespace std;
int n, vst[N], ans;
vector<int> e[N];
void bfs(int x) {
    queue<int> q;
    q.push(x);
    while (!q.empty()) {
        int top = q.front();
        q.pop();
        vst[top] = true;
        for (int i = 0; i < e[top].size(); i ++) {
            if (!vst[e[top][i]]) q.push(e[top][i]);
        }
    }
}
int main() {
    cin >> n;
    for (int i = 0; i < n; i ++) {
        for (int j = 0, x; j < n; j ++) {
            cin >> x;
            if (i != j && x) e[i].push_back(j);
        }
    }
    ans = n;
    for (int i = 0; i < n; i ++) {
        if (vst[i]) {
            ans--;
            continue;
        }
        bfs(i);
    }
    cout << ans << endl;
    return 0;
}