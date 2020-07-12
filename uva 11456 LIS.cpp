#include <iostream>
#include <vector>

using namespace std;

struct car{
    int w, in, de;
};
vector<car> S;
int main()
{
    int T, N, w;
    cin>>T;
    while(T--){
        S.clear();
        cin>>N;
        for(int i=0;i<N;++i){
            cin>>w; S.push_back((car){w, 1, 1});
        }
        for(int i=N-1;i>=0;i--)
            for(int j=i+1;j<N;++j)
                if(S[i].w<S[j].w)
                    S[i].in = max(S[i].in, S[j].in+1);
        for(int i=N-1;i>=0;i--)
            for(int j=i+1;j<N;++j)
                if(S[i].w>S[j].w)
                    S[i].de = max(S[i].de, S[j].de+1);
        int ans = 0;
        for(int i=0;i<N;++i)
            ans = max(ans, S[i].in + S[i].de - 1);
        cout<<ans<<endl;
    }
}
