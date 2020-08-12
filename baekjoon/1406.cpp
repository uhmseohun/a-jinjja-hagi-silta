#include <cstdio>
#include <cstring>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    char string[150000];
    scanf("%s", string);
    stack<char> left, right;
    for(int i=0; string[i]; ++i) {
        left.push(string[i]);
    }
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; ++i) {
        char command;
        scanf(" %c", &command);
        if(command == 'L') {
            if(!left.empty()) {
                right.push(left.top());
                left.pop();
            }
        } else if(command == 'D') {
            if(!right.empty()) {
                left.push(right.top());
                right.pop();
            }
        } else if(command == 'B') {
            if(!left.empty()) {
                left.pop();
            }
        } else {
            char value;
            scanf(" %c", &value);
            left.push(value);
        }
    }
    vector<char> left_chr;
    while(!left.empty()) {
        left_chr.push_back(left.top());
        left.pop();
    }
    reverse(left_chr.begin(), left_chr.end());
    for(const char chr: left_chr) {
        printf("%c", chr);
    }
    while(!right.empty()) {
        printf("%c", right.top());
        right.pop();
    }
    printf("\n");
    return 0;
}
