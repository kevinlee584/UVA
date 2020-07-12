#include <iostream>
#include <vector>

using namespace std;

const int N = 100000;

struct node{
    long long value;
    int left, right;
};
long long PreSum[N+5];
vector<node> S;
long long GetPreSum(node i){
    return PreSum[i.right]-PreSum[i.left-1];
}
int main()
{
    int n, t = 0;
    PreSum[0] = 0;
    while(cin>>n){
        S.clear();
        S.push_back((node){-1, 0, 0});
        for(int i=1;i<=n;++i){
            cin>>PreSum[i];
            S.push_back((node){PreSum[i], i, i});
            PreSum[i] += PreSum[i-1];
        }
        S.push_back((node){-1, n+1, n+1});

        for(int i=1;i<=n;++i)
            while(S[i].value<=S[S[i].left-1].value)
                S[i].left = S[S[i].left-1].left;

        for(int i=n;i>0;--i)
            while(S[i].value<=S[S[i].right+1].value)
                S[i].right = S[S[i].right+1].right;

        long long Max = 0;
        int j = 0;
        for(int i=1;i<=n;++i){
            if(Max < GetPreSum(S[i])*S[i].value){
                Max = GetPreSum(S[i])*S[i].value;
                j = i;
            }
        }

        if(t==1) cout<<endl; t = 1;
        cout<<Max<<endl;
        if(j==0) cout<<1<<" "<<1<<endl;
        else cout<<S[j].left<<" "<<S[j].right<<endl;


    }
}
