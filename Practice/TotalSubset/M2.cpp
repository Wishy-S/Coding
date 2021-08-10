#include <bits/stdc++.h>
using namespace std;
int main(){
	int n;cin>>n;
	//let's say we want to print all subsets of {0,1,2} which are 2^(sizeofset)-1
	//Now if we look carefully the binary pattern of nos. from 0 to  2^(sizeofset)-1
	//for the given example sizeofset is 3 so 0 to 7
	//000 => phi
	//001 => {2}
	//010 => {1}
	//011 => {1,2}
	//100 => {0}
	//101 => {0,2}
	//110 => {0,1}
	//111 => {0,1,2}
	//The pattern is like 1 means the corresponding no. is present in the subset 
	//and 0 means it is not
	//i < 2^n
	
	for(int i = 0 ;i<(1<<n);i++){
		
		vector<int>subset;
		
		for(int j=0;j<n;j++){
			if(i&(1<<j))subset.push_back(j);
			}
			
		
		for(int i:subset)cout<<i<<' ';
		
		cout<<endl;
	}
	
	
}
