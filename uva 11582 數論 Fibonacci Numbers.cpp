#include <iostream>

using namespace std;

typedef unsigned long long ull;

int pow_mod(ull a, ull b, ull c){
    if(b==0) return 1;
    ull x = pow_mod(a,b/2,c);
    ull ans = (ull)x * x % c;
    if(b%2==1)   ans = ans * a % c;
    return (int)ans;
}
const int N = 1100*1100;
int f[N];

int main()
{
    int t,n;
	ull a,b;
	cin >> t;
	while(t--)
    {
		cin >> a >> b >> n;
		f[0] = 0, f[1] = 1%n;
		int kase;
		for(int i = 2; i <= n*n+100; i++)
        {
			f[i] = (f[i-1]+f[i-2]) % n;
			if(f[i]==f[1] && f[i-1]==f[0])
			{
				kase = i - 1;
				break;
			}
		}

		int ans = pow_mod(a%kase, b,(ull)kase);
		cout << f[ans] << endl;
	}
    return 0;
}
