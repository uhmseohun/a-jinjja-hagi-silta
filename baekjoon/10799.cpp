#include <cstdio>
#include <cstring>
#include <stack>
#include <vector>
using namespace std;
typedef pair<int, int> ipair;

int main() {
    char string[100005];
    stack<int> bracket;
    vector<ipair> steels;
    scanf("%s", string);
    int len = strlen(string), answer = 0;
    for(int i=0; i < len; ++i) {
        if(string[i] == '(' && string[i+1] == ')') {
            answer += bracket.size();
            i++;
        } else if(string[i] == '(') {
            bracket.push(i);
        } else if(string[i] == ')') {
            steels.push_back(make_pair(bracket.top(), i));
            bracket.pop();
        }
    }
    printf("%d\n", answer + steels.size());
    return 0;
}
