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
    int n; cin >> n;
    int s = 1, u, v;
    //sから最も遠い　u を求める
    int ma = 0;
    for (int i = 1; i <= n; ++i){
        if(s != i){
            int dist;
            cout << "? " << s << " " << i << endl;
            cin >> dist;
            if(dist > ma){
                ma = max(ma, dist);
                u = i;
            }
        }
    }

    //uから最も遠いvまでの距離が木の直径となる
    int ans = 0;
    for (int i = 1; i <= n; ++i){
        if(u != i){
            int dist;
            cout << "? " << u << " " << i << endl;
            cin >> dist;
            if(dist > ans){
                ans = max(ans, dist);
            }
        }
    }
    cout << "!" << " " << ans << endl;
    return 0;
}