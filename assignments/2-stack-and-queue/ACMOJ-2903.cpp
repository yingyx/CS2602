// acmoj: 2903
// 2903. 智能家居温度监测
// https://acm.sjtu.edu.cn/OnlineJudge/problem/2903

#include <bits/stdc++.h>
using namespace std;
#define N 1009
int n, q, t[N];
int main(){
    scanf("%d%d", &n, &q);
    for (int i = 0; i < q; i++) scanf("%d", &t[i]);
    for (int i = 0, sum = 0; i < q; i++) {
        sum += t[i];
        if (i >= n) sum -= t[i - n];
        printf("%d\n", sum / min(i + 1, n));
    }
    return 0;
}