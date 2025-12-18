// acmoj: 2956
#include <iostream>
#include <queue>
#define N 100009
using namespace std;
string s;
struct Node {
    int val;
    int ans;
    int depth;
    Node *lson, *rson;
} *root;
queue<Node*> q;
vector<string> output;
int sum[N];
void f(Node *u, Node *fa) { // calc depth and layer sum
    if (!u || !u->val) return;
    if (!fa) u->depth = 1;
    else u->depth = fa->depth + 1;
    sum[u->depth] += u->val;
    f(u->lson, u);
    f(u->rson, u);
}
void g(Node *u, Node *fa) {
    if (!u || !u->val) return;
    u->ans = sum[u->depth] - ((fa && fa->lson) ? fa->lson->val : 0) - ((fa && fa->rson) ? fa->rson->val : 0);
    if (!fa) u->ans = 0;
    g(u->lson, u);
    g(u->rson, u);
}
int main() {
    while (cin >> s) {
        int num = (s == "null" ? 0 : stoi(s));
        Node *son = new Node{num, 0, 1, nullptr, nullptr};
        if (!q.empty()) {
            if (!q.front()->lson) q.front()->lson = son;
            else {
                q.front()->rson = son;
                q.pop();
            }
        } else root = son;
        if (num) q.push(son);
    }
    f(root, nullptr);
    g(root, nullptr);
    while (!q.empty()) q.pop();
    q.push(root);
    while (!q.empty()) {
        Node *u = q.front();
        q.pop();
        if (!u) continue;
        output.push_back(u->val ? to_string(u->ans) : "null");
        q.push(u->lson);
        q.push(u->rson);
    }
    while (output.back() == "null") output.pop_back(); // gets 10 points, ???
    for (string &s : output) cout << s << " ";
    return 0;
}