#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;
const int N = 105;
int in[N], n, m;
vector<int> graph[N];

void initial(){
    memset(in, 0, sizeof(in));
    for(int i=0;i<N;++i) graph[i].clear();
    int u, v;
    for(int i=0;i<m;++i){
        cin>>u>>v;
        graph[u].push_back(v);
        in[v]++;
    }
}

void topologic(){
    queue<int> Q;
    vector<int> ans;
    for(int i=1;i<=n;++i)
        if(in[i]==0) Q.push(i);
    while(!Q.empty()){
        int t = Q.front(); Q.pop();
        ans.push_back(t);
        for(int i=0;i<graph[t].size();++i){
            int v = graph[t][i];
            in[v]--;
            if(in[v]==0) Q.push(v);
        }
    }

    for(int i=0;i<ans.size();++i){
        if(i) cout<<" "<<ans[i];
        else cout<<ans[i];
    }
    cout<<endl;
}
int main() {
    while(cin>>n>>m){
        if(n==0&&m==0) break;
        initial();
        topologic();
    }
	return 0;
}
