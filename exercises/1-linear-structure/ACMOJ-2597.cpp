// acmoj: 2597
#include <iostream>
#define N 1009
using namespace std;

int n, k, a[N];
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    cin >> k;
    while (k--) {
        int l, r;
        cin >> l >> r;
        l--;
        r--;
        while (l < r) {
            int tmp = a[l];
            a[l] = a[r];
            a[r] = tmp;
            ++l;
            --r;
        }
    }
    for (int i = 0; i < n; i++) cout << a[i] << " ";
    return 0;
}
