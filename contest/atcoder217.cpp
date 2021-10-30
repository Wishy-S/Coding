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
ll sumofFactors(ll n)
{
    // Traversing through all prime factors.
    ll res = 1, N = n;
    for (int i = 2; i <= sqrt(n); i++)
    {
 
         
        ll curr_sum = 1;
        ll curr_term = 1;
        while (n % i == 0) {
 
            // THE BELOW STATEMENT MAKES
            // IT BETTER THAN ABOVE METHOD
            //  AS WE REDUCE VALUE OF n.
            n = n / i;
 
            curr_term *= i;
            curr_sum += curr_term;
        }
 
        res *= curr_sum;
    }
 
    // This condition is to handle
    // the case when n is a prime
    // number greater than 2.
    if (n >= 2)
        res *= (1+n);
 
    return res-N;
}
ll mySumOfFactors(ll n){
    ll res = 1;

    for(ll i = 2;i*i<=n;i++){
        ll cur = 1,tmp = 1;
        // cout<<i<<' ';
        while(n%i==0){
            n/=i;
            cur*=i;

            // cout<<cur<<' ';

            tmp+=cur;
        }
        cout<<'\n';
        // cout<<tmp<<' ';
        res*=tmp;
    }

    // cout<<endl;

    if(n>=2){
        // it is like p1^0 + p1^1 where  p1 is the remaining prime which is >= 2 and still remaining 
        res*=(n+1);
    }

    return res;
}
void solve(){
    ll n;cin>>n;
    cout<<mySumOfFactors(n)-n<<endl;
}


int main(){
    ll t;
    // sieve();
    
    t = 1;
    cin>>t;
    
    while(t--){
           solve();
    }
}