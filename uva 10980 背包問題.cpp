#include <iostream>
#include <sstream>
#include <iomanip>

using namespace std;

double dp[120], m;
int t, n, nCase;

int main()
{
    dp[0] = 0;
    string str, str1;
    nCase = 1;
    while(cin>>m>>t){
        for(int i=1;i<=100;++i) dp[i] = dp[i-1]+m;
        for(int i=0;i<t;++i){
            cin>>n>>m;
            for(int j=1;j<=100;++j){
                if(j<n) dp[j] = min(dp[j], m);
                else dp[j] = min(dp[j], dp[j-n]+m);
            }
        }
        cin>>str;
        getline(cin,str1);
        str = str + str1;
        stringstream in(str);
        cout << fixed;
        cout<<"Case "<<nCase<<":"<<endl;
        while(in>>n){
            cout<<"Buy "<<n<<" for $"<<setprecision(2)<<dp[n]<<endl;
        }
        nCase++;
    }

}
