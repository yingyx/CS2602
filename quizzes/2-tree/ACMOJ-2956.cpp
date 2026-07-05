// acmoj: 2956
#include <iostream>
#include <queue>
#include <vector>
#include <string>
using namespace std;

struct Node {
    long long val;
    Node *lson, *rson;
} *root;

string s;
vector<string> a, output;

Node* newNode(string s) {
    if (s == "null") return nullptr;
    return new Node{stoll(s), nullptr, nullptr};
}

void build() {
    if (a.empty()) return;

    root = newNode(a[0]);
    if (!root) return;

    queue<Node*> q;
    q.push(root);

    int idx = 1;
    while (!q.empty() && idx < a.size()) {
        Node *u = q.front();
        q.pop();

        if (idx < a.size()) {
            u->lson = newNode(a[idx++]);
            if (u->lson) q.push(u->lson);
        }

        if (idx < a.size()) {
            u->rson = newNode(a[idx++]);
            if (u->rson) q.push(u->rson);
        }
    }
}

void calc() {
    if (!root) return;

    queue<Node*> q;
    q.push(root);
    root->val = 0;

    while (!q.empty()) {
        int sz = q.size();
        vector<Node*> layer;
        long long sum = 0;

        for (int i = 0; i < sz; i++) {
            Node *u = q.front();
            q.pop();
            layer.push_back(u);

            if (u->lson) sum += u->lson->val;
            if (u->rson) sum += u->rson->val;
        }

        for (Node *u : layer) {
            long long sonSum = 0;

            if (u->lson) sonSum += u->lson->val;
            if (u->rson) sonSum += u->rson->val;

            if (u->lson) {
                u->lson->val = sum - sonSum;
                q.push(u->lson);
            }

            if (u->rson) {
                u->rson->val = sum - sonSum;
                q.push(u->rson);
            }
        }
    }
}

void print() {
    if (!root) return;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node *u = q.front();
        q.pop();

        if (!u) {
            output.push_back("null");
            continue;
        }

        output.push_back(to_string(u->val));
        q.push(u->lson);
        q.push(u->rson);
    }

    while (!output.empty() && output.back() == "null") {
        output.pop_back();
    }

    for (int i = 0; i < output.size(); i++) {
        if (i) cout << " ";
        cout << output[i];
    }
}

int main() {
    while (cin >> s) {
        a.push_back(s);
    }

    build();
    calc();
    print();

    return 0;
}