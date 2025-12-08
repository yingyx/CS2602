// acmoj: 2953
// 2953. 按基准值分组
// https://acm.sjtu.edu.cn/OnlineJudge/problem/2953
#include <iostream>
#define N 100009
using namespace std;
int n, p, a[N];
int l, m;
int main() {
    cin >> n >> p;
    for (int i = 0; i < n; i ++) {
        cin >> a[i];
        if (a[i] < p) {
            cout << a[i] << " ";
            l++;
        }
        if (a[i] == p) m++;
    }
    for (int i = 0; i < m; i ++) cout << p << " ";
    for (int i = 0; i < n; i ++) {
        if (a[i] > p) cout << a[i] << " ";
    }
    cout << endl;
    if (m) cout << l << " " << l + m - 1 << endl;
    else cout << "-1 -1" << endl;
    return 0;
}