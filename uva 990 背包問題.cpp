#include <iostream>
#include <vector>

using namespace std;

struct treasure{
    int dep, num;
};
int dp[35][1005], limit, w, n;
vector<treasure> a, ans;
int main()
{
    int Case = 0;
    while(cin>>limit>>w){
        for(int i=0;i<=limit;++i) dp[0][i] = 0;
        cin>>n;
        int di, vi;
        for(int i=0;i<n;++i){
            cin>>di>>vi;
            a.push_back((treasure){di, vi});
        }
        int n = 0;
        for(int i=0;i<a.size();++i){
            n++;
            di = a[i].dep, vi = a[i].num;
            for(int j=0;j<=limit;++j){
                if(j<(di*w*3)) dp[n][j] = dp[n-1][j];
                else dp[n][j] = max(dp[n-1][j], dp[n-1][j-(di*w*3)]+vi);
            }
        }
        for(int x=n,y=limit;x!=0;--x){
            if(dp[x][y]==dp[x-1][y]) continue;
            ans.push_back(a[x-1]); y-=a[x-1].dep*w*3;
        }
        if(Case==1) cout<<endl; Case = 1;
        cout<<dp[n][limit]<<endl;
        cout<<ans.size()<<endl;
        for(int i=ans.size()-1;i>=0;--i)
            cout<<ans[i].dep<<" "<<ans[i].num<<endl;

        a.clear();
        ans.clear();
    }
    return 0;

}
