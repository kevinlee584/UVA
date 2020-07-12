#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef long long lln;
struct road{
    int u;
    lln items;
    bool operator<(const road &b)const{
        return items > b.items;
    }
};
int inf = 0x0000FFFF;
int n;
lln item[105];
int pre[105], vis[105];
vector<int> G[105];

lln cal(int x, lln c){
    if(x<=26){
        if(c%19==0) c = c + c /19;
        else c = c + c /19 + 1;
    }
    else c += 1;
    return c;
}

void initial(){
    for(int i=0;i<105;++i){
        G[i].clear();
        item[i] = (1LL<<61);
        pre[i] = inf;
        vis[i] = 0;
    }

    char u, v;
    for(int i=0;i<n;++i){
        cin>>u>>v;
        G[u-'A'].push_back(v-'A');
        G[v-'A'].push_back(u-'A');
    }

}

void BFS(int s, int e, lln c){
    c = cal(e, c);
    item[e] = c;
    pre[e] = -1;
    priority_queue<road> PQ;
    PQ.push((road){e, c});

    while(!PQ.empty()){
        road temp = PQ.top(); PQ.pop();
        int u = temp.u;
        lln it = temp.items;

        if(vis[u]==1) continue;
        vis[u] = 1;

        for(int i=0;i<G[u].size();++i){
            int v = G[u][i];
            lln k = cal(v, it);
            if(k > item[v])continue;
            if(k==item[v]&&u > pre[v])continue;
            item[v] = k;
            pre[v] = u;
            PQ.push((road){v, item[v]});
        }
    }
}

int main()
{
    int t = 1;
    while(cin>>n){
        if(n==-1) break;
        cout<<"Case "<<t<<":"<<endl; t++;
        initial();
        char s, e;
        lln cost;
        int i;
        cin>>cost>>s>>e;

        if(s==e){
            cout<<cost<<endl;
            cout<<s;
        }
        else {
            BFS(s-'A', e-'A', cost);
            cout<<item[pre[s-'A']]<<endl;
            i = pre[s-'A'];
            cout<<s;
            while(i!=-1){
                char c = 'A' + i;
                cout<<"-"<<c;
                i = pre[i];
            }
        }
        cout<<endl;
    }
    return 0;
}
