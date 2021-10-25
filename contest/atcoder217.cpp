#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(v) v.begin(),v.end()
#define pii pair<int,int>
#define f first
#define s second
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
void solve(){
    int n ;cin>>n;string s;cin>>s;
    int ans = INT_MAX;
    for(char c = 'a';c<='z';c++){
        int l = 0 , r = n-1,cans = 0;
        while(l<=r){
            if(s[l] == s[r]){
                ++l;--r;
            }else {
                if(s[l] == c){
                    ++l;
                    cans++;
                }else if(s[r] == c){
                    --r;
                    cans++;
                }else{
                    cans = INT_MAX;break;
                }
            }
            if(cans == INT_MAX){
                break;
            }

        }
        ans = min(ans,cans);
    }
    if(ans == INT_MAX){
        cout<<"-1\n";
    }else{
        cout<<ans<<'\n';
    }
}
int main(){
    ll t;
    t = 1;
    cin>>t;
    
    while(t--){
           solve();
    }
}