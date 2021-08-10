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
	 string s,p;cin>>s>>p;
	 int i = 0,L = p.length();
	 while(i<s.length()){
	 	string t = s.substr(i,L);
	 	// cout<<t<<endl;
	 	if(t == p){
	 		s.erase(i,L);
	 		// cout<<s<<endl;
	 		i = -1;
	 	}
	 	i++;
	 }
	 cout<<s<<endl;
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

// 0xb177ae204bee22ff5ce17b8306a2333a058f896be706afa055ac2af3b161afea --> 100,123 --> bid
// 0x4c3e7cc0231d66ab6688ab0b95e7a4309723f5af8998942fb234073f180762d0 --> 50 ,123 --> ask