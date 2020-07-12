#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const int maxn = 0x0001FFFF;

int main()
{
    int A[4000],B[4000],C[4000],D[4000];
    int n, m;
    cin>>n;
    int t = 0;
    while(n--){
        if(t)cout<<endl;
        t = 1;
        cin>>m;
        for(int i=0;i<m;++i)
            cin>>A[i]>>B[i]>>C[i]>>D[i];
        vector<int> CD[maxn];

        for(int i=0;i<m;++i)
        for(int j=0;j<m;++j){
            int sum = C[i] + D[j];
            CD[abs(sum)%maxn].push_back(sum);
        }
        int ans = 0;

        for(int i=0;i<m;++i)
        for(int j=0;j<m;++j){
            int sum = A[i] + B[j];
            int d = abs(sum)%maxn;
            for(size_t k=0;k<CD[d].size();++k){
                if(sum+CD[d][k]==0)
                    ans++;
            }
        }
        cout<<ans<<endl;;
    }
}
