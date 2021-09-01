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

int findIndx(vector<int>&v,int l,int r,int k){
    while(l<r-1){
        int m = l+(r-l)/2;
        if(k<=v[m]){
            r = m;
        }else{
            l = m;
        }
    }
    return r;
}
int LIS(vector<int>&v,int n){
	//in case if u want to find the Longest Decreasing Subsequence then u can just reverse the array and follow the same 
	//you will get your answer

	int len = 1;
	vector<int>tail(n,0);
	
	tail[0] = v[0];

	for(int i = 1;i<n;i++){
		
		int ele = v[i];

		if(ele < tail[0]){
			tail[0] = ele;
		}else if(ele > tail[len-1]){
			//make another list cloning and deleting the same size one
			//actually same size one get over written if any
			tail[len++] = ele;
		}else{
			//find the indx of the list in which you have to put this curr element 
			//you can do this using binary search as we are maintaining a sorted list of end elements in tail
			int indx = findIndx(tail,0,len-1,ele);
			tail[indx] = ele;

		}
	}

	return len;
}
void solve(){
	int n;cin>>n;vector<int>v(n);for(int &i:v)cin>>i;
	cout<<LIS(v,n)<<endl;	
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
