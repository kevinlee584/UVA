#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 42;

int dp[MAXN][MAXN][MAXN][MAXN];
int n,arr[5],a[5][MAXN];

int dfs(int basket,int candy){
    if(dp[arr[1]][arr[2]][arr[3]][arr[4]]!=-1)
        return dp[arr[1]][arr[2]][arr[3]][arr[4]];

    int ans = 0;
    int sum, t;
    for(int i=1;i<=4;++i){
        sum = 0;
        arr[i]++;
        if(arr[i]<=n){
            if((t=1<<a[i][arr[i]])&basket)
                sum = dfs((~t)&basket, candy-1)+1;
            else if(candy<4)
                sum = dfs(t|basket, candy+1);
        }
        arr[i]--;
        ans = max(ans, sum);
    }
    return dp[arr[1]][arr[2]][arr[3]][arr[4]] = ans;
}

int main()
{
    while(cin>>n&&n){
        for(int i=1;i<=n;++i)
            for(int j=1;j<=4;++j)
                cin>>a[j][i];
        memset(dp, -1, sizeof(dp));
        memset(arr, 0, sizeof(arr));
        cout<<dfs(0, 0)<<endl;
    }


}
