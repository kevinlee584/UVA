#include <iostream>
#include <cstring>

using namespace std;

#define lowbit(x) (x&(-x))
#define N 200005

int BitTree[N],arr[N],n,m;

void add(int x, int v){
    while(x<N){
        BitTree[x]+=v;
        x+=lowbit(x);
    }
}

int query(int x){
    int ans = 0;
    while(x){
        ans+=BitTree[x];
        x-=lowbit(x);
    }
    return ans;
}

int main()
{
    int t;
    cin>>t;
    while(t--){
        memset(BitTree,0,sizeof(BitTree));
        cin>>n>>m;

        for(int i=1;i<=n;++i){
            arr[i] = n+1-i;
            add(i,1);
        }

        for(int i=1;i<=m;++i){
            int v;
            cin>>v;
            int under = query(arr[v]);

            if(i!=1)cout<<" ";
            cout<<n-under;

            add(arr[v],-1);
            arr[v] = n + i;
            add(n+i,1);
        }

        cout<<endl;

    }

}
