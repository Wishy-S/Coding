#include <bits/stdc++.h>
using namespace std;
int main(){
	int a[] = {1,3,4,5};
	int n = sizeof(a)/sizeof(a[0]);
	cout<<"indices: ";for(int i = 0;i<n;i++)cout<<i<<' ';
	cout<<'\n';
	cout<<"array:   "; 
	for(int i = 0;i<n;i++){
		cout<<a[i]<<' ';
		}
	cout<<'\n';
	int x = 2;
	auto lb = lower_bound(a,a+n,x); 
	auto ub = upper_bound(a,a+n,x);//in some sense you can say upper_bound(a,a+n,x) <=>  lower_bound(a,a+n,x+1);
	cout<<"LB: "<<lb-a<<'\n'<<"UB: "<<ub-a<<'\n';
}
