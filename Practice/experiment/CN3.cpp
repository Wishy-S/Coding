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
	int n;cin>>n;
	vector<int>v(n),A[3];
	for(int &i:v)cin>>i;

	int d[3][3] = {0};

	unordered_map<int,int>mp;
	for(int i = 0;i<n;i++){
		++mp[i%3];
		--mp[v[i]%3];
		if(i%3!=v[i]%3){
			A[i%3].push_back(v[i]%3);
		}
	}
	for(int i = 0;i<3;i++){
		if(mp[i]!=0){
			cout<<"-1\n";return ;
		}
	}

	for(int i = 0;i<3;i++){
		int f[3]={0};
		for(int j:A[i]){
			f[j]++;
		}
		for(int k = 0;k<3;k++){
			if(i!=k){
				d[i][k] = f[k];
			}
		}
	}
	int ans = 0;
	if(d[0][1] > d[1][0]){
		ans+=d[1][0];
		d[0][1]-=d[1][0];
	}else{
		ans+=d[0][1];
		d[1][0]-=d[0][1];
	}
	if(d[0][2] > d[2][0]){
		ans+=d[2][0];
		d[0][2]-=d[2][0];
	}else{
		ans+=d[0][2];
		d[2][0]-=d[0][2];
	}
	if(d[2][1] > d[1][2]){
		ans+=d[1][2];
		d[2][1]-=d[1][2];
	}else{
		ans+=d[2][1];
		d[1][2]-=d[2][1];
	}

	int p = max(d[0][1],d[1][0])+max(d[0][2],d[2][0])+max(d[1][2],d[2][1]);

	ans+=(p/3)*2;

	cout<<ans<<endl;
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
