#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
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
    ll N, M; cin >> N >> M;
    vector<ll> vec(M);
    map<ll, ll> mp;
    vector<ll> pairs(M);
    for(int i = 0; i < N; ++i){
        ll a; cin >> a;
        ++vec[a%M];
        ++mp[a];
        if(mp[a]%2==0) ++pairs[a%M];
    }
    ll ans = 0;
    for(ll i = 0; i < M; ++i){
        ll j = (M - i)%M;
        if(i>j) break;
        if(i==j){
            ans += vec[i]/2;
            continue;
        }
        ll idx = i, idx2 = j;
        if(vec[i] < vec[j]) swap(idx, idx2);
        else if(vec[i] == vec[j] && pairs[i] < pairs[j]) swap(idx, idx2);

        ans += vec[idx2];
        ll diff = vec[idx] - vec[idx2];
        diff /= 2;
        ans += min(diff, pairs[idx]);
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
