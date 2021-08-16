#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define all(v) v.begin(),v.end()
#define pb(x) push_back(x)
#define f first
#define s second
#define vt vector
#define boost ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);  
const ll mod = 1e9+7;
const int d4i[4]={-1, 0, 1, 0}, d4j[4]={0, 1, 0, -1};
const int d8i[8]={-1, -1, 0, 1, 1, 1, 0, -1}, d8j[8]={0, 1, 1, 1, 0, -1, -1, -1};
ll power(ll x,unsigned ll y,ll p){
     ll res = 1;     // Initialize result
 
    x = x % p; // Update x if it is more than or
                // equal to p
  
    if (x == 0) return 0; // In case x is divisible by p;
 
    while (y > 0)
    {
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res*x) % p;
 
        // y must be even now
        y = y>>1; // y = y/2
        x = (x*x) % p;
    }
    return res;
}
int gcd(int a,int b){
    if(b==0)return a;
    
    return gcd(b,a%b);
}
 bool isValid(int x,int y,int N){
        return x>=0 and x<N and y>=0 and y<N;
    }
    
    
int minimumCostPath(vector<vector<int>>& grid) 
{
    // Code here
    int n = grid.size();
    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
    pq.push({grid[0][0],{0,0}});
    vector<vector<int>>cost(n,vector<int>(n,INT_MAX));
    
    while(!pq.empty()){
        auto p = pq.top();
        pq.pop();
        int cur_x = p.s.f , cur_y = p.s.s;
        int cur_wt = p.f;
        if(cur_x == n-1 and cur_y == n-1){
            return cost[cur_x][cur_y];
        }
        //if cost to reach current cell is greater than ( the cost to reach any of its valid adjacent cells + cost for that cell)
                //then update the cost to reach that cell
                
                
        for(int i = 0;i<4;i++){
            int nx = d4i[i]+cur_x,ny = d4j[i]+cur_y;
            if(isValid(nx,ny,n)){

                if(grid[nx][ny] + cur_wt < cost[nx][ny]){
                    
                    cost[nx][ny] = cur_wt + grid[nx][ny];
                    
                    pq.push({cost[nx][ny],{nx,ny}});
                }
            }
        }
    }
    // for(int i = 0;i<n;i++){
    //     for(int j=0;j<n;j++){
    //         cout<<wt[i][j]<<' ';
    //     }
    //     cout<<endl;
    // }
    return cost[n-1][n-1];
}
void solve(){
    int n;cin>>n;
    vector<vector<int>>g(n,vector<int>(n));
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            cin>>g[i][j];
        }
    }
    cout<<minimumCostPath(g)<<endl;
}
int main()
{   boost;
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
