// acmoj: 2914
#include <iostream>
#include <stack>
using namespace std;

stack<int> s;
string st;
int ans;

int str2num(string s) {
    int pm = 1;
    if (s[0] == '-') {
        pm = -1;
        s = s.substr(1);
    }
    int num = 0;
    for (int i = 0; i < s.length(); i++) {
        num *= 10;
        num += (s[i] - '0');
    }
    return pm * num;
}

int main() {
    while (cin >> st) {
        if (st[0] == '-' || ('0' <= st[0] && st[0] <= '9')) { // number
            s.push(str2num(st));
        }
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