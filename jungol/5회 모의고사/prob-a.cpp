#include <cstdio>
#include <algorithm>
using namespace std;
const int _size = 705;
 
int n, m, h[_size][_size];
bool c[_size][_size];
const int xx[] = { -1, 0, 1, 0 };
const int yy[] = { 0, 1, 0, -1 };
 
int fr, re;
struct Data{
    int x, y, a;
} que[_size*_size];
 
void init() {
    fr = 0;
    re = 0;
    for(int i=0; i<_size; ++i) {
        for(int j=0; j<_size; ++j) {
            c[i][j] = false;
        }
    }
}
 
void push(int x, int y, int a) {
    c[x][y] = true;
    que[re++] = Data({ x, y, a });
}
 
bool is_available(int max_height) {
    init();
    if(max_height < h[0][0]) return false;
    push(0, 0, h[0][0]);
    while(fr <= re) {
        Data k = que[fr++];
        for(int i=0; i<4; ++i) {
            int mx=k.x+xx[i];
            int my=k.y+yy[i];
            if(mx<0 || my<0 || mx>=n || my>=m) continue;
            if(c[mx][my]) continue;
            int ma=max(k.a, h[mx][my]);
            if(max_height < ma) continue;
            push(mx, my, ma);
            if(mx==n-1 && my==m-1) return true;
        }
    }
    return false;
}
 
int main() {
    scanf("%d %d", &n, &m);
    int s = 100000005, e = 0;
    for(int i=0; i<n; ++i) {
        for(int j=0; j<m; ++j) {
            scanf("%d", &h[i][j]);
            s = min(s, h[i][j]);
            e = max(e, h[i][j]);
        }
    }
    int ans = e;
    while(s <= e) {
        int m = (s+e)/2;
        if(is_available(m)) {
            e = m - 1;
            ans = min(ans, m);
        } else {
            s = m + 1;
        }
    }
    printf("%d\n", ans);
    return 0;
}

