// acmoj: 2946
// 2946. 验证二叉查找树
// https://acm.sjtu.edu.cn/OnlineJudge/problem/2946
#include <iostream>
#define N 1009
using namespace std;
int a[N], n;
bool ok(int u, int lower, int upper) {
    if (u > n || a[u] == -1) return true;
    return (lower == -1 || a[u] > lower)
     && (upper == -1 || a[u] < upper)
     && ok(2 * u, lower, upper == -1 ? a[u] : min(upper, a[u]))
     && ok(2 * u + 1, lower == -1 ? a[u] : max(lower, a[u]), upper);
}
int main() {
    fill(a, a + N, -1);
    string s;
    while (cin >> s) {
        while (n && a[(n + 1) / 2] == -1) n++;
        a[++n] = stoi(s);
    }
    cout << (ok(1, -1, -1) ? "true" : "false") << endl;
    return 0;
}