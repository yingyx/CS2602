// acmoj: 2598
#include <iostream>
#define N 209
using namespace std;

int n, a[N], x;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    cin >> x;
    for (int i = 0; i < n; i++) {
        if (a[i] < x) cout << a[i] << " ";
    }
    for (int i = 0; i < n; i++) {
        if (a[i] >= x) cout << a[i] << " ";
    }
    return 0;
}