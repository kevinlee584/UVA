#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
struct item{
    int price, favorite;
    bool operator<(const item &b)const{
        if(favorite==b.favorite) return price<b.price;
        return favorite>b.favorite;
    }
};
vector<item> S;
int dp[105][10205], n, m, flag, Max;

void init(){
    S.clear();
    flag = 0;
    Max = 0;
    int p, f;
    for(int i=0;i<n;++i){
        cin>>p>>f;
        S.push_back((item){p, f});
        if(p==2000) Max = max(Max, f);
    }
    for(int j=0;j<=m+200;++j) dp[0][j] = 0;
    if(1800<m&&m<2000) flag = 1;
    if(m>1800) m+=200;
}
int total_Sum(){
    int sum = 0;
    for(int x=n,y=m;x!=0;--x){
        if(dp[x][y]==dp[x-1][y]) continue;
        sum += S[x-1].price;
        y -= S[x-1].price;
    }
    return sum;
}
void solve(){
    int p, f;
    n = 0;
    for(int i=0;i<S.size();++i){
        p = S[i].price;
        f = S[i].favorite;
        n++;
        if(flag&&p==2000){
          for(int j=0;j<=m;++j) dp[n][j] = dp[n-1][j];
          continue;
        }
        for(int j=0;j<=m;++j){
            if(j<p) dp[n][j] = dp[n-1][j];
            else dp[n][j] = max(dp[n-1][j], dp[n-1][j-p]+f);
        }

    }
    if(flag==0)cout<<dp[n][m]<<endl;
    else {
        int sum = total_Sum();
        int Ans;
        if(sum<=2000) Ans = dp[n][m-200];
        else Ans = dp[n][m];

        for(int i=m;i>2000;--i){
            if(dp[n][i-2000]==0) break;
            if(dp[n][i-2000]!=dp[n][i-2001]){
                Ans = max(Ans, dp[n][i-2000]+Max);
                break;
            }
        }
        cout<<Ans<<endl;
    }
}

int main()
{
    while(cin>>m>>n){
        init();
        solve();
    }

}
