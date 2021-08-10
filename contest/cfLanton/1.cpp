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
	int n,m ;cin>>n>>m;
	vector<string>grid(n);
	for(int i = 0;i<n;i++)cin>>grid[i];
	
	vector<string>g1(n),g2(n);
	string t1 = "",t2 = "";
	for(int i = 0;i<m;i++){
		if(i&1){
			t1+="R";t2+="W";
			}
		else{
			t1+="W";t2+="R";
			}
	}
	
	
	//build g1
	for(int i = 0;i<n;i++){
		if(i&1){
			g1[i] = t1;
			g2[i] = t2;
			}
		else{
			g2[i] = t1;
			g1[i] = t2;
			}
	}
	
		bool ok1 = 1,ok2 = 1;
		for(int i = 0;i<n;i++){
			for(int j = 0;j<m;j++){
				if(grid[i][j]=='.')continue;
				else{
					if(grid[i][j]!=g1[i][j]){
						ok1 = 0;
						break;
						}
					}
				
				}
			}
		for(int i = 0;i<n;i++){
			for(int j = 0;j<m;j++){
				if(grid[i][j]=='.')continue;
				else{
					if(grid[i][j]!=g2[i][j]){
						ok2 = 0;
						break;
						}
					}
				
				}
			}	
		if(!ok1 and !ok2){
			cout<<"NO\n";
			}
		else {
			cout<<"YES\n";
			if(ok1){
			for(auto s:g1){
				cout<<s<<'\n';
				}
			}
		else{
			for(auto s:g2){
				cout<<s<<'\n';
				}
			}
		}
	
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
