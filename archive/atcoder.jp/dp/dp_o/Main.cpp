#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int,  int>;

const ll INF = 1LL << 60;
const int INF32 = 1 << 29;
const ll MOD = 1000000007;

#define bit(n,k) ((n>>k)&1) /*nのk bit目*/

ll dp[22][1<<22];
int main(){
     int n;cin >>n;
     static vector<vector<int> > a(n, vector<int> (n)); 
     for(int i = 0; i < n; ++i){
         for(int j = 0; j < n; ++j){
              cin >>a[i][j];
         }
    }
     dp[0][0]=1;
     
     for(int S = 0; S < (1<<n); ++S){
         int i = __builtin_popcount(S);
         for(int j = 0; j < n; ++j){
             if(bit(S, j)==1 && a[i-1][j]==1){
                 dp[i][S]=(dp[i][S]+dp[i-1][S^(1<<j)])%MOD;
            }
         }
    }
    

   ll ans=dp[n][(1<<n)-1];
    
    cout << ans << endl;
}