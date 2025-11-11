// acmoj: 2910
// 2910. 前缀中位数
// https://acm.sjtu.edu.cn/OnlineJudge/problem/2910
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int n;
int main() {
    cin >> n;
    priority_queue<int, vector<int>, less<int>> max_heap;
    priority_queue<int, vector<int>, greater<int>> min_heap;
    for (int i = 1, x; i <= n; i++) {
        cin >> x;
        // push element into one of the heaps
        if (max_heap.empty() || x <= max_heap.top()) max_heap.push(x);
        else min_heap.push(x);
        // adjust size
        if (max_heap.size() > min_heap.size() + 1) {
            min_heap.push(max_heap.top());
            max_heap.pop();
        } else if (min_heap.size() > max_heap.size()) {
            max_heap.push(min_heap.top());
            min_heap.pop();
        }

        if (i % 2) cout << max_heap.top() << endl;
    }
    return 0;
}