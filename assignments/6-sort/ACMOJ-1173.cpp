// acmoj: 1173
// 1173. 一道排序题
// https://acm.sjtu.edu.cn/OnlineJudge/problem/1173
#include <iostream>
#include <algorithm>
#define ll long long
#define N 100009
using namespace std;
int n, a[N], b[N];
ll ans_min, ans_max;
int main() {
    cin >> n;
    for (int i = 0; i < n; i ++) cin >> a[i];
    for (int i = 0; i < n; i ++) cin >> b[i];
    sort(a, a + n);
    sort(b, b + n);
    for (int i = 0; i < n; i ++) {
        ans_max += 1LL * a[i] * b[i];
        ans_min += 1LL * a[i] * b[n - i - 1];
    }
    cout << ans_max << " " << ans_min << endl;
    return 0;
}