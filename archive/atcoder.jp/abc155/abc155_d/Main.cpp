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

ll N, K;
vector<ll> a, b, c;

bool check(ll mb){
    ll an = a.size();
    ll bn = b.size();
    ll cn = c.size();
    ll total = 0LL;
    if(mb <= 0){
        for (int i = 0; i < an; ++i) {
            ll tmp = mb / a[i];
            ll idx = lower_bound(b.begin(), b.end(), tmp) - b.begin();
            total += idx;
        }
    }
    else{
        for (ll i = 0; i < an; ++i) {
            ll tmp = (mb+a[i]-1LL) / a[i];
            ll idx = lower_bound(a.begin(), a.end(), tmp) - a.begin();
            idx = max(0LL, idx -1LL - i);
            total += idx;
        }
        ll SUM = bn * (bn-1)/2LL;
        for (ll i = 0; i < bn; ++i) {
            ll tmp = (mb-b[i]-1LL) / b[i];
            int idx = upper_bound(b.begin(), b.end(), tmp) - b.begin();
            if(idx < i) SUM -= idx;
            else SUM -= i;
        }
        total += SUM;
        total += an * bn;
        total += cn * (cn-1LL) / 2LL + cn * an + cn * bn;
    }
    //cout << mb << " " << total << endl;
    if(total < K){
        return false;
    }
    return true;
}


void solve() {
    cin >> N >> K;
    a.clear();
    b.clear();
    c.clear();

    for(int i = 0; i < N; ++i){
        ll tmp; cin >> tmp;
        if(tmp > 0LL) a.push_back(tmp);
        else if(tmp == 0LL) c.push_back(tmp);
        else b.push_back(tmp);
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    ll lb = -INF64, ub = INF64;
    while(ub - lb > 1LL){
        ll mb = (lb + ub) / 2LL;
        if(check(mb)){
            ub = mb;
        }else{
            lb = mb;
        }
    }
    cout << lb << endl;
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
