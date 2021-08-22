#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define all(v) v.begin(),v.end()
#define allr(v) v.rbegin(),v.rend()
#define pb(x) push_back(x)
#define f first
#define s second
#define vt vector
#define boost ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);  
bool check(queue<char>s,string t){
	for(int i = 0;!s.empty() and i<t.length();i++){
		if(s.front() == t[i]){
			return 0;
		}
		s.pop();
	}
	return 1;
}
bool altcheck(string s,string t){
	for(int i = 0;i<t.length();i++){
		if(s[i] == t[i]){
			return 0;
		}
	}
	return 1;
}

void solve(){
	string s;cin>>s;
	string res = "";
	map<char,int>mp;
	for(char i:s)++mp[i-'a'];
	
	int n = s.length();
	

	for(char i='a';i<='z';i++){
		if(mp[i-'a']>n/2){
			cout<<"IMPOSSIBLE\n";return;
		}
	}

	for(char i='a';i<='z';i++){
		int f = mp[i-'a'], j = 0;
		
		while(f>0 and j<n and i!=s[j]){
			res+=i;
			--f;
			++j;
		}
		mp[i-'a']=f;
	}

		cout<<res<<endl;
	if(altcheck(s,res)){
	
	cout<<res<<endl;}
	else{
		cout<<"IMPOSSIBLE\n";return;
	}
}
int main()
{	boost;
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	t = 1;
	cin>>t;
	//cin>>t>>n>>q;
	//clock_t clk = clock();
	for(int i = 0;i<t;i++){
		cout<<"Case #"<<i+1<<": ";
		solve();
		}
	
	//clk = clock()-clk;
	//cout<<"TIME CONSUMED: "<<(float)(clk)/CLOCKS_PER_SEC<<"sec\n";
}
