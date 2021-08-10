#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define all(v) v.begin(),v.end()
#define pb(x) push_back(x)
#define f firstPK
#define s second
#define vt vector
#define boost ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);  
const ll mod = 998244353;
int gcd(int a,int b){
	if(b==0)return a;
	
	return gcd(b,a%b);
}
void solve(){
	 int has[2000]={0};
        for(int i = 1;(i*(i+1))/2<2000;i++){
            has[(i*(i+1))/2] = 1;
        }
        vector<int>h;
        for(int i = 1;i<2000;i++){
            if(has[i]==1){h.push_back(i);}
        }
        for(int i : h)cout<<i<<' ';
        cout<<endl;
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


