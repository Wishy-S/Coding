#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(v) v.begin(),v.end()
#define pii pair<int,int>
#define f first
#define s second
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);   
const int mod = 1e9+7;
bool comp(pair<ll,ll>&a,pair<ll,ll>&b){return a.first-a.second >= b.first-b.second;}
const int mxn = 1e7;
int primes[mxn+1];
void sieve(){
    for(int i = 0;i<=mxn;i++){
        primes[i] = 1;
    }
    primes[1] = 0;
    //first check all the nos. less than sqrt(LimitUpToWhichPrimesToBeCalculated)
    for(ll i = 2;i*i<=mxn ;i++){
        
        if(primes[i]==1){
            for(ll j = i*i;j<=mxn;j+=i)
                primes[j] = 0;
            }   
    }
    
}

ll modularExponentiation(long long int x,long long int n,long long int M)

{
ll result=1;

    while(n>0)

    {

        if(n % 2 ==1)

        result=(result * x)%M;

        x=(x*x)%M;

        n=n/2;

    }

return result;

}
ll cal(vector<ll>&a){
    ll res = a[0];
    for(ll i:a){
        res = __gcd(res,i);
    }
    return res;
}
void solve(){
    int n;cin>>n;vector<ll>v(n);for(ll &i:v)cin>>i;

    ll ans = 0;
    for(int i = 0;i<n;i++){
        for(int j = i+1;j<n;j++){
            ll a = v[i],b = v[j];
            ll mul = a*b;
            v[i] = v[j] = mul;
            ans = max(ans,cal(v));
            v[i] = a,v[j] = b;
        }
    }
    cout<<ans<<endl;
}


int main(){
    ll t;
    fastio;
    // sieve();
    t = 1;
    cin>>t;
    
    while(t--){
           solve();
    }
}