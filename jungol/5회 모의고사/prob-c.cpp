//
//  main.cpp
//  algorithm
//
//  Created by 엄서훈 on 2020/08/20.
//

#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
const int _size = 100005;
int n;
vector<int> u[_size];
bool c[_size];

int longest_node(int src) {
    memset(c, false, sizeof(c));
    queue<int> q;
    q.push(src);
    c[src] = true;
    int f = 1;
    while(!q.empty()) {
        f = q.front();
        q.pop();
        for(int k: u[f]) {
            if(c[k]) continue;
            q.push(k);
            c[k] = true;
        }
    }
    return f;
}

int p[2][_size];

void dfs(int node, int type) {
    for(int k: u[node]) {
        if(c[k]) continue;
        c[k] = true;
        p[type][k] = node;
        dfs(k, type);
    }
}

void generate_tree(int root, int type) {
    memset(c, false, sizeof(c));
    p[type][root] = 0;
    c[root] = true;
    dfs(root, type);
}

int d[2][_size][20];

void generate_table(int type) {
    for(int i=1; i<=n; ++i) {
        d[type][i][0] = p[type][i];
    }
    for(int j=1; j<20; ++j) {
        for(int i=1; i<=n; ++i) {
            int val = d[type][i][j-1];
            val = d[type][val][j-1];
            d[type][i][j] = val;
        }
    }
}

int get_parent_node(int type, int src, int dist) {
    int node = src, i;
    for(i=0; dist; ++i, dist>>=1) {
        if(!(dist & 1)) continue;
        node = d[type][node][i];
        if(!node) return -1;
    }
    return node;
}

int main() {
    int a, b;
    scanf("%d", &n);
    for(int i=0; i<n-1; ++i) {
        scanf("%d %d", &a, &b);
        u[a].push_back(b);
        u[b].push_back(a);
    }
    int la = longest_node(1);
    int lb = longest_node(la);
    generate_tree(la, 0);
    generate_table(0);
    generate_tree(lb, 1);
    generate_table(1);
    
    int q;
    scanf("%d", &q);
    int s, w;
    for(int i=0; i<q; ++i) {
        scanf("%d %d", &s, &w);

        int res = max(
            get_parent_node(0, s, w),
            get_parent_node(1, s, w)
        );
        printf("%d\n", res);
    }
    return 0;
}
