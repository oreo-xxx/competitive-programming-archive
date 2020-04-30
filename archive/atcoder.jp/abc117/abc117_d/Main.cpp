#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int,  int>;

const ll INF = 1LL << 60;
const int INF32 = 1 << 29;
const ll MOD = 1000000007;

const int MAX_DIGIT = 50;
long long dp[100][2]; // dp[上から i 桁まで][ smaller ]

int main(){
    int n; ll k;
    cin >> n >> k;
    vector<ll> a(n);
    for(int i = 0; i < n; ++i){cin >> a[i];}
    memset(dp,-1,sizeof(dp));
    dp[0][0] = 0;
    for(int i = 0; i < 50; ++i){
        ll mask = (1LL << (49-i));
        
        int num=0;
        for(int j = 0; j< n; ++j){
            if(a[j]&mask){++num; }
        }
        ll cost0 = mask * num;
        ll cost1 = mask* (n-num);
        
        // smaller -> smaller
        if (dp[i][1] != -1) {
            dp[i+1][1]=max(dp[i+1][1], dp[i][1] + max(cost0, cost1)); // 0 でも 1 でも自在に大きい方
        }
        
         // exact -> smaller
        if (dp[i][0] != -1) {
            if (k & mask) { // K の i 桁目が 1 だったら、X の i 桁目は 0 にする
                dp[i+1][1] = max(dp[i+1][1], dp[i][0] + cost0);
            }
        }
        
         // exact -> exact (K にぴったり合わせる)
        if (dp[i][0] != -1) {
            if (k & mask) {
                 dp[i+1][0]=max(dp[i+1][0], dp[i][0] + cost1);
            }
            else dp[i+1][0]=max(dp[i+1][0], dp[i][0] + cost0);
        }
        
    }
    cout << max(dp[50][0], dp[50][1]) << endl;
    return 0; 
}
