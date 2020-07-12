#include <iostream>
#include <cstring>

using namespace std;
const int N = 3000;
const int M = 10;
struct num{
    int length;
    int ans[N];
};
num arr[1001];

int main()
{
    for(int i=0;i<=1000;++i) memset(arr[i].ans, 0, sizeof(arr[i].ans));
    arr[0].length = 1; arr[0].ans[0] = 1;
    arr[1].length = 1; arr[1].ans[0] = 1;

    for(int i=2;i<=1000;++i){
        for(int j=0;j<arr[i-1].length;++j){
            arr[i].ans[j] += (arr[i-1].ans[j]*i);
            if(arr[i].ans[j]>=M){
                arr[i].ans[j+1] += arr[i].ans[j]/M;
                arr[i].ans[j] = arr[i].ans[j]%M;
            }
        }
        int k = arr[i-1].length;
        int nn = arr[i].ans[k];
        while(nn>0){
            arr[i].ans[k] = nn%M;
            nn = nn/M;
            k++;
        }
        arr[i].length = k;
    }
    int n;
    while(cin>>n){
        cout<<n<<"!"<<endl;
        for(int i=arr[n].length-1;i>=0;--i)
            cout<<arr[n].ans[i];
        cout<<endl;
    }

}
