#include <iostream>
#include <algorithm>

using namespace std;
struct node{
    int l ,r;
    bool operator < (const node &b)const{
        if(r==b.r) return l < b.l;
        return r < b.r;
    }
}a[300005];
int n;
void solve(){
    int p = -1 ,ans = 0;
    for(int i=0;i<n;++i){
        if(a[i].r==p) continue;
        if(a[i].l>p){
            ans++;
            p = a[i].r;
        }
        else p++;
    }
    cout<<ans-1<<endl;
}


int main()
{
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=0;i<n;++i) cin>>a[i].l>>a[i].r;
        sort(a, a+n);
        solve();
    }

    return 0;
}
