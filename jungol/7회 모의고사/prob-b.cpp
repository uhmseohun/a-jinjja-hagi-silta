/**
 * Dynamic Programming
**/

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int _size = 1005;
int dp[_size];
char a[_size], b[_size];

char lower_to_upper(char lower) {
  return lower - 'a' + 'A';
}

bool is_lower(char target) {
  return 'a' <= target && target <= 'z';
}

bool is_upper(char target) {
  return !is_lower(target);
}

int main() {
  int tc;
  scanf("%d", &tc);
  int la, lb;
  while(tc--) {
    memset(dp, 0, sizeof(dp));
    scanf("%s %s", a + 1, b + 1);
    la = strlen(a);
    lb = strlen(b);
    for(int i=1; i<=la; ++i) {
      for(int j=i-1; j>=0; --j) {
        int curr = dp[j] + 1;
        if(is_lower(a[i]))
          dp[i] = dp[j];
        if(lower_to_upper(a[i]) == b[curr])
          dp[i] = max(dp[i], dp[j] + 1);
      }
    }
    puts(dp[lb] == lb ? "YES" : "NO");
  }
  return 0;
}
