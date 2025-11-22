// acmoj: 1109
// 1109. 扩展二叉树
// https://acm.sjtu.edu.cn/OnlineJudge/problem/1109

#include <iostream>
#include <sstream>
#include <vector>
#define N 100009
using namespace std;

vector<int> val;
int child[N][2];

int buildTree(int& idx) {
    if (idx >= val.size() || val[idx] == -1) {
        idx++;
        return -1;
    }
    int rootVal = val[idx++];
    int left = buildTree(idx);
    int right = buildTree(idx);
    child[rootVal][0] = left;
    child[rootVal][1] = right;
    return rootVal;
}

void inorder(int x) {
    if (x == -1) return;
    inorder(child[x][0]);
    cout << x << " ";
    inorder(child[x][1]);
}

void postorder(int x) {
    if (x == -1) return;
    postorder(child[x][0]);
    postorder(child[x][1]);
    cout << x << " "; 
}

int main() {
    string x;
    while (cin >> x) {
        if (x == ".") val.push_back(-1);
        else val.push_back(stoi(x));
    }

    int idx = 0;
    int root = buildTree(idx);

    inorder(root);
    cout << endl;
    postorder(root);

    return 0;
}