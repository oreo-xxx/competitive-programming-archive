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

int main() {
    ll n, m; cin >>n>> m;
    vector<vector<ll> >a(4), sum(4);
    ll w0, v0; cin >>w0>> v0;
    a[0].push_back(v0);
    for(int i = 1; i < n; ++i){
        ll w, v; cin >>w>> v;
        a[w-w0].push_back(v);
    }
    for(int i = 0; i < 4; ++i){
        sort(a[i].begin(), a[i].end(), greater<ll>() );
        sum[i].push_back(0);
        for(int j = 0; j < a[i].size(); ++j){
            sum[i].push_back(sum[i][j]+a[i][j]);
        }
    }
    ll ans = 0;
    for(int i = 0; i <= a[0].size(); ++i){
        ll tmp = sum[0][i];
        for(int j = 0; j <= a[1].size(); ++j){
            tmp += sum[1][j];
            for(int k = 0; k <= a[2].size(); ++k){
                tmp += sum[2][k];
                for(int l = 0; l <= a[3].size(); ++l){
                    tmp += sum[3][l];
                    ll w = (i+j+k+l)*w0;
                    w += j + 2*k +3*l;
                    if(w<= m){
                        ans=max(ans, tmp);
                    }
                    tmp -= sum[3][l];
                }
                tmp -= sum[2][k];
            }
            tmp -= sum[1][j];
        }
    }
    cout << ans << endl;
}
