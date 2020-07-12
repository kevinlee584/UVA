#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

struct node{
    int u, v, d;
    bool operator<(const node &b)const{
        return d > b.d;
    }
};
vector<node> data;
vector<node> rem;

int main()
{
    int t;
    cin>>t;

    while(t--){
        int n, m;
        cin>>n>>m;

        int u, v, d;
        while(m--){
            cin>>u>>v>>d;
            data.push_back((node){u,v,d});
        }

        sort(data.begin(),data.end());

        int parent[n+5], t = 1; 
        memset(parent,0,sizeof(parent));
        for(int i=0;i<data.size();++i){
            int u = data[i].u;
            int v = data[i].v;

            if(parent[u]==0&&parent[v]==0){
                parent[u] = t;
                parent[v] = t;
                t++;
            }
            else if(parent[u]!=parent[v]){

                if(parent[u]==0) parent[u] = parent[v];
                else if(parent[v]==0) parent[v] = parent[u];
                else{
                    int k = parent[v];
                    for(int j=1;j<=n;++j)
                        if(parent[j]==k)
                            parent[j] = parent[u];
                }

            }
            else{
                rem.push_back(data[i]);
            }
        }

        int sum = 0;
        for(int i=0;i<rem.size();++i)
            sum += rem[i].d;
        cout<<sum<<endl;
        data.clear();
        rem.clear();
    }
    cin>>t;
    return 0;

}
