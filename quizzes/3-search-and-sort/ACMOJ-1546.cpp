// acmoj: 1546
#include <iostream>
#define N 100009
using namespace std;
int n, a[N];
void order(int *a, int n, int i) {
    while (true) {
        int maxChild = i * 2;
        if (maxChild > n) return;
        if (i * 2 + 1 <= n && a[i * 2 + 1] > a[i * 2]) maxChild = i * 2 + 1;
        if (a[maxChild] <= a[i]) return;
        swap(a[maxChild], a[i]);
        i = maxChild;
    }
}
int main() {
    cin >> n;
    for (int i = 1; i <= n; i ++) cin >> a[i];
    for (int i = n / 2; i >= 1; i --) order(a, n, i);
    for (int i = 1; i <= n; i ++) cout << a[i] << " ";
    cout << endl;
    for (int i = 1; i <= n; i ++) {
        swap(a[1], a[n - i + 1]);
        order(a, n - i, 1);
    }
    for (int i = 1; i <= n; i ++) cout << a[i] << " ";
    return 0;
}