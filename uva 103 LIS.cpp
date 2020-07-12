#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

struct box{
    int pos, nest[35];
};
int n, m, InLIS[65];
vector<box> S;

bool CmpBoxes(box a, box b){
    for(int i=0;i<m;++i)
        if(a.nest[i]>=b.nest[i]) return false;
    return true;
}
bool Lexico(box a, box b){
    for(int i=0;i<m;++i)
        if(a.nest[i]!=b.nest[i]) return a.nest[i]<b.nest[i];
    return true;
}

void solve(){
    for(int i=0;i<S.size();++i){
        InLIS[i] = 1;
    }
    for(int i=S.size()-1;i>=0;--i)
        for(int j=i+1;j<S.size();++j)
            if(CmpBoxes(S[i],S[j]))
            InLIS[i] = max(InLIS[i], InLIS[j]+1);

    int Max = 0, j;
    for(int i=0;i<S.size();++i){
        if(Max<InLIS[i]){
            Max = InLIS[i];
            j = i;
        }
    }
    cout<<Max<<endl;
    cout<<S[j].pos;
    Max--;
    for(int i=j+1;Max!=0;++i){
        if(CmpBoxes(S[j],S[i])&&Max==InLIS[i]){
            cout<<" "<<S[i].pos;
            j = i;
            Max--;
        }
    }
    cout<<endl;
}

int main()
{
    while(cin>>n>>m){
        box temp;
        for(int i=0;i<n;++i){
            temp.pos = i+1;
            for(int j=0;j<m;++j)
                cin>>temp.nest[j];
            sort(temp.nest, temp.nest+m);
            S.push_back(temp);
        }
        sort(S.begin(),S.end(),Lexico);
        solve();
        S.clear();
    }
}
