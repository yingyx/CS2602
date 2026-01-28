// acmoj: 1108
// 1108. 二叉树遍历(flist)
// https://acm.sjtu.edu.cn/OnlineJudge/problem/1108
#include <iostream>
using namespace std;
string mid, layer;
string f(string mid, string layer) {
    if (mid.empty()) return "";
    string left = mid.substr(0, mid.find(layer[0]));
    string right = mid.substr(mid.find(layer[0]) + 1);
    string left_layer = "", right_layer = "";
    for (int i = 1; i < layer.size(); i ++) {
        if (left.find(layer[i]) != string::npos) left_layer += layer[i];
        if (right.find(layer[i]) != string::npos) right_layer += layer[i];
    }
    return layer[0] + f(left, left_layer) + f(right, right_layer);
}
int main() {
    cin >> mid >> layer;
    cout << f(mid, layer) << endl;
    return 0;
}