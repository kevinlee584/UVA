#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;
const int N = 26;
int in[N];
char indexof[N];
string a, b;
vector<int> graph[N];

void initial(){
    for(int i=0;i<N;++i) {
        graph[i].clear();
        in[i] = -1;
    }
    while(cin>>b&&b!="#"){
        int L = (a.size()>b.size())?b.size():a.size();
        for(int i=0;i<L;++i){
            int x = a[i]-'A', y = b[i]-'A';
            if(in[x]==-1) in[x] = 0;
            if(in[y]==-1) in[y] = 0;
            if(x!=y){
                graph[x].push_back(y);
                in[y]++;
                break;
            }
        }
        a = b;
    }
}

void topologic(){
    queue<int> Q;
    vector<int> ans;
    for(int i=0;i<N;++i)
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

    for(int i=0;i<ans.size();++i) cout<<indexof[ans[i]];
    cout<<endl;
}
int main() {
    char c = 'A';
    for(int i=0;i<N;++i) indexof[i] = c+i;
    while(cin>>a){
        initial();
        topologic();
    }
	return 0;
}
