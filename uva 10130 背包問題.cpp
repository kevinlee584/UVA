#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct object{
    int price, weight;
};
vector<object> input;
vector<int> people;
int dp[1005][35], N, M, MaxSum;

void dp_solve(int p){
    int w, n, s;
    for(int i=0;i<input.size();++i){
        n = i+1; w = input[i].weight; s = input[i].price;
        for(int j=0;j<=people[p];++j){
            if(j<w) dp[n][j] = dp[n-1][j];
            else dp[n][j] = max(dp[n-1][j], dp[n-1][j-w]+s);
        }
    }
}

void solve(){
    int n = input.size();
    MaxSum = 0;
    for(int i=0;i<people.size();++i){
        for(int j=0;j<=30;++j) dp[0][j] = 0;
        dp_solve(i);
        MaxSum += dp[n][people[i]];
    }
    cout<<MaxSum<<endl;
}

int main()
{
    int T;
    cin>>T;
    while(T--){
        cin>>N;
        int pi, wi, carryi;
        for(int i=0;i<N;++i){
            cin>>pi>>wi;
            input.push_back((object){pi, wi});
        }
        cin>>M;
        for(int i=0;i<M;++i){
            cin>>carryi;
            people.push_back(carryi);
        }
        solve();
        input.clear();
        people.clear();
    }

}
