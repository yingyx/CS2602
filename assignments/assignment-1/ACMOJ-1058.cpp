// acmoj: 1058
// 1058. 小恶魔的单循环链表
// https://acm.sjtu.edu.cn/OnlineJudge/problem/1058

#include <iostream>
#include <cstdio>
using namespace std;

namespace LIST
{

    struct NODE {
        int val;
        NODE *nxt = nullptr;
    };

    NODE *head = nullptr;
    int len = 0;

    void init() {
        head = nullptr;
        len = 0;
    }

    NODE* move(int i) {
        if (!len || i < 0 || i >= len) return nullptr;
        NODE *p = head;
        while (i--) p = p->nxt;
        return p;
    }

    void insert(int i, int x) {
        NODE* p = new NODE{x, nullptr};
        if (!len) {
            p->nxt = p;
            head = p;
            len = 1;
            return;
        }
        if (!i) { // insert before head
            move(len - 1)->nxt = p;
            p->nxt = head;
            head = p;
            ++len;
            return;
        }
        NODE* pre = move(i - 1);
        p->nxt = pre->nxt;
        pre->nxt = p;
        ++len;
    }

    void remove(int i) {
        if (len == 1) {
            delete head;
            head = nullptr;
            len = 0;
            return;
        }
        if (!i) { // delete head
            move(len - 1)->nxt = head->nxt;
            NODE* tmp = head;
            head = head->nxt;
            delete tmp;
            tmp = nullptr;
            --len;
            return;
        }
        NODE *pre = move(i - 1);
        NODE *tmp = pre->nxt;
        pre->nxt = tmp->nxt;
        delete tmp;
        tmp = nullptr;
        --len;
    }

    void remove_insert(int i) {
        if (len == 0 || i < 0 || i >= len) return;
        if (len == 1) return;
        // delete
        NODE *p = nullptr;
        if (!i) { // delete head
            p = head;
            move(len - 1)->nxt = head->nxt;
            head = head->nxt;
        } else {
            NODE *pre = move(i - 1);
            p = pre->nxt;
            pre->nxt = p->nxt;
        }
        --len;
        // insert
        NODE* tail = move(len - 1);
        tail->nxt = p;
        p->nxt = head;
        ++len;
    }

    void get_length() {
        cout << len << endl;
    }

    void query(int i) {
        NODE *p = move(i);
        if (!p) cout << -1 << endl;
        else cout << p->val << endl;
    }

    void get_max() {
        if (!len) {
            cout << -1 << endl;
            return;
        }
        int maxx = 0;
        NODE *p = head;
        for (int i = 0; i < len; i++) {
            p = p->nxt;
            maxx = max(maxx, p->val);
        }
        cout << maxx << endl;
    }

    void clear() {
        if (!len) return;
        NODE *p = head->nxt;
        while (p != head) {
            NODE *tmp = p;
            p = p->nxt;
            delete tmp;
            tmp = nullptr;
        }
        delete head;
        head = nullptr;
        len = 0;
    }

}
int n;
int main()
{
    cin >> n;
    int op, x, p;
    LIST::init();
    for (int _ = 0; _ < n; ++_)
    {
        cin >> op;
        switch(op) {
            case 0:
                LIST::get_length();
                break;
            case 1:
                cin >> p >> x;
                LIST::insert(p,x);
                break;
            case 2:
                cin >> p;
                LIST::query(p);
                break;
            case 3:
                cin >> p;
                LIST::remove(p);
                break;
            case 4:
                cin >> p;
                LIST::remove_insert(p);
                break;
            case 5:
                LIST::get_max();
                break;
        }
    }
    LIST::clear();
    return 0;
}