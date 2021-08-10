#include <bits/stdc++.h>
using namespace std;
int main(int argc,char** argv){
	//int n;//cin>>n;
	vector<int>permutation;
	//for(int i= 0;i<argc;i++){cout<<argv[i]<<' ';}
	//cout<<'\n';
	stringstream ss(argv[argc-1]);
	int n  = 2;
	ss>>n;
	for (int i = 1; i <= n; i++) {
	permutation.push_back(i);
	}
		do {
		// process permutation
		for(int i:permutation)cout<<i<<' ';
		
		cout<<'\n';
		} while (next_permutation(permutation.begin(),permutation.end()));	

}
