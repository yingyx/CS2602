// acmoj: 2885
// 2885. 另一棵树的子树
// https://acm.sjtu.edu.cn/OnlineJudge/problem/2885

#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

vector<int> val1, val2;

bool checkSubTree(int idx1, int idx2) {
    if (idx1 >= val1.size() && idx2 >= val2.size()) return true;
    if (idx1 >= val1.size() || idx2 >= val2.size()) return false;
    if (val1[idx1] != val2[idx2]) return false;
    return checkSubTree(idx1 * 2 + 1, idx2 * 2 + 1) && checkSubTree(idx1 * 2 + 2, idx2 * 2 + 2);
}

int main() {
    string line1, line2;
    getline(cin, line1);
    getline(cin, line2);
    stringstream ss1(line1), ss2(line2);

    int x;
    while (ss1 >> x) val1.push_back(x);
    while (ss2 >> x) val2.push_back(x);

    for (int i = 0; i < val1.size(); i++) {
        if (checkSubTree(i, 0)) {
            cout << "true" << endl;
            return 0;
        }
    }
    cout << "false" << endl;
    return 0;
}