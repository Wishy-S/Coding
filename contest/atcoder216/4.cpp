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
	vector<vector<int>>v;
	for(int i = 0;i<m;i++){
		int k;cin>>k;
		vector<int>t(k);
		for(int &i:t)cin>>i;

		reverse(t.begin(),t.end());
		v.push_back(t);	
	}
	int cnt = 0;
	while(1){
		bool ok = 0;
		for(int i = 0;i<m;i++){
			for(int j = 0;j<m;j++){
				if(j!=i and !v[i].empty() and !v[j].empty() and v[i].back()==v[j].back()){
					v[i].pop_back();
					v[j].pop_back();
					cnt+=2;
					ok = 1;
					break;
				}
			}
			if(ok == 1 )break;
		}
		if(ok==0 and cnt==2*n){cout<<"Yes\n";return;}
		if(ok == 0 and cnt!=2*n){
			cout<<"No\n";return ;
		}
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
