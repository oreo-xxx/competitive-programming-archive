#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using P = pair<ll, ll>;

const ll INF64 = 1LL << 60;
const int INF32 = 1 << 29;
const int MOD = 1000000007;

// Library

//
int n;
vector<ll> h;
vector<ll> s;

bool check(ll mb){
    double t[n];
    for(int i = 0; i < n; ++i) {
        if(mb < h[i]){
            return false;
        }
        t[i] = (double)(mb - h[i]) / s[i];
    }
    sort(t, t + n);
    for(int i = 0; i < n; ++i) {
        if(t[i] < i){
            return false;
        }
    }
    return true;
}
int main() {
#ifdef MYLOCAL
    ifstream in("input.txt");
    cin.rdbuf(in.rdbuf());
#endif
    cin >> n;
    h.resize(n);
    s.resize(n);
    for(int i = 0; i < n; ++i){
        cin >> h[i] >> s[i];
    }

    ll lb = 0, ub = INF64;
    while(ub - lb > 1){
        ll mb = (lb + ub) / 2;
        if(check(mb)){
            ub = mb;
        }else{
            lb = mb;
        }
    }

    cout << ub << endl;
    return 0;
}

