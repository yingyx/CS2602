// acmoj: 2920
// 2920. 搜索出现区域
// https://acm.sjtu.edu.cn/OnlineJudge/problem/2920
#include <iostream>
#define N 10009
using namespace std;
int n, m, a[N];
int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i ++) cin >> a[i];
    int l1 = 0, r1 = n - 1, l2 = 0, r2 = n - 1;
    bool flg1 = false, flg2 = false;
    while (l1 <= r1) {
        int m1 = (l1 + r1) / 2;
        if (a[m1] == m && (m1 - 1 < 0 || a[m1 - 1] != m)) { // ok
            cout << m1 << " ";
            flg1 = true;
            break;
        }
        if (a[m1] >= m) r1 = m1 - 1; // m1 too big
        else l1 = m1 + 1;
    }
    if (!flg1) cout << -1 << " ";
    while (l2 <= r2) {
        int m2 = (l2 + r2) / 2;
        if (a[m2] == m && (m2 + 1 >= n || a[m2 + 1] != m)) { // ok
            cout << m2 << endl;
            flg2 = true;
            break;
        }
        if (a[m2] > m) r2 = m2 - 1; // m2 too big
        else l2 = m2 + 1;
    }
    if (!flg2) cout << -1 << endl;
    return 0;
}