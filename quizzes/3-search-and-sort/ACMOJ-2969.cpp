// acmoj: 2969
#include <iostream>
#include <map>
#define N 1009
using namespace std;
int n, k;
map<int,int> lst;
int main() {
    cin >> n >> k;
    for (int i = 1, x; i <= n; i ++) {
        cin >> x;
        if (lst[x] && i - lst[x] <= k) {
            cout << "true" << endl;
            return 0;
        }
        lst[x] = i;
    }
    cout << "false" << endl;
    return 0;
}