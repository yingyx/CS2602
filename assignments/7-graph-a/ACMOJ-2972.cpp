// acmoj: 2972
// 2972. 寻找小镇法官
// https://acm.sjtu.edu.cn/OnlineJudge/problem/2972
#include <iostream>
#define N 5009
using namespace std;
int n, m;
bool e[N][N], not_judge[N];
int main() {
    cin >> n >> m;
    while (m--) {
        int a, b;
        cin >> a >> b;
        e[a][b] = true;
        not_judge[a] = true;
    }
    for (int i = 1; i <= n; i ++) {
        if (not_judge[i]) continue;
        bool flg = true;
        for (int j = 1; j <= n; j ++) {
            if (j != i && !e[j][i]) {
                flg = false;
                break;
            }
        }
        if (flg) {
            cout << i << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}