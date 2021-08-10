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
int gcd(int a,int b){
	if(b==0)return a;
	
	return gcd(b,a%b);
}
void solve(){
	int n;cin>>n;
	vt<ll>v(n);
	for(ll &i:v)cin>>i;
	
	ll cost = 0;
	for(int i = 0;i<n-1;i++){
		cost+=abs(v[i]-v[i+1]);
		}
	
	cost+=(v[0]+v[n-1]);
	bool ok = 1;
	while(ok){
		ok = 0;
	for(int i = 1;i<n-1;i++){
		if(v[i]>v[i-1] and v[i]>v[i+1]){
			ll mx = max(v[i-1],v[i+1]);
			cost-=abs(v[i]-mx);
			v[i] = mx;	
			ok = 1;	
		}
		}
	}
	if(v[0]>v[1]){
		cost-=(v[0]-v[1]);
		}
	if(v[n-1]>v[n-2]){
		cost-=(v[n-1]-v[n-2]);
		}
		
	cout<<cost<<endl;
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
		//cout<<"Case #"<<i+1<<": ";
		solve();
		}
	
	//clk = clock()-clk;
	//cout<<"TIME CONSUMED: "<<(float)(clk)/CLOCKS_PER_SEC<<"sec\n";
}
