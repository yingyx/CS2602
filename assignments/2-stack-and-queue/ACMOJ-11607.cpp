// acmoj: 11607
// 11607. 【原1607】天真队列
// https://acm.sjtu.edu.cn/OnlineJudge/problem/11607

#include <bits/stdc++.h>
#include <vector>
#define N 2000009
using namespace std;

int n, g[N], q;
int queue_group_id[N], id_cnt, cnt;
vector<vector<int>> queues;
int queueL[N], queueR[N];
int id_queue[N], idQueueL, idQueueR = -1;

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &g[i]);
    scanf("%d", &q);
    while (q--) {
        int op;
        scanf("%d", &op);
        if (!op) {
            if (cnt >= n) continue;
            ++cnt;
            bool flg = false;
            for (int i = 0; i < id_cnt; i ++) {
                if (queue_group_id[i] == g[cnt]) {
                    queues[i].push_back(cnt);
                    ++queueR[i];
                    flg = true;
                    break;
                }
            }
            if (flg) continue;
            queue_group_id[id_cnt] = g[cnt];
            queues.push_back({});
            queues[id_cnt].push_back(cnt);
            id_queue[++idQueueR] = id_cnt;
            ++id_cnt;
        }
        else {
            if (idQueueL > idQueueR) {
                printf("-1\n");
                continue;
            }
            int head_group_id = id_queue[idQueueL];
            printf("%d\n", queues[head_group_id][queueL[head_group_id]]);
            queueL[head_group_id]++;
            if (queueL[head_group_id] > queueR[head_group_id]) { // empty
                idQueueL++;
                queue_group_id[head_group_id] = -1;
            }
        }
    }
    return 0;
}