// acmoj: 2878
// 2878. 任意进制的固定宽度字符串加法（指针版）
// https://acm.sjtu.edu.cn/OnlineJudge/problem/2878

#include <bits/stdc++.h>
#define N 600
using namespace std;
int char2val(char c) {
    if ('0' <= c && c <= '9') return c - '0';
    if ('a' <= c && c <= 'z') return c - 'a' + 10;
    return c - 'A' + 10;
}
char val2char(int val) {
    if (0 <= val && val <= 9) return '0' + val;
    return 'A' + val - 10;
}
int m, n, B;
int main() {
    scanf("%d%d%d", &m, &n, &B);
    char str1[m], str2[n];
    scanf("%s%s", str1, str2);
    int len = max(m, n) - 1;
    char ans[len + 1];
    ans[len] = '\0';

    int carry = 0;
    char *p1 = str1 + m - 2, *p2 = str2 + n - 2, *p_ans = ans + max(m, n) - 2;
    for (int i = 0, carry = 0, sum; i < len; i ++) {
        int val1 = p1 ? char2val(*p1) : 0;
        int val2 = p2 ? char2val(*p2) : 0;
        sum = val1 + val2 + carry;
        carry = sum / B;
        *p_ans = val2char(sum % B);
        p_ans--;
        if (p1 > str1) p1--;
        else p1 = nullptr;
        if (p2 > str2) p2--;
        else p2 = nullptr;
    }

    printf("%s\n", ans);
    return 0;
}