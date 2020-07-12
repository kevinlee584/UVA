#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

typedef pair<int, int> pii;
const int N = 100000+5;
int n, m, vis[N], frombeg[N], fromend[N], ans[N];
vector<pii> G[N];
queue<int> next1, next2;

void init(){
    for(int i=0;i<=n;++i) G[i].clear();
    memset(frombeg, 0x3f, sizeof(frombeg));
    memset(fromend, 0x3f, sizeof(fromend));
    memset(vis, 0, sizeof(vis));
    memset(ans, 0x3f, sizeof(ans));
    while (!next1.empty())next1.pop();
    while (!next2.empty())next2.pop();

    int u, v, c;
    for(int i=0;i<m;++i){
        cin>>u>>v>>c;
        if(u==v) continue;
        G[u].push_back(make_pair(v, c));
        G[v].push_back(make_pair(u, c));
    }
}
void BFS(int s, int *dis){
    dis[s] = 0;
    queue<int> S;
    S.push(s);
    while(!S.empty()){
        int u = S.front(); S.pop();
        for(size_t i=0;i<G[u].size();++i){
            int v = G[u][i].first;
            if(dis[u]+1<dis[v]){
                dis[v] = dis[u]+1;
                S.push(v);
            }
        }
    }
}
void BFS(int k){
    if(k==frombeg[n]+1) return;
    next2 = next1;
    while(!next1.empty()){
        int u = next1.front(); next1.pop();
        for(int j=0;j<G[u].size();++j){
            int v = G[u][j].first;
            if(frombeg[v]+fromend[v]==frombeg[n]&&frombeg[v]==k)
                ans[k] = min(ans[k], G[u][j].second);
        }
    }
    while(!next2.empty()){
        int u = next2.front(); next2.pop();
        for(int j=0;j<G[u].size();++j){
            int v = G[u][j].first;
            if(frombeg[v]==k&&vis[v]==0&&G[u][j].second==ans[k]){
                vis[v] = 1;
                next1.push(v);
            }
        }
    }
    BFS(k+1);
}
int main()
{
    while(cin>>n>>m){
        init();
        BFS(1, frombeg);
        BFS(n, fromend);
        next1.push(1);
        BFS(1);
        cout<<frombeg[n]<<endl;
        for(int i=1;i<=frombeg[n];++i){
            if(i==1) cout<<ans[i];
            else cout<<" "<<ans[i];
        }
        cout<<endl;
    }
}
