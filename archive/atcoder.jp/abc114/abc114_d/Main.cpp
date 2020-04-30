#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using P = pair<ll, ll>;

const ll INF64 = 1LL << 60;
const int INF32 = 1 << 29;
const int MOD = 1000000007;

const int CASES = 3;

vector<P> prime_factorize(ll n) {
    vector<P> res;
    for (ll p = 2; p * p <= n; ++p) {
        if (n % p != 0) continue;
        int num = 0;
        while (n % p == 0) { ++num; n /= p; }
        res.push_back(make_pair(p, num));
    }
    if (n != 1) res.push_back(make_pair(n, 1));
    return res;
}

map<ll, int> sisuu;

ll rec(map<ll, int>::iterator p, ll mul) {
    if (p == sisuu.end()) {
        if (mul == 1) return 1;
        else return 0;
    }

    ll res = 0;
    for (int i = 0; i < p->second + 1; ++i) {
        if (mul % (i+1) != 0) continue;
        res += rec(++p, mul / (i+1));
        --p;
    }
    return res;
}

void solve(){
    sisuu.clear();
    int N; cin >> N;
    for (int i = 2; i <= N; ++i) {
        auto ps = prime_factorize(i);
        for (auto it : ps){
            sisuu[it.first] += it.second;
        }
    }

    cout << rec(sisuu.begin(), 75) << endl;
    return;
}

int main() {
    #ifdef MYLOCAL
    vector<string> filenames {"input1.txt", "input2.txt", "input3.txt", "input4.txt"};
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

