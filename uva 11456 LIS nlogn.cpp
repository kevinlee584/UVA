#include <iostream>
#include <vector>

using namespace std;
int T, n;
vector<int> S, v;

int main()
{
    cin>>T;
    while(T--){
        S.clear();
        v.clear();
        cin>>n;
        if(n<=0){
            cout<<0<<endl;
            continue;
        }

        int num;
        for(int i=0;i<n;++i){
            cin>>num;
            S.push_back(num);
        }
        for(int i=0;i<n;++i)
            S.insert(S.begin(), S[i+i]);

        vector<int>::iterator it;
        v.push_back(S[0]);

        for(int i=1;i<S.size();++i){
            it = lower_bound(v.begin(), v.end(), S[i]);
            if(it==v.end()){
                v.push_back(S[i]);
            }
            else{
                *it = S[i];
            }
        }
        cout<<v.size()<<endl;
    }

}
