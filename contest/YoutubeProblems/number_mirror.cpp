#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define all(v) v.begin(),v.end()
#define pb(x) push_back(x)
#define f first
#define s second
#define vt vector
#define boost ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);  
const ll mod = 1e9+7;
ll power(ll x,unsigned ll y,ll p){
	 ll res = 1;     // Initialize result
 
    x = x % p; // Update x if it is more than or
                // equal to p
  
    if (x == 0) return 0; // In case x is divisible by p;
 
    while (y > 0)
    {
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res*x) % p;
 
        // y must be even now
        y = y>>1; // y = y/2
        x = (x*x) % p;
    }
    return res;
}
int gcd(int a,int b){
	if(b==0)return a;
	
	return gcd(b,a%b);
}
ll sumofFactors(ll n)
{
    // Traversing through all prime factors.
    ll res = 1;
    for (ll i = 2; i <= sqrt(n); i++)
    {
 
         
        ll curr_sum = 1;
        ll curr_term = 1;
        while (n % i == 0) {
 
            // THE BELOW STATEMENT MAKES
            // IT BETTER THAN ABOVE METHOD
            //  AS WE REDUCE VALUE OF n.
            n = n / i;
 
            curr_term *= i;
            curr_sum += curr_term;
        }
 
        res *= curr_sum;
    }
 
    // This condition is to handle
    // the case when n is a prime
    // number greater than 2.
    if (n >= 2)
        res *= (1+n);
 
    return res;
}
int check(vector<int>&v){
	int n = v.size();
	if(n<3){
		return 1;
	}
	for(int i = 0;i<n;i++){
		for(int j = i+1;j<n;j++){
			for(int k = i+1;k<j;k++){
				if(v[k]*2 == v[i]+v[j]){
					cout<<i<<' '<<j<<' '<<k<<endl;
					return 0;
				}
			}
		}
	}
	return 1;
}
void solve(){
	int n;cin>>n;

	vector<int>v(n);
	for(int &i:v)cin>>i;


	if(check(v)){
		cout<<"YES\n";
	}else{
		cout<<"NO\n";
	}

}
int main()
{	boost;
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	t = 1;
	// cin>>t;
	//cin>>t>>n>>q;
	//clock_t clk = clock();
	for(int i = 0;i<t;i++){
		//cout<<"Case #"<<i+1<<": ";
		solve();
		}
	
	//clk = clock()-clk;
	//cout<<"TIME CONSUMED: "<<(float)(clk)/CLOCKS_PER_SEC<<"sec\n";
}
