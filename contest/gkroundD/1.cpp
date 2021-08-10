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
void solve(){
	vector<vector<int>>v(3,vector<int>(3,0));
	for(int i = 0;i<3;i++){
		for(int j = 0;j<3;j++){
			if(i==1 and j==1){continue;}
			cin>>v[i][j];
		}
	
	}

	int ans = 0;
	if(v[0][0]+v[0][2] == 2*v[0][1]){
		++ans;
	}
	if(v[2][0]+v[2][2] == 2*v[2][1]){
		++ans;
	}
	if(v[0][0]+v[2][0] == 2*v[1][0]){
		++ans;
	}
	if(v[0][2]+v[2][2] == 2*v[1][2]){
		++ans;
	}
	int cal = v[0][0]+v[2][2];
	map<int,int>mp;
	if(cal%2==0)
		mp[cal/2]++;
	cal = v[0][1]+v[2][1];
	if(cal%2==0)
		mp[cal/2]++;
	cal = v[0][2]+v[2][0];
	if(cal%2==0)
		mp[cal/2]++;
	cal = v[1][0]+v[1][2];
	if(cal%2==0)
		mp[cal/2]++;
	int f = INT_MIN,ele = -1;
	for(auto i:mp){
		if(f<i.second){
			f = i.second;
			ele = i.first;
		}
	}
	if(f==INT_MIN)f = 0;
	
	ans+=f;
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
		cout<<"Case #"<<i+1<<": ";
		solve();
		}
	
	//clk = clock()-clk;
	//cout<<"TIME CONSUMED: "<<(float)(clk)/CLOCKS_PER_SEC<<"sec\n";
}
