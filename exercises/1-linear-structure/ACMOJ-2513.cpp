// acmoj: 2513
#include <iostream>
#include <stack>
using namespace std;

bool isNumber(char c) {
    return '0' <= c && c <= '9';
}

void printAndPop(stack<char> &s) {
    if (s.empty() || s.top() == '(' || s.top() == ')') return;
    cout << s.top();
    s.pop();
}

bool prioritize(char c1, char c2) {
    if ((c1 == '+' || c1 == '-') && (c2 == '*' || c2 == '/')) return false;
    if (c1 == '(' || c1 == ')' || c2 == '(' || c2 == ')') return false;
    return true;
}

stack<char> s;
char c;

int main() {
    while (cin >> c && c != '@') {
        if (isNumber(c) || c == '.') cout << c;
        else if (c == ')') {
            while (!s.empty()) {
                if (s.top() == '(') {
                    s.pop();
                    break;
                }
                printAndPop(s);
            }
        } else if (c != '(') {
            while (!s.empty() && prioritize(s.top(), c)) printAndPop(s);
            s.push(c); 
        } else { // left bracket
            s.push(c);
        }
    }

    while (!s.empty()) printAndPop(s);
    cout << '@' << endl;

    return 0;
}