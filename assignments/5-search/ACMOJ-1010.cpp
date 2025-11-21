// acmoj: 1010
// 1010. 逛商场
// https://acm.sjtu.edu.cn/OnlineJudge/problem/1010
#include <iostream>
#include <algorithm>
#define N 100009
using namespace std;
int n, m;
pair<int,int> c[N], ans[N];
int pre[N];
bool cmp(const pair<int,int> &a, const pair<int,int> &b) {
    return a.second < b.second;
}
int main() {
    cin >> n >> m;
    for (int i = 1, x; i <= n; i ++) {
        cin >> x;
        pre[i] = pre[i - 1] + x;
    }
    for (int i = 0, x; i < m; i ++) {
        cin >> x;
        c[i].first = i;
        c[i].second = x;
    }
    sort(c, c+m, cmp);
    for (int i = 0, j = 1; i < m; i ++) {
        while (c[i].second > pre[j]) j++;
        ans[c[i].first].first = j;
        ans[c[i].first].second = c[i].second - pre[j - 1];
    }
    for (int i = 0; i < m; i ++) cout << ans[i].first << " " << ans[i].second << endl;
    return 0;
}