#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main() {
    int n;
    string s, p, q, temp, ans;
    while (cin>>n && n){
        vector<string> A;
        for (int i = 0; i < n; i++){
            cin>>s; A.push_back(s);
        }
        sort(A.begin(), A.end());

        p = A[n/2-1];
        q = A[n/2];
        ans = "";

        for(int i=0;i<p.length();++i){
            char c = p[i];
            if(c=='Z'){ans = ans + p[i];continue;}
            temp = ans + c;
            if(p<=temp&&temp<q){ans = temp; break;}
            c += 1;
            temp = ans + c;
            if(p<=temp&&temp<q){ans = temp; break;}
            ans = ans + p[i];
        }
        cout<<ans<<endl;
    }
    return 0;
}
