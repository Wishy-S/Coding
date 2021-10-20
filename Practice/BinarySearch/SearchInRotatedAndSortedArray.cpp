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
int search(vt<ll>&arr, int n, int k)
{
    //Write your code here
    int l = 0,r = n-1;
    while(l<=r){
        int m = l+(r-l)/2;
        if(arr[m]==k){
            return m;
        }
        
        //looking for the part of the array in which we are 
        //like after rotating the array is divided into 2 sorted subarrays
        //So by checking the left most element with the middle element we can check
        //whether we are in the left sorted part or in the right sorted part 
        
        //e.g -- >    	4,5,6  1,2,3   ( left sorted array    right sorted subarray )
        
        else if(arr[m] < arr[l]){// this tells us that the mid element lies in the right subarray            
            //now check where the key value lies 
            //if it's within the range of the middle_ele and rightmost_ele then make the l = m+1;
            if(k<=arr[r] and k>=arr[m]){
                l = m+1;
            }else{
                r = m-1;
            }
            
        }else{//in the left subarray
            if(k>=arr[l] and k<=arr[m]){
               r = m-1;
            }else
               l = m+1;
        }
    }
    return -1;
}
void solve(){
	int n;cin>>n;
	vt<ll>v(n);for(ll &i:v)cin>>i;

	int q;cin>>q;
	while(q-->0){
		int k;cin>>k;
		cout<<search(v,n,k)<<'';
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
