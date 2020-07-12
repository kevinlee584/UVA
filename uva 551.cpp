#include <iostream>
#include <stack>
#include <cstdio>
#include <cstring>
#include <fstream>

using namespace std;

bool IsOpening(char c){
    return c=='('||c=='{'||c=='['||c=='<';
}
bool IsClosing(char c){
    return c==')'||c=='}'||c==']'||c=='>';
}

int main()
{
    stack<char> checker;
    string s;
    while(getline(cin,s)){
        int i, len = s.length();
        int count = 0;

        for(i=0;i<len;++i){
            count++;
            if(IsOpening(s[i])){
                if(s[i]=='('&&s[i+1]=='*'){
                    checker.push('*');
                    i++;
                }else{
                    checker.push(s[i]);
                }
            }
            else if(IsClosing(s[i])||(s[i]=='*'&&s[i+1]==')')){
                if (checker.empty())
					break;
				if (s[i] == '*') {
					if (checker.top() != '*') {
						break;
					}
					checker.pop();
					i++;
				} else if (s[i] == ')') {
					if (checker.top() != '(') {
						break;
					}
					checker.pop();
				} else if (s[i] == ']') {
					if (checker.top() != '[') {
						break;
					}
					checker.pop();
				} else if (s[i] == '>') {
					if (checker.top() != '<') {
						break;
					}
					checker.pop();
				} else if (s[i] == '}') {
					if (checker.top() != '{') {
						break;
					}
					checker.pop();
				}
            }
        }
        if(!checker.empty()||i<len){
            if(i>=len&&!checker.empty())count++;
            cout<<"NO"<<" "<<count<<endl;
        }
        else {
            cout<<"YES"<<endl;
        }

        while(!checker.empty())
            checker.pop();
    }
    return 0;

}
