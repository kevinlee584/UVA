#include <iostream>
#include <vector>

using namespace std;

vector<int> a, ans;
int n, m, dp[25][100005];

int main()
{
    while(cin>>m>>n){

        int track;
        for(int i=0;i<n;++i){
            cin>>track;
            a.push_back(track);
        }
        for(int i=0;i<=m;++i) dp[0][i] = 0;

        n = 0;
        for(int i=0;i<a.size();++i){
            n++;
            for(int j=0;j<=m;++j){
                if(j<a[i]) dp[n][j] = dp[n-1][j];
                else dp[n][j] = max(dp[n-1][j], dp[n-1][j-a[i]]+a[i]);
            }
        }
        for(int x=n,y=m;x!=0;--x){
            if(dp[x][y]==dp[x-1][y]) continue;
            ans.push_back(a[x-1]); y-=a[x-1];
        }
        for(int i=ans.size()-1;i>=0;--i)
            cout<<ans[i]<<" ";

        cout<<"sum:"<<dp[n][m]<<endl;
        a.clear();
        ans.clear();
    }

}
