#include <iostream>
#include <vector>

using namespace std;

void find_prime();
void initial();
int gauss();

int array[501][501];
int m, n;
vector<int>Prime;


int main()
{
    find_prime();

    int count;
    cin>>count;

    while(count--){
        cin>>n;
        initial();

        for(int i=0;i<n;++i){
        long long int num;
        cin>>num;

        for(int j=0;Prime[j]<=num&&j<Prime.size();++j){
            int t = 0;
            while(num%Prime[j]==0){
                t++;
                num /= Prime[j];
                }
            if(t%2)array[i][j] = 1;
            m = max(m,j);
        }
        }
    m++;

    long long int ans = 1;
    ans = (ans<<gauss())-1;
    cout<<ans<<endl;
    }

    return 0;

}
void initial()
{
    for(int i=0;i<n;++i)
        for(int j=0;j<501;++j)
            array[i][j] = 0;
}
void find_prime()
{
    bool prime[501];

    for(int i=0;i<501;++i)
        prime[i] = true;

    prime[0] = prime[1] = false;

    for(int i=2;i<501;++i){
        if(prime[i]){
            for(int j=i*i;j<501;j+=i)
                prime[j] = false;
            Prime.push_back(i);
        }
    }
}
int gauss()
{
    int t = 0;
    int i = 0;
    int x;

    while(i<m&&t<n){
        x = t;
        while(x<n){
            if(array[x][i])break;
            x++;
        }
        if(x!=n){
            if(x!=t)
                for(int j=i;j<m;++j){
                    swap(array[t][j],array[x][j]);
                }

            for(int j=t+1;j<n;++j)
                if(array[j][i])
                    for(int k=i;k<m;++k)
                        array[j][k] ^= array[t][k];
            t++;
        }
        i++;
    }
    return n - t;
}
