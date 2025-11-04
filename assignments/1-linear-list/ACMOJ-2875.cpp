// 2875. 顺序表插入与删除
// https://acm.sjtu.edu.cn/OnlineJudge/problem/2875

#include <bits/stdc++.h>
using namespace std;

struct Node {
    Node *nxt;
    int num;
};

int n, m, len;

int main() {
    scanf("%d", &n);
    len = n;
    Node *pre = nullptr, *head = nullptr;
    for (int i = 0, x; i < n; i++) {
        scanf("%d", &x);
        Node *newNode = new Node{nullptr, x};
        if (!i) head = newNode;
        if (pre != nullptr) pre->nxt = newNode;
        pre = newNode;
    }
    scanf("%d", &m);
    for (int i = 0, pos, x; i < m; i ++) {
        char op;
        scanf(" %c", &op);
        if (op == 'I') {
            scanf("%d%d", &pos, &x);
            if (pos < 1 || pos > len + 1) continue;
            Node *p = head, *newNode = new Node{nullptr, x};
            if (pos == 1) {
                newNode->nxt = head;
                head = newNode;
            } else {
                for (int j = 1; j < pos - 1; j++) p = p->nxt;
                newNode->nxt = p->nxt;
                p->nxt = newNode;
            }
            len ++;
        } else if (op == 'D') {
            scanf("%d", &pos);
            if (pos < 1 || pos > len) continue;
            if (pos == 1) {
                Node* tmp = head;
                head = head->nxt;
                delete tmp;
            } else {
                Node* p = head;
                for (int j = 1; j < pos - 1; j++) p = p->nxt;
                Node* tmp = p->nxt;
                p->nxt = tmp->nxt;
                delete tmp;
            }
            len--;
        }
    }
    if (!head) {
        puts("EMPTY");
    } else {
        Node *p = head;
        while (p) {
            printf("%d ", p->num);
            p = p->nxt;
        }
    }
    return 0;
}
