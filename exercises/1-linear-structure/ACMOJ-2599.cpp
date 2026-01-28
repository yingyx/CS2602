// acmoj: 2599
#include <iostream>
using namespace std;

class Node {
    public:
    int val;
    Node* nxt;
    
    Node(int val) : val(val), nxt(nullptr) {}
};

int n, m;
Node *p1, *p2, *lst, *head;

int main() {
    cin >> n;
    for (int i = 0, x; i < n; i ++) {
        cin >> x;
        Node *p = new Node(x);
        if (!i) p1 = p;
        else lst->nxt = p;
        lst = p;
    }
    lst = nullptr;
    cin >> m;
    for (int i = 0, x; i < m; i ++) {
        cin >> x;
        Node *p = new Node(x);
        if (!i) p2 = p;
        else lst->nxt = p;
        lst = p;
    }

    if (p1->val < p2->val) {
        head = p1;
        lst = p1;
        p1 = p1->nxt;
    } else {
        head = p2;
        lst = p2;
        p2 = p2->nxt;
    }

    while (p1 != nullptr || p2 != nullptr) {
        if (p1 == nullptr) {
            lst->nxt = p2;
            lst = p2;
            p2 = p2->nxt;
        } else if (p2 == nullptr || p1->val < p2->val) {
            lst->nxt = p1;
            lst = p1;
            p1 = p1->nxt;
        } else {
            lst->nxt = p2;
            lst = p2;
            p2 = p2->nxt;
        }
    }

    lst = head;
    while (lst != nullptr) {
        cout << lst->val << " ";
        lst = lst->nxt;
    }

    return 0;
}