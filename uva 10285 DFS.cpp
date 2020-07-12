#include <iostream>
#include <cstring>

using namespace std;

int num[105][105], n, m;
int find_path(int i, int j, int l){
    int a =0, b = 0, c = 0, d = 0;
    if(i+1<=n&&num[i][j]>num[i+1][j]) a = find_path(i+1, j, l+1);
    if(i-1>0 &&num[i][j]>num[i-1][j]) b = find_path(i-1, j, l+1);
    if(j+1<=m&&num[i][j]>num[i][j+1]) c = find_path(i, j+1, l+1);
    if(j-1>0 &&num[i][j]>num[i][j-1]) d = find_path(i, j-1, l+1);

    if(a||b||c||d){
        a = max(a, b); a = max(a, c); a = max(a, d);
        return a;
    }
    return l;
}


int main()
{
    string name;
    int t;
    cin>>t;
    while(t--){
        cin>>name>>n>>m;
        for(int i=1;i<=n;++i)
            for(int j=1;j<=m;++j)
                cin>>num[i][j];

        int ans = 0;
        for(int i=1;i<=n;++i)
            for(int j=1;j<=m;++j)
                ans = max(ans, find_path(i, j, 1));

        cout<<name<<": "<<ans<<endl;
    }




}
