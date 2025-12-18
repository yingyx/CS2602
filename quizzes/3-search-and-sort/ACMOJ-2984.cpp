// acmoj: 2984
#include <iostream>
#include <algorithm>
#include <vector>
#define N 100009
using namespace std;
int n;
pair<int,int> a[N];
vector<int> ans;
bool cmp(const pair<int,int> &a, const pair<int,int> &b) {
    if (a.first == b.first) return a.second < b.second;
    return a.first < b.first;
}
int main() {
    cin >> n;
    for (int i = 0; i < n; i ++) cin >> a[i].first >> a[i].second;
    if (n == 1) {
        cout << a[0].first << " " << a[0].second << endl;
        return 0;
    }
    sort(a, a + n, cmp);
    int i = 0, j = 1;
    while (i < n && j < n) {
        while (a[j].first <= a[i].second && j < n) {
            if (a[j].second > a[i].second) a[i].second = a[j].second;
            j ++;
        }
        ans.push_back(i);
        i = j;
    }
    for (int i = 0; i < ans.size(); i ++) {
        cout << a[ans[i]].first << " " << a[ans[i]].second << endl;
    }
    return 0;
}