#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e9+7;
bool comp(pair<ll,ll>&a,pair<ll,ll>&b){return a.first-a.second >= b.first-b.second;}
ll GCD(vector<int>&v){
    ll res = v[0];

    for(int i:v){
        res = __gcd((ll)i,res);
    }
    return res;
}
ll MUL(vector<int>&v){
    ll res = 1;
    for(int i:v){
        res = ((res%mod) * (i%mod))%mod;
    }

    return res;
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

}
int main(){
       int t;
       //cin>>t;
       t = 1;
       while(t--){
           solve();
       }
}