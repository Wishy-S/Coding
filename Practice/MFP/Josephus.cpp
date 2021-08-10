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
	ll N;cin>>N;
	//if u look at the problem carefully there is a pattern associated with output
	//which is 1,1,3,1,3,5,7,1,3,5,7,9. . . 
	//i.e., whenever (n is a power of 2) the series restarts and continues till next power of 2, 
	//which implies for a given N we have to find the power of 2 which is less than N 
	//after which simply find the indx for the series element by subtracting the N from the pow of 2 and 
	//rth term of series is 2*r+1 so just put the calculated value in place r and get your answer 
	//and as we only have to find the power of 2 less than N so the Time Complexity will be O(log2(n))
	//and S.C -> O(1) as we are not using any variable space.

	//here the solution begins

  	long long p = 1;
    if(N<3){
    	cout<<"1\n";
    	return ;
    }
    
    while(p<N){
        
        p = p*2;
   	 }
    
    if(!(N&(N-1))){
    	cout<<"1\n";
        return;
    }else{
        p/=2;//because of overflow from the above while loop which make p > n 
    }

    //(N-p) is the index for the series 1,3,5,7,9....
    cout<<(2*(N-p)+1)<<endl;
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
