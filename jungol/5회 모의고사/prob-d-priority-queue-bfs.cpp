#include <cstdio>
#include <queue>
using namespace std;
const int _size = 605;
int n, m, mat[_size][_size];
int minl[_size][_size];
const int xx[] = { -1, 0, 1, 0 };
const int yy[] = { 0, 1, 0, -1 };

struct L{
    int x, y, l;
    bool operator < (const L &r) const {
        return l > r.l;
    }
};

int main() {
    scanf("%d %d", &n, &m);
    char t;
    for(int i=0; i<n; ++i) {
        for(int j=0; j<m; ++j) {
           scanf(" %c", &t);
           minl[i][j] = _size * _size;
           if(t == '^') mat[i][j] = 0;
           if(t == '>') mat[i][j] = 1;
           if(t == 'v') mat[i][j] = 2;
           if(t == '<') mat[i][j] = 3;
        }
    }
    priority_queue<L> pq;
    pq.push(L({ 0, 0, 0 }));
    while(!pq.empty()) {
        const auto t = pq.top();
        pq.pop();
        if(t.x == n-1 && t.y == m-1) break;
        for(int i=0; i<4; ++i) {
            int mx = t.x + xx[i];
            int my = t.y + yy[i];
            if(mx < 0 || my < 0) continue;
            if(n <= mx || m <= my) continue;
            int ml = t.l + (i != mat[t.x][t.y]);
            if(minl[mx][my] <= ml) continue;
            minl[mx][my] = ml;
            pq.push(L({ mx, my, ml }));
        }
    }
    printf("%d\n", minl[n-1][m-1]);
    return 0;
}

