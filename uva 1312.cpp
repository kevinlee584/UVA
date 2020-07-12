#include <iostream>
#include <algorithm>

using namespace std;
int n, w, h, y[105], T = 0;
struct node{
    int x, y;
    bool operator < (const node &b)const{
        if(x==b.x) return y < b.y;
        return x < b.x;
    }
}a[105];

void solve(){
    sort(a,a+n);
    sort(y,y+n+2);
    int len = unique(y, y+n+2)- y;
    int ansx, ansy, m = -1, ww, hh;

    for(int i=0;i<len;++i){
        for(int j=i+1;j<len;++j){
        hh = y[j] - y[i];
        int cur_x = 0;
        for(int k=0;k<n;++k){
            if(a[k].y<=y[i]||y[j]<=a[k].y) continue;
            ww = a[k].x - cur_x; ww = min(ww, hh);
            if(ww>m){ansx = cur_x; ansy = y[i]; m = ww;}
            cur_x = a[k].x;
        }
        ww = w - cur_x; ww = min(ww, hh);
        if(ww>m){ansx = cur_x; ansy = y[i]; m = ww;}
        }
    }
    if(T==1) cout<<endl; T = 1;
    cout<<ansx<<" "<<ansy<<" "<<m<<endl;
}


int main()
{
    int t;
    cin>>t;
    while(t--){
        cin>>n>>w>>h;
        for(int i=0;i<n;++i){
            cin>>a[i].x>>a[i].y;
            y[i] = a[i].y;
        }
        y[n] = 0; y[n+1] = h;
        solve();
    }
    return 0;
}
