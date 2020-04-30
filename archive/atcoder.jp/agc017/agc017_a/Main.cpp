#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using P = pair<ll, ll>;

const ll INF64 = 1LL << 60;
const int INF32 = 1 << 29;
const int MOD = 1000000007;

const int CASES = 4;

void solve(){
    int N, P; cin >> N >> P;
    ll even=0, odd=0;
    for(int i = 0; i < N; ++i){
        int A; cin >> A;
        if(A % 2 == 0) ++even;
        else ++odd;
    }
    ll ans = 0;
    if(P == 0){
        ll tmp = 1LL;
        for(ll i = 0; i <= odd; ++i){
            if(odd != 0){
                tmp *= (odd - i);
                tmp /= (i + 1LL);
            }
            if(i % 2 == 0){
                ans += (tmp * (1LL << even));
            }
        }
    }
    else{
        ll tmp = 1LL;
        for(ll i = 0; i <= odd; ++i){
            tmp *= (odd - i);
            tmp /= (i + 1LL);
            if(i % 2 == 0){
                ans += (tmp * (1LL << even));
            }
        }
    }
    cout << ans << '\n';

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

