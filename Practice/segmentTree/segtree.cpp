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
const int mxn = 1e6;
ll tree[mxn+1];
void build(vector<ll>v){
	//n needs to be power of 2 if not then make it . by appending the elements
	ll n = v.size();
	ll indx = 2*n-1;
	//first copied all the values from the array to leaves
	for(int j = n-1;j>=0;j--,indx--){
		tree[indx]=v[j];
		}
		
	//forming the internal nodes 
	
	while(indx>0){
		tree[indx] = tree[2*indx]+tree[2*indx+1];
		indx--;
		}
	
}
ll sum(ll a,ll b,ll n){
	a+=n;b+=n;
	ll s = 0;
	while(a<=b){
		if(a%2==1)s+=tree[a++];
		if(b%2==0)s+=tree[b--];
		a/=2;b/=2;
		}
	return s;
}
void update(ll k,ll x,ll n){
	k+=n;
	tree[k]+=x;
	for(k/=2;k>=1;k/=2){
		tree[k] = tree[2*k]+tree[2*k+1];
		}
}
void solve(){
	ll n;cin>>n;
	vt<ll>v(n);
	for(ll &i:v)cin>>i;
	
	//if n is not a power of 2 then we have to insert some elements to the array
	
	while(!(n&&!(n&(n-1)))){
		v.push_back(0);
		n = v.size();
	}
	
	//building the segment tree in bottom up manner
	build(v);
	//for(ll i = 1;i<2*n;i++)cout<<tree[i]<<' ';
	
	//cout<<'\n';
	int q;cin>>q;
	while(q--){
		char t;
		ll L,R;cin>>t;
		
		//sum query
		if(t=='q'){
			cin>>L>>R;
			--L,--R;
			cout<<sum(L,R,n)<<'\n';
		}
		//update query
		else{
			ll x,k;cin>>k>>x;
			--k;
			update(k,x,n);			
			}	
	}
	
}
int main()
{	boost;
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	t = 1;
	//cin>>t;
	//cin>>t>>n>>q;
	//clock_t clk = clock();
	for(int i = 0;i<t;i++){
		//cout<<"Case #"<<i+1<<": ";
		solve();
		}
	
	//clk = clock()-clk;
	//cout<<"TIME CONSUMED: "<<(float)(clk)/CLOCKS_PER_SEC<<"sec\n";
}
