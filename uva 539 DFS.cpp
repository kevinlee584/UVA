#include <iostream>
#include <vector>

using namespace std;

vector<int> G[25];
bool vis[25][25];
int n, m;

int dfs(int u, int d){
    if(G[u].size()==0) return d;

    int dep = d;

    for(int i=0;i<G[u].size();++i){
        int v = G[u][i];
        if(vis[u][v]||vis[v][u])continue;
        vis[u][v] = true;
        dep = max(dep,dfs(v,d+1));
        vis[u][v] = false;
    }

    return dep;
}

int main()
{
    while(cin>>n>>m){
        if(n==0&&m==0) break;
        int u, v;
        for(int i=0;i<m;++i){
            cin>>u>>v;
            G[u].push_back(v);
            G[v].push_back(u);
        }

        for(int i=0;i<25;++i)
            for(int j=0;j<25;++j)
                vis[i][j] = false;

        int Max = 0;
        for(int i=0;i<n;++i)
            Max = max(Max,dfs(i,0));

        cout<<Max<<endl;
        for(int i=0;i<25;++i) G[i].clear();
    }

}
