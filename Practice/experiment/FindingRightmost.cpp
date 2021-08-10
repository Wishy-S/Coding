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
void solve2(){
	int n;cin>>n;

	vector<int>A(n);
	for(int &i:A)cin>>i;

	int B;cin>>B;
	

	int i = 0, ans = 0;
    if(B == 0){
    	cout<<"-1\n";
        return ;
    }
    //Start from 0th index
    while(i<n)
    {
        int idx = -1;
        //check range [X-B+1, X+B-1] and find rightmost bulb
        int L = max(0, i-B+1);
        int R = min(n,i+B);
        for(int j=R-1;j>=L;j--)
        {
            if(A[j] == 1){
                idx = j;
                break;
            }
        }
        cout<<idx<<'\n';
        if(idx == -1){
        	cout<<"-1\n";
            return ;
        }
        ans++;
        //Start now from index which is outside the current selected bulb
        i = idx+B;
    }
    cout<<ans<<endl;
}
void solve(){
	int n;cin>>n;

	vector<int>A(n);
	for(int &i:A)cin>>i;

	int B;cin>>B;
	int i = 0,ans = 0;
	while(i<n)
    {
        int idx = -1;
        //check range [X-B+1, X+B-1] and find rightmost bulb       
        int R = min(n,i+B);
        int L = max(0, i-B+1);
        for(int j = R-1;j>=L;j--)
        {
            if(A[j] == 1){
                idx = j;
                break;
            }
        }
        // while(j>=L){
        //     --j;
        //     if(A[j]==1){
        //         idx = j;
        //         break;
        //     }
        // }
        if(idx == -1){
            cout<<"-1\n";
            return ;
        }
        ans++;
        cout<<"INDEX : "<<idx<<'\n';
        //Start now from index which is outside the current selected bulb
        i = idx+B;
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
