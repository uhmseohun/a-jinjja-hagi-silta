#include <cstdio>
#include <cstring>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

void output(stack<char> side) {
    vector<char> answer;
    while(!side.empty()) {
        answer.push_back(side.top());
        side.pop();
    }
    reverse(answer.begin(), answer.end());
    for(const char ch: answer) {
        printf("%c", ch);
    }
}

int main() {
    int n;
    scanf("%d", &n);
    while(n--) {
        char string[1000005];
        stack<char> left, right;
        scanf("%s", string);
        int len = strlen(string);
        for(int i=0; i<len; ++i) {
            if(string[i] == '<') {
                if(!left.empty()) {
                    right.push(left.top());
                    left.pop();
                }
            } else if(string[i] == '>') {
                if(!right.empty()) {
                    left.push(right.top());
                    right.pop();
                }
            } else if(string[i] == '-') {
                if(!left.empty()) left.pop();
            } else {
                left.push(string[i]);
            }
        }

        vector<char> reversed_left;
        while(!left.empty()) {
            reversed_left.push_back(left.top());
            left.pop();
        }
        reverse(reversed_left.begin(), reversed_left.end());
        for(const char ch: reversed_left) {
            printf("%c", ch);
        }
        while(!right.empty()) {
            printf("%c", right.top());
            right.pop();
        }
        puts("");
    }
    return 0;
}
