#include <cstdio>
#include <algorithm>
using namespace std;
const int _size = 100005;
int n, k, m[_size];
int max_tree[_size*3], min_tree[_size*3];

void build(int idx, int s, int e) {
    if(s == e) {
        max_tree[idx] = m[s];
        min_tree[idx] = m[s];
        return;
    }
    int m = (s + e) / 2;
    int lch = idx*2+1, rch = idx*2+2;
    build(lch, s, m);
    build(rch, m+1, e);
    max_tree[idx] = max(max_tree[lch], max_tree[rch]);
    min_tree[idx] = min(min_tree[lch], min_tree[rch]);
}

int min_query(int idx, int s, int e, int qs, int qe) {
    if(qs <= s && e <= qe) return min_tree[idx];
    if(e < qs || qe < s) return 10000;
    int lch = idx*2+1, rch = idx*2+2;
    int m = (s + e) / 2;
    int lv = min_query(lch, s, m, qs, qe);
    int rv = min_query(rch, m+1, e, qs, qe);
    return min(lv, rv);
}

int max_query(int idx, int s, int e, int qs, int qe) {
    if(qs <= s && e <= qe) return max_tree[idx];
    if(e < qs || qe < s) return 0;
    int lch = idx*2+1, rch = idx*2+2;
    int m = (s + e) / 2;
    int lv = max_query(lch, s, m, qs, qe);
    int rv = max_query(rch, m+1, e, qs, qe);
    return max(lv, rv);
}

int main() {
    scanf("%d %d", &n, &k);
    for(int i=0; i<n; ++i) {
        scanf("%d", &m[i]);
    }
    build(0, 0, n-1);
    int ans = 0;
    for(int i=0; i+k-1<n; ++i) {
        int minv = min_query(0, 0, n-1, i, i+k-1);
        int maxv = max_query(0, 0, n-1, i, i+k-1);
        ans = max(ans, minv*maxv);
    }
    printf("%d\n", ans);
    return 0;
}

