#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

struct item{
    double l, r;
    bool operator < (const item &b)const{
        if(l==b.l) return r<b.r;
        return l<b.l;
    }
};

int main()
{
    vector<item> S;
    int n;
    double w, l;
    while(cin>>n>>l>>w){
        S.clear();
        double p, r;
        for(int i=0;i<n;++i){
            cin>>p>>r;
            if(r<=w/2) continue;
            double a = sqrt(r*r-w*w/4);
            S.push_back((item){p-a, p+a});
        }
        sort(S.begin(), S.end());
        int i=0, j=0, cnt = 0;
        double left = 0, right = 0;
        bool flag = false;
        while(i<S.size()){
            for(;j<S.size()&&S[j].l<=left;j++)
                if(S[j].r>right)
                    right = S[j].r;

            if(j==i) break;
            cnt++;
            i = j;
            left = right;
            if(right>=l){
                flag =true;
                break;
            }
        }
        if(flag) cout<<cnt<<endl;
            else cout<<-1<<endl;

    }

}
