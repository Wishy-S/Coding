#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define all(v) v.begin(),v.end()
#define pb(x) push_back(x)
#define f first
#define s second
#define vt vector
#define boost ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);  
//longest pallindromic subsequence
//state: L(i,j) -> longest pallindromic subsequence in the string starting from i and ending at j;
//
//base case : if i==j then L(i,i) = 1;
//if(s[i]==s[j] and i+1==j) then L(i,j) = 2;
//else
//L(i,j) = max(L(i-1,j),L(i,j-1)); 

//adding memoisation for string 0 <= length <=3000
int memo[3001][3001];

//here passing the string by reference is a very crucial point!!!!!!!
//makes your code even faster if passed by reference
int lps(string &s,int i,int j){
	if(i>j)return 0;
	if(memo[i][j]==-1){

	if(i == j)return 1;


	if(s[i]==s[j]){
		memo[i][j] = lps(s,i+1,j-1)+2;
	}else
	memo[i][j] = max(lps(s,i+1,j),lps(s,i,j-1));
	
	}
	return memo[i][j];
}
int tabulation_lps(string s){
        int n = s.length();
        int L[n][n];
        memset(L,0,sizeof(L));
        for(int i = 0;i<n;i++)L[i][i] = 1;
        
        for(int i = n-1;i>=0;i--){
            for(int j = i+1;j<n;j++){
               if(s[i]==s[j]){
                    L[i][j] = L[i+1][j-1]+2;
                }else{
                    L[i][j] = max(L[i+1][j],L[i][j-1]);
                }
            }
        }
        
        return L[0][n-1];
    }

//tabulation space complexity modified using 1-D array instead of 2-D 
int tabulation_lps_modified(string &s){
    int n = s.length();
    int L[n];
    for(int i = n-1;i>=0;i--){
        int b = 0;
        for(int j = i ;j<n;j++){
            if(j==i){
                L[i] = 1;
            }else if(s[i]==s[j]){
                int t = L[j];
                L[j] = b+2;
                b = t;
            }else{
                b = L[j];
                L[j] = max(L[j-1],L[j]);
            }
        }
    }
    return L[n-1];
}
//without memo
int lps_without_memo(string &seq, int i, int j)
{
// Base Case 1: If there is only 1 character
if (i == j)
    return 1;
 
// Base Case 2: If there are only 2
// characters and both are same
if (seq[i] == seq[j] && i + 1 == j)
    return 2;
 
// If the first and last characters match
if (seq[i] == seq[j])
    return lps_without_memo(seq, i+1, j-1) + 2;
 
// If the first and last characters do not match
return max( lps_without_memo(seq, i, j-1), lps_without_memo(seq, i+1, j) );
}
void solve(){
	string s;cin>>s;
	
	memset(memo,-1,sizeof(memo));
	int n = s.length();
	// cout<<lps_without_memo(s,0,n-1)<<endl;
	cout<<tabulation_lps_modified(s)<<endl;
	// cout<<n<<endl;
}
int main()
{	boost;
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	t = 1;
	// cin>>t;
	//cin>>t>>n>>q;
	//clock_t clk = clock();
	for(int i = 0;i<t;i++){
		//cout<<"Case #"<<i+1<<": ";
		solve();
		}
	
	//clk = clock()-clk;
	//cout<<"TIME CONSUMED: "<<(float)(clk)/CLOCKS_PER_SEC<<"sec\n";
}
