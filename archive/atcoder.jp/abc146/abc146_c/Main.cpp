#include <bits/stdc++.h>

using namespace std;
using ll = unsigned long long;
using P = pair<ll, ll>;

const ll INF64 = 1LL << 60;
const int INF32 = 1 << 29;
const ll MOD = 1000000007;

const int CASES = 4;

ll a, b, x;

bool check(ll m){
    string tmp = to_string(m);
    ll keta = tmp.size();
    ll sum = a * m + b * keta;
    if(x < sum){
        return true;
    }
    else{
        return false;
    }
}

void solve() {
    cin >> a >> b >> x;

    ll lb = 0LL, ub = 1e9+1;
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

