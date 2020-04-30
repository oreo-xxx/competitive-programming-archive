#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using P = pair<int, uint>;

const ll INF64 = 1LL << 60;
const int INF32 = 1 << 29;
const int MOD = 1000000007;

const int CASES = 2;


void solve(){
    int N, K; cin >> N >> K;
    vector<ll> A(N);
    for(int i = 0; i < N ; ++i) cin >> A[i];

    vector<ll> ands;
    for(int i = 0; i < N ; ++i){
        ll tmp = A[i];
        ands.push_back(tmp);
        for(int j = 1; i + j < N ; ++j){
            tmp += A[i + j];
            ands.push_back(tmp);
        }
    }

    ll ans = 0;
    for(ll i = 61; i >= 0; --i){
        vector<ll> vec;
        ll tmp = (1LL << i);
        for(int j = 0; j < ands.size(); ++j){
            if( (ands[j] & tmp) != 0){
                vec.push_back(ands[j]);
            }
        }

        if(vec.size() >= K){
            ands = vec;
            ans |= tmp;
        }
    }

    cout << ans << '\n';
}



int main() {
    #ifdef MYLOCAL
    vector<string> filenames {"input1.txt", "input2.txt", "input3.txt"};
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

