#include <stdio.h>
#include <string.h>

bool is_palindrom(char *string, int start, int end) {
    int l=start, r=end;
    while(l <= r) {
        if(string[l] != string[r]) return false;
        l++; r--;
    }
    return true;
}

bool is_pseudo_palindrom(char *string) {
    int l=0, r=strlen(string)-1;
    while(l <= r) {
        if(string[l] != string[r]) {
            if(is_palindrom(string, l+1, r)) return true;
            if(is_palindrom(string, l, r-1)) return true;
            return false;
        } else { l++; r--; }
    }
    return true;
}

int main() {
    int n;
    char string[100005];
    scanf("%d", &n);
    for(int i=0; i<n; ++i) {
        scanf("%s", string);
        int len = strlen(string);
        if(is_palindrom(string, 0, len-1)) puts("0");
        else if(is_pseudo_palindrom(string)) puts("1");
        else puts("2");
    }
    return 0;
}
