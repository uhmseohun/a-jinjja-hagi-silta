#include <cstdio>
bool c[100];

int main() {
  int n, p;
  scanf("%d %d", &n, &p);
  int v = n;
  c[v] = true;
  int answer = 1;
  while(true) {
    v = (v * n) % p;
    if(c[v]) break;
    c[v] = true;
    answer++;
  }
  printf("%d\n", answer);
  return 0;
}
