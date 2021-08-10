#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;
    int a[n];
    for(int i = 0;i<n;i++)cin>>a[i];
    
    int target ;
    cin>>target;
    
    //approach
    
    int l = 0,r = 0;
    int s = 0;
    
    while(r<n&&s<target){s+=a[r];if(s>=target)break; ++r;}
    s-=a[r];
    --r;
    if(s==target){ for(int i = l;i<=r;i++)cout<<a[i]<<' ';cout<<endl;}
    int min = INT_MAX;
    int R = 0,L = 0;
    while(r<n&&l<n){
       // cout<<s<<' '<<l<<' '<<r<<'\n';
        if(r+1<n){
            if(a[r+1]+s<=target){++r;s+=a[r];}
            else{
                s-=a[l];++l;
            }
        }else{break;}
        if(s==target){if(r-l+1<min){min = r-l+1;R = r;L = l;}}
 
    }
    if(s==target)
    {for(int i = L;i<=R;i++)cout<<a[i]<<' ';
    cout<<endl;}
    
	return 0;
}
