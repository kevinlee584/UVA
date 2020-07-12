#include <iostream>

using namespace std;

typedef long long int lln;
int n;
lln a[105], dp[105][105];
#define sum(x, y) (a[y]-a[x-1])

int main()
{
    a[0] = 0;
    while(cin>>n&&n){
        for(int i=1;i<=n;++i){
            cin>>a[i];
            a[i]+=a[i-1];
        }
        for(int i=1;i<=n;++i)
            for(int j=1;j<=n;++j)
                dp[i][j] = 0;

        for(int l=0;l<=n;++l)
        for(int s=1;s+l<=n;++s){
            int e = s+l;
            dp[s][e] = sum(s, e);
            for(int k=s+1;k<=e;++k)
                dp[s][e] = max(dp[s][e], sum(s, e)-dp[k][e]);
            for(int k=e-1;k>=s;--k)
                dp[s][e] = max(dp[s][e], sum(s, e)-dp[s][k]);
        }

        cout<<dp[1][n]*2-sum(1, n)<<endl;
    }
}
