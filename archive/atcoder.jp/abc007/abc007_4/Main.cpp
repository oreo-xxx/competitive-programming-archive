#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pint = pair<int,  int>;
using edge = int;
using graph = vector<vector<edge>>;
const ll INF = 1LL << 60;
const int INF32 = 1 << 29;
const ll MOD = 1000000007;

string A, B;
ll dp[100][2][2][2];
ll dp2[100][2][2][2];
int main() {
    ll a;
    cin >> a >> B;
    --a;
    A=to_string(a);
    int n = A.size();
    dp[0][0][0][0]= 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++){
              for (int m = 0; m < 2; m++){
                int x = j ? 9 : A[i] - '0';
                for (int d = 0; d <= x; d++) {
                    dp[i + 1][j || d < x][k || d == 4][m || d==9] += dp[i][j][k][m];
                }
              }
            }
        }
    }
  
    int n2 = B.size();
    dp2[0][0][0][0]= 1;
    for (int i = 0; i < n2; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++){
              for (int m = 0; m < 2; m++){
                int x = j ? 9 : B[i] - '0';
                for (int d = 0; d <= x; d++) {
                    dp2[i + 1][j || d < x][k || d == 4][m || d==9] += dp2[i][j][k][m];
                }
              }
            }
        }
    }
  
    ll ans = 0;
    for (int j = 0; j < 2; j++) {
        ans += dp2[n2][j][0][1];
        ans += dp2[n2][j][1][0];
        ans += dp2[n2][j][1][1];
        ans -= dp[n][j][0][1];
        ans -= dp[n][j][1][0];
        ans -= dp[n][j][1][1];
    }
    cout << ans << endl;
}