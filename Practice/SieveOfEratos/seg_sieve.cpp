#include <bits/stdc++.h>
using namespace std;
#define vt vector
#define ll long long
const int MAX = 1e6+1;

vector<int>primes;
void sieve(){
	bool isPrime[MAX];
	for(int i = 0;i<=MAX;i++){
			isPrime[i] = true;
		}
	isPrime[0] = isPrime[1] = 0;
	
	for(int i = 2;i*i<=MAX;i++){
		if(isPrime[i]){
			for(int j = i*i;j<=MAX;j+=i){
				isPrime[j] = false;
				}
			}
		}
	for(int i = 1;i<=MAX;i++){
		if(isPrime[i])primes.push_back(i);
	}
	//cout<<'\n';
	
}
// r-l <= 1e6;

void getPrimesInRange(ll l,ll r){
	bool isPrime[r-l+1];
	for(int i = 0;i<=r-l;i++)isPrime[i] = 1;
	
	for(int i = 0;primes[i]*primes[i]<=r;i++){
		int cp = primes[i];
		int base = (l/cp)*cp;
		if(base<l){
			base+=cp;
		}
		for(int j = base;j<=r;j+=cp){
			isPrime[j-l] = 0;
			}
		if(base == cp){
			isPrime[base-l] = 1;
			}
	}
	if(l == 1){isPrime[0] = 0;}
	
	for(int i = 0;i<=r-l;i++){
		if(isPrime[i])cout<<i+l<<' ';
		}
	cout<<'\n';
	
}
int main(){
	sieve();
	
	ll l,r;cin>>l>>r;
	getPrimesInRange(l,r);
}
