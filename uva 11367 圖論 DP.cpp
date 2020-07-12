#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

const int inf = 999999;
const int maxn = 1005;
const int maxm = 105;

struct City{
    int city, rest, cost;
    City(int c=0,int r=0,int cs=0):city(c),rest(r),cost(cs){};
    bool operator < (const City &a)const{
        return cost>a.cost;
    }
};
typedef pair<int,int> pii;
vector<pii> G[maxn];
int P[maxn],D[maxn][maxm],Vis[maxn][maxm],N,M;

void initial(){
    for(int i=0;i<N;++i){
        G[i].clear();
        cin>>P[i];
    }
    int u,v,w;
    while(M--){
        cin>>u>>v>>w;
        G[u].push_back(make_pair(v,w));
        G[v].push_back(make_pair(u,w));
    }
}
int Dijkstra(int c, int s, int e){
    priority_queue<City> PQ;
    for(int i=0;i<N;++i)
    for(int j=0;j<=c;++j){
        D[i][j] = inf;
        Vis[i][j] = 0;
    }

    D[s][0] = 0;
    PQ.push(City(s,0,D[s][0]));//city, rest, cost

    while(!PQ.empty()){
        City temp = PQ.top(); PQ.pop();
        int city = temp.city, rest = temp.rest;

        if(Vis[city][rest])continue;
        Vis[city][rest] = 1;

        for(size_t i=0;i<G[city].size();++i){
            int v = G[city][i].first, d = G[city][i].second;
            if(rest<d)continue;

            if(D[v][rest-d]>D[city][rest]){
                D[v][rest-d] = D[city][rest];
                PQ.push(City(v,rest-d,D[v][rest-d]));
            }
        }
        if(rest<c&&D[city][rest+1]>D[city][rest]+P[city]){
            D[city][rest+1] = D[city][rest] + P[city];
            PQ.push(City(city,rest+1,D[city][rest+1]));
        }
    }
    return D[e][0];
}


int main()
{
    while(cin>>N>>M){
        initial();
        int q, u, v, w;
        cin>>q;
        while(q--){
            cin>>w>>u>>v;
            int Cost = Dijkstra(w,u,v);
            if(Cost==inf)cout<<"impossible"<<endl;
            else cout<<Cost<<endl;
        }
    }

}
