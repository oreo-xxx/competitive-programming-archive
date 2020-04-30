#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pint = pair<int, int>;
using pll = pair<ll, ll>;
using Edge = pair<int, ll>;
using Graph = vector<vector<int>>;
using WeightedGraph = vector<vector<Edge>>;
const ll INF64 = 1LL << 60;
const int INF32 = 1 << 29;
const ll MOD = 1000000007;

const int CASES = 3;

void solve() {
    ll X, Y; cin >> X >> Y;
    ll A, B, C; cin >> A >> B >> C;
    vector<ll> p(A), q(B);
    priority_queue<ll> r;
    for(int i = 0; i < A; ++i)cin >> p[i];
    for(int i = 0; i < B; ++i)cin >> q[i];
    for(int i = 0; i < C; ++i){
        ll tmp; cin >> tmp;
        r.push(tmp);
    }
    sort(p.begin(), p.end(), greater<ll>());
    sort(q.begin(), q.end(), greater<ll>());

    priority_queue<ll,vector<ll>,greater<ll>> que;
    for(int i = 0; i < X; ++i){
        que.push(p[i]);
    }
    for(int i = 0; i < Y; ++i){
        que.push(q[i]);
    }
    for(int i = 0 ; i < C; ++i){
        ll q_ = que.top();
        ll r_ = r.top();
        if( q_ < r_){
            que.pop();
            que.push(r_);
            r.pop();
            r.push(q_);
        }
        else{
            break;
        }
    }
    ll ans = 0;
    for (int i = 0; i < X + Y; ++i) {
        ans += que.top();
        que.pop();
    }
    cout << ans << endl;
}

int main() {
#ifdef MYLOCAL
    vector<string> filenames {"input1.txt", "input2.txt", "input3.txt", "input4.txt", "input5.txt"};
    cout << "------------\n";
    for(int i = 0; i < CASES; ++i){
        ifstream in(filenames[i]);
        cin.rdbuf(in.rdbuf());
        solve();
        cout << "------------\n";
    }
#else

    solve();

#endif
    return 0;
}
