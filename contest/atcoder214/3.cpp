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
typedef tuple<ll,ll,ll> tup;
void solve(){
	int n;cin>>n;
	vector<tuple<ll,ll,ll>>st(n);
	for(int i = 0;i<n;i++){
		ll x;
		cin>>x;
		get<0>(st[i]) = x;
		get<2>(st[i]) = i;
	}
	for(int i = 0;i<n;i++){
		ll x;
		cin>>x;
		get<1>(st[i]) = x;
	}


	auto cmp = [&](const tup &a,const tup &b){
		return get<1>(a) < get<1>(b);
	};
	// sort(all(st),cmp);

	// for(int i = 0;i<n;i++){
	// 	cout<<get<0>(st[i])<<' '<<get<1>(st[i])<<' '<<get<2>(st[i])<<endl;
	// }
	vector<ll>ans(n);
	ll tt = 0;
	// for(auto t:st){
	// 	if(tt==0){
	// 		tt = get<1>(t);
	// 	}
	// 	int indx = get<2>(t);
	// 	ans[indx] = min(get<1>(t),tt);
		
	// 	tt = min(tt+get<0>(t),);
	// }
	int ind = 0,cmin = INT_MAX;
	for(int  i = 0;i<n;i++){
		if(get<1>(st[i]) < cmin){
			cmin  = get<1>(st[i]);
			ind = i;
		}
	}
	tt = cmin;
	for(int i = ind;i<n;i++){
		
		ans[i] = min(get<1>(st[i]),tt);
		tt = min(tt + get<0>(st[i]),get<1>(st[i])+get<0>(st[i]));
	}
	for(int i = 0;i<ind;i++){
		ans[i] = min(get<1>(st[i]),tt);
		tt = min(tt + get<0>(st[i]),get<1>(st[i])+get<0>(st[i]));	
	}



	for(ll i:ans){
		cout<<i<<'\n';
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
