// acmoj: 2913
// 2913. 二叉树的遍历 (post)
// https://acm.sjtu.edu.cn/OnlineJudge/problem/2913

#include <iostream>
using namespace std;
string pre, mid;
void f(string pre, string mid) {
    if (!pre.length()) return;
    if (pre.length() == 1) {
        cout << pre;
        return;
    }
    char root = pre[0];
    int len_l = mid.find(root);
    f(pre.substr(1, len_l), mid.substr(0, len_l)); // left subtree
    f(pre.substr(len_l + 1), mid.substr(len_l + 1)); // right subtree
    cout << root;
}
int main() {
    cin >> pre;
    cin >> mid;
    f(pre, mid);
    return 0;
}