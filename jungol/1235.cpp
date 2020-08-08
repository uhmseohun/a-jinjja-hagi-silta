#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
typedef pair<int, int> ipair;
const int _size = 105;
int n, d[_size][_size];
bool m[_size];
int h[_size][_size];
ipair p[_size][_size];
vector<ipair> x;

void trace(int s, int e) {
    x.push_back(make_pair(s, e));
    if(e - s == 1) return;
    ipair t = p[s][e];
    if(s + 1 == t.first) {
        trace(s+1, e-1);
    } else {
        x.pop_back();
        trace(s, t.second);
        trace(t.second+1, e);
    }
}

int main() {
    scanf("%d", &n);
    int v;
    for(int i=0; i<n; ++i) {
        scanf("%1d", &v);
        m[i] = bool(v);
    }
    for(int i=0; i<_size; ++i) {
        for(int j=0; j<_size; ++j) {
            d[i][j] = 10000000;
            h[i][j] = 10000000;
        }
    }
    for(int k=1; k<n; k+=2) {
        for(int i=0; i+k<n; ++i) {
            if(m[i] != m[i+k]) {
                if(k == 1) d[i][i+k]=3, h[i][i+k]=1;
                else {
                    h[i][i+k] = h[i+1][i+k-1] + 1;
                    d[i][i+k] = d[i+1][i+k-1] + k + h[i][i+k] * 2;
                    p[i][i+k] = make_pair(i+1, i+k-1);
                }
            }

            for(int j=i+1; j<i+k; j+=2) {
                int v = d[i][j] + d[j+1][i+k];
                if(v < d[i][i+k]) {
                    d[i][i+k] = v;
                    h[i][i+k] = max(h[i][j], h[j+1][i+k]);
                    p[i][i+k] = make_pair(i, j);
                }
            }
        }
    }
    printf("%d\n", d[0][n-1]);
    trace(0, n-1);
    sort(x.begin(), x.end());
    for(ipair u: x) {
        printf("%d %d\n", u.first+1, u.second+1);
    }
    return 0;
}
