// acmoj: 2239
// 2239. 质因数分解排序法
// https://acm.sjtu.edu.cn/OnlineJudge/problem/2239
#include <iostream>
#include <algorithm>
#define N 1009
using namespace std;
int n, a[N];
int get_factor_count(int n) {
    int cnt = 0;
    for (int i = 2; i * i <= n; i ++) {
        while (n % i == 0) {
            n /= i;
            cnt += 1;
        }
        if (n == 1) break;
    }
    if (n > 1) cnt++;
    return cnt;
}
bool cmp(const int &a, const int &b) {
    if (get_factor_count(a) == get_factor_count(b)) return a < b;
    return get_factor_count(a) < get_factor_count(b);
}
int main() {
    cin >> n;
    for (int i = 0; i < n; i ++) cin >> a[i];
    sort(a, a+n, cmp);
    for (int i = 0; i < n; i ++) cout << a[i] << " ";
    return 0;
}