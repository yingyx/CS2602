// acmoj: 2914
#include <iostream>
#include <stack>
using namespace std;

stack<int> s;
string st;
int ans;

int main() {
    while (cin >> st) {
        if (st[0] == '-' || ('0' <= st[0] && st[0] <= '9')) s.push(stoi(st)); // number
        else if (st[0] == 'C') s.pop();
        else if (st[0] == 'D') s.push(s.top() * 2);
        else if (st[0] == '+') {
            int tmp = s.top();
            s.pop();
            int sum = tmp + s.top();
            s.push(tmp);
            s.push(sum);
        }
    }
    while (!s.empty()) {
        ans += s.top();
        s.pop();
    }
    cout << ans << endl;
    return 0;
}