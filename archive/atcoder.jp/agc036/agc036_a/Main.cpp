#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using P = pair<ll, ll>;

const ll INF64 = 1LL << 60;
const int INF32 = 1 << 29;
const int MOD = 1000000007;

const int CASES = 3;

void solve(){
    ll S;
    cin >> S;

    ll x1 = 10e8, y1 = 0, x2 = 0, y2 = 0;
    y2 = (S / x1);
    if(y2 < 10e8){
        ++y2;
    }
    ll sum = x1 * y2 - S;
    // S = x1 * y2 - x2 * y1
    for(ll i = 1; i <= 10e9; ++i){
        y1 = i;
        if(sum % y1 != 0) continue;
        x2 = sum / y1;
        if(x2 <= 10e8){
            break;
        }
    }
    cout << "0 0 " << x1 << " " << y1 <<  " " << x2 <<  " " << y2 << '\n';
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

