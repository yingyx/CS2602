// acmoj: 2951
// 2951. 第 K 小元素
// https://acm.sjtu.edu.cn/OnlineJudge/problem/2951
#include <iostream>
#include <queue>
using namespace std;
priority_queue<int, vector<int>> q;
int n, k;
int main() {
    cin >> n >> k;
    for (int i = 0, x; i < n; i ++) {
        cin >> x;
        if (i < k) q.push(x);
        else if (x < q.top()) {
            q.pop();
            q.push(x);
        }
    }
    cout << q.top() << endl;
    return 0;
}