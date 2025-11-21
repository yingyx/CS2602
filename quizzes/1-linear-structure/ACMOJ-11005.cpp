// acmoj: 11005
#include <bits/stdc++.h>
#define N 19
using namespace std;
int n, a[N][N];
bool vst[N];

void input_and_check() {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> a[i][j];
        }
    }
    
    // check row
    for (int i = 0; i < 9; i++) {
        memset(vst, false, sizeof(vst));
        for (int j = 0; j < 9; j++) {
            if (vst[a[i][j]]) {
                cout << "Wrong" << endl;
                return;
            }
            vst[a[i][j]] = true;
        }
    }

    // check column
    for (int j = 0; j < 9; j++) {
        memset(vst, false, sizeof(vst));
        for (int i = 0; i < 9; i++) {
            if (vst[a[i][j]]) {
                cout << "Wrong" << endl;
                return;
            }
            vst[a[i][j]] = true;
        }
    }

    // check grid
    for (int g = 0; g < 9; g++) {
        memset(vst, false, sizeof(vst));
        for (int _id = 0; _id < 9; _id++) {
            int num = a[(g % 3) * 3 + (_id % 3)][((g / 3) * 3) + (_id / 3)];
            if (vst[num]) {
                cout << "Wrong" << endl;
                return;
            }
            vst[num] = true;
        }
    }
    
    cout << "Right" << endl;
    return;
}

int main() {
    cin >> n;
    while (n--) {
        input_and_check();
    }
    return 0;
}