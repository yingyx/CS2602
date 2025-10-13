// acmoj: 2901
// 2901. 最近的更高箱子
// https://acm.sjtu.edu.cn/OnlineJudge/problem/2901

#include <bits/stdc++.h>
#define N 100009
using namespace std;
int n, h[N], st[N], ans[N];
int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &h[i]);
    st[0] = 1;
    st[1] = 0;
    for (int i = 1, top; i < n; i++) {
        top = st[*st];
        while (h[i] > h[top] && *st) {
            ans[top] = i + 1;
            --*st;
            top = st[*st];
        }
        st[++*st] = i;
    }
    for (int i = 0; i < n; i++) printf("%d ", ans[i]);
    return 0;
}