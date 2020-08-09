#include <cstdio>
#include <vector>
#include <set>
using namespace std;
const int _size = 100005;
int n, k, m[_size];
multiset< int, greater<int> > s1;
multiset< int, less<int> > s2;

int main() {
    scanf("%d %d", &n, &k);
    for(int i=0; i<n; ++i) {
        scanf("%d", &m[i]);
    }
    for(int i=0; i<k; ++i) {
        s1.insert(m[i]);
        s2.insert(m[i]);
    }
    int ans = (*s1.begin()) * (*s2.begin());
    for(int i=k; i<n; ++i) {
        s1.erase(s1.find(m[i-k]));
        s2.erase(s2.find(m[i-k]));
        s1.insert(m[i]);
        s2.insert(m[i]);
        ans = max(ans, (*s1.begin()) * (*s2.begin()));
    }
    printf("%d\n", ans);
    return 0;
}

