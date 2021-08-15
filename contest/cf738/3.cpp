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


void canReach(int s,map<int,int>&vis,vector<int>&res,vector<int>adj[]){
	vis[s] = 1;
	res.push_back(s);
	for(int i:adj[s]){
		if(!vis[i]){
			canReach(i,vis,res,adj);
		}
	}
}
void solve(){
	int n;cin>>n;
	vector<int>v(n);
	for(int &i:v)cin>>i;
vector<int>adj[n+2];
	for(int i = 1;i<=n-1;i++){
		adj[i].push_back(i+1);
	}

	for(int i = 1;i<=n;i++){
		if(v[i-1]==0){
			adj[i].push_back(n+1);
		}
		else{
			adj[n+1].push_back(i);
		}
	}
	for(int i = 1;i<=n+1;i++){
		map<int,int>vis;
		vector<int>res;
		bool ok = 1;
		canReach(i,vis,res,adj);
		for(int i = 1;i<=n+1;i++){
			if(vis[i]==0){
				ok = 0;
				break;
			}
		}
		if(ok){
			for(int i:res)cout<<i<<' ';
			cout<<endl;
			return ;
		}
	}
	// 	for(int i = 1;i<=n+1;i++){
	// 	cout<<i<<": ";
	// 	for(int j : adj[i]){
	// 		cout<<j<<' ';
	// 	}
	// 	cout<<endl;
	// }

	cout<<"-1\n";

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
