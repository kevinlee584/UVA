#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

struct data{
    int u, v, d;
    bool operator<(const data &b)const{
        return d<b.d;
    }
}S[25005];
int parent[1005], n, m;
void init(){
    for(int i=0;i<n;++i) parent[i] = i;
    for(int i=0;i<m;++i) cin>>S[i].u>>S[i].v>>S[i].d;
    sort(S, S+m);
}
int find(int x){return x==parent[x] ? x : parent[x] = find(parent[x]);}
void solve(){
    vector<int> ans;
    for(int i=0;i<m;++i){
        int u = S[i].u, v = S[i].v;
        if(parentof(u)!=parentof(v))
            parent[find(u)] = parent[v];
        else ans.push_back(S[i].d);
    }
    if(ans.empty()) cout<<"forest"<<endl;
    else {
        cout<<ans[0];
        for(int i=1;i<ans.size();++i) cout<<" "<<ans[i];
        cout<<endl;
    }
}
int main()
{
    while(cin>>n>>m){
        if(n==0&&m==0) break;
        init();
        solve();
    }
}
