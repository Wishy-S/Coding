#include<bits/stdc++.h>
using namespace std;
const int mxn = 1e5;
bool primes[mxn+1];
void sieve(){
	memset(primes,true,sizeof(primes));
	primes[1] = false;
	//first check all the nos. less than sqrt(LimitUpToWhichPrimesToBeCalculated)
	for(int i = 2;i*i<=mxn ;i++){
		
		if(primes[i]){
			for(int j = i*i;j<=mxn;j+=i)
				primes[j] = false;
			}	
	}
	
}
void segmented_sieve(int l,int r){
	bool sprime[r-l+1];
	memset(sprime,1,sizeof(sprime));
	for(int i = 2;i<=floor(sqrt(r));i++){
		//problem is how we can reach for L from left side
		
		
		
		for(int j = l;j<=r;j++){
			if(j!=i and  primes[i] and (j%i==0)){
				sprime[j-l]=0;
				}
			}
		}
	for(int i = l ;i<=r;i++){
		if(sprime[i-l])cout<<i<<' ';
	}
	cout<<"\n";
	
}
void solve(){
	int l,r;cin>>l>>r;
	
	
	segmented_sieve(l,r);
}
int main(){
	int t;
	cin>>t;
	sieve();
	while(t--){
		solve();
	}
}
