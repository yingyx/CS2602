// acmoj: 2906
// 2906. 二叉树的直径
// https://acm.sjtu.edu.cn/OnlineJudge/problem/2906

#include <iostream>
#include <sstream>
#include <vector>
#define N 1009
using namespace std;

vector<int> val;
vector<int> e[N];
int d, dp[N];

int buildTree(int& idx) {
    if (idx >= val.size() || val[idx] == -1) {
        idx++;
        return -1;
    }
    int rootVal = val[idx++];
    int left = buildTree(idx);
    int right = buildTree(idx);
    if (left != -1) e[rootVal].push_back(left);
    if (right != -1) e[rootVal].push_back(right);
    return rootVal;
}

void dfs(int u, int fa) {
    for (int v : e[u]) {
        dfs(v, u);
        d = max(d, dp[u] + dp[v] + 1);
        dp[u] = max(dp[u], dp[v] + 1);
    }
}

int main() {
    int x;
    while (cin >> x) val.push_back(x);

    int idx = 0;
    int root = buildTree(idx);

    dfs(root, 0);
    cout << d << endl;
    return 0;
}