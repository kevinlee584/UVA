#include<iostream>
#include<vector>

using namespace std;
vector<int> S;
int n;
int arr[505], index[505];

int cal(){
    int t = 0;
    for(int i=0;i<n;++i){
        if(i==arr[i])continue;
        int a = i, b = index[i];
        swap(arr[a], arr[b]);
        swap(index[arr[a]], index[arr[b]]);
        t++;
    }
    return t;
}

int solve(){
    int ans = 99999;

    for(int i=0;i<S.size()-n;++i){
        int k = i;
        for(int j=0;j<n;++j){
            arr[j] = S[k];
            index[arr[j]] = j;
            k++;
        }
        ans = min(cal(),ans);
    }

    for(int i=S.size()-1;i>=n;--i){
        int k = i;
        for(int j=0;j<n;++j){
            arr[j] = S[k];
            index[arr[j]] = j;
            k--;
        }
        ans = min(cal(),ans);
    }
    return ans;
}
int main()
{
    while(cin>>n){
        if(n==0)break;
        int num;
        for(int i=0;i<n;++i){
            cin>>num;
            S.push_back(num-1);
        }
        for(int i=0;i<n;++i)
            S.push_back(S[i]);

        cout<<solve()<<endl;
        S.clear();
    }

    return 0;
}
