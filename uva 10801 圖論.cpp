#include <iostream>
#include <vector>
#include <queue>
#include<cstring>
#include<cstdio>

using namespace std;

#define inf 999999

void Dijkstra();
void initial();
int w[101][101], dis[101], Time[6], e, n;
bool vis[101];

int main()
{
    while(cin>>n>>e){
        initial();
        Dijkstra();
        if(dis[e]==0) cout<<0<<endl;
        else if(dis[e]!=inf)cout<<dis[e]-60<<endl;
        else cout<<"IMPOSSIBLE"<<endl;
    }

}
void initial(){
    for(int i=0;i<101;++i)
        for(int j=0;j<101;++j)
            w[i][j] = inf;
    for(int i=0;i<101;++i){
        dis[i] = inf;
        vis[i] = false;
    }

    dis[0] = 0;

    for(int i=1;i<=n;++i)
            cin>>Time[i];

    for(int k=1;k<=n;++k){
        vector<int> data;
        int t;
        do{
            cin>>t;
            data.push_back(t);
        }while(getchar()!='\n');

        for(int i=0;i<data.size();++i)
            for(int j=0;j<data.size();++j){
                int p = data[i];
                int q = data[j];
                if(p>q)swap(p,q);

                if(w[data[i]][data[j]]>(q-p)*Time[k])
                    w[data[i]][data[j]] = (q-p)*Time[k];
            }
            data.clear();
    }
}

void Dijkstra(){
    queue<int>q;
    q.push(0);
    while(!q.empty()){
        int i = q.front();
        q.pop();
        vis[i] = false;

        for(int j=0;j<101;++j){
            if(dis[j]>dis[i]+w[i][j]+60){
                dis[j] = dis[i] + w[i][j] + 60;

                if(!vis[j]){
                    q.push(j);
                    vis[j] = true;
                }
            }
        }
    }

}
