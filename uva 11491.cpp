#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

int main()
{
    vector<int> A, ans;
    int n, m;
    char c;

    while(scanf("%d%d",&n,&m)){
        if(n==0&&m==0) break;
        c = getchar();

        for(int i=0;i<n;++i){
            int a = getchar()-'0';
            if(m>0) A.push_back(a);
            else ans.push_back(a);
            m--;
        }


        for(int i=A.size()-1;i>=0;--i){
            if(A[i]>=ans[0]){
                int k = ans[0];
                ans[0] = A[i];
                for(int j=1;j<ans.size();++j){
                    if(k>=ans[j]) swap(ans[j],k);
                    else break;
                }
            }
        }

        for(int i=0;i<ans.size();++i)
            cout<<ans[i];
        cout<<endl;

        ans.clear();
        A.clear();
    }
}
