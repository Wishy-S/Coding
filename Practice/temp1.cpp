#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long int
#define ld long double
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define mt make_tuple
#define itf it->first
#define its it->second
#define fo(i,a,b) for(i=a;i<(ll)b;++i)
#define foe(i,a,b) for(i=a;i<=(ll)b;++i)
#define rfo(i,a,b) for(i=a;i>(ll)b;--i)
#define rfoe(i,a,b) for(i=a;i>=(ll)b;--i)
#define trans(x) for(auto &val:x)
#define all(x) x.begin(), x.end()
#define itoj(x,i,j) x.begin()+i,x.begin()+j
#define uniq(x) x.erase(unique(x.begin(),x.end()),x.end())
#define subv(x,i,j) vector<long long int>(x.begin()+i,x.begin()+j)
#define subs(x,i,j) string(x.begin()+i,x.begin()+j)
#define vll vector <long long int>
#define mll map<long long int, long long int>
#define umll unordered_map<long long int, long long int>
#define pll pair <long long int, long long int>
#define pqll priority_queue<long long int>
#define vpll vector <pair<long long int, long long int>>
#define ub(x,k) upper_bound(x.begin(),x.end(),k)
#define lb(x,k) lower_bound(x.begin(),x.end(),k)
#define boost ios::sync_with_stdio(false); cin.tie(nullptr);cout.tie(nullptr)
#define time (chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now()-STi).count())*(1e-9)
#define ret(x) {cout<<x; return;}
#define cnt1(x) __builtin_popcountll(x)
#define lsb(x) __builtin_ffsll(x)
#define ctz(x) __builtin_ctzll(x)
#define inv(x) vector<ll> x(n);trans(x)cin>>val;
#define ins(x) vector<string> x(n);trans(x)cin>>val;
#define endl "\n"

const auto STi =chrono::high_resolution_clock::now();
const ll MOD =1000000007;
const ll M =1000001;

ll mul(ll x, ll y, ll m=MOD) {ll res=0;x%=m; while(y){ if(y&1)res=(res+x)%m; x=(2*x)%m;y>>=1;}return res;} 



map<ll,ll> m;
vector<ll> v(M);

ll fun (ll n){
if(n<M) return v[n];
ll l=m[n];
if(l) return l;
 l=n/2;
  l=  (     mul(fun(l),fun(n-l))
      + mul(4*fun(l-2),fun(n-l-1))
      + mul(4*fun(l-1),fun(n-l-2))
      +   mul(fun(l-1),fun(n-l-1)) )%MOD  ;   
   m[n]=l;
return l;
}


const ll mxn = 1e5;
const ll mod = 1e9+7;
const ll mod2 = mod*mod;
void multiply(ll a[3][3],ll b[3][3]) 
{ 
    ll mul[3][3]; 
    for (int i = 0; i < 3; i++) 
    { 
        for (int j = 0; j < 3; j++) 
        { 
            ll tmp = 0;
            for (int k = 0; k < 3; k++){ 
                tmp += a[i][k]*b[k][j];
            }
            mul[i][j] = tmp%mod;
        }
    }
    for (int i=0; i<3; i++) 
    for (int j=0; j<3; j++) 
        a[i][j] = mul[i][j];
}
ll power(ll F[3][3],ll n){
    ll M[3][3] = {{1,0,0}, {0,1,0}, {0,0,1}}; 
    while(n>0){
        if(n&1){
         multiply(M,F);
        }
        n=n>>1;
        multiply(F,F);
    }
    return (7*M[0][0] + 2*M[0][1] + M[0][2]); 
}
ll answer(ll n) 
{ 
    ll F[3][3] = {{1,1,4}, {1,0,0}, {0,1,0}} ; 
 
    if(n==1) 
    return 1;
    if(n==2)
    return 2;
    if(n==3)
    return 7;
  
    return power(F,n-3)%MOD;
} 



int main()
{      boost;  ll j;
     v[1]=1; v[2]=2; v[3]=7;
fo(j,4,M)
v[j]=(v[j-1]+v[j-2]+4*v[j-3])%MOD;

int t;cin>>t;
while(t--){ll n;cin>>n;
	cout<<fun(n)<<'\n';
	}
   return 0; 
  }
