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
const int d4i[4]={-1, 0, 1, 0}, d4j[4]={0, 1, 0, -1};
const int d8i[8]={-1, -1, 0, 1, 1, 1, 0, -1}, d8j[8]={0, 1, 1, 1, 0, -1, -1, -1};

const int mxn = 1e7;

bool primes[mxn+1];
void sieve(){
	memset(primes,true,sizeof(primes));
	primes[1] = false;
	//first check all the nos. less than sqrt(LimitUpToWhichPrimesToBeCalculated)
	for(int i = 2;i*i<=mxn ;i++){
		
		if(primes[i]){
			for(int j = i*i;j<=mxn;j+=i)
				primes[j] = false;
			}	
	}
	
}

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
void solve(){
	int n,m;cin>>n>>m;
	map<double,int>slope;
	for(int i = 0 ;i<m;i++){
		int a,b;cin>>a>>b;
		if(a==b){
			slope[INT_MAX]++;
		}else{
			double sl = (double)1/(double)(b-a);
			slope[sl]++;
		}
	}
	int ans = 0;
	for(auto i:slope){
		
		ans = max(ans,i.second);
	}
	cout<<ans<<endl;
}
int main()
{	boost;
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	
	t = 1;
	cin>>t;
	//cin>>t>>n>>q;
	//clock_t clk = clock();
	for(int i = 0;i<t;i++){
		// cout<<"Case #"<<i+1<<": ";
		solve();
		}
	
	//clk = clock()-clk;
	//cout<<"TIME CONSUMED: "<<(float)(clk)/CLOCKS_PER_SEC<<"sec\n";
}
