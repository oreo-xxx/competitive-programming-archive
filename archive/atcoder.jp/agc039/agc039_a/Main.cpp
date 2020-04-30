#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using P = pair<ll, ll>;

const ll INF64 = 1LL << 60;
const int INF32 = 1 << 29;
const int MOD = 1000000007;

const int CASES = 3;

void solve(){
    string S; ll K; cin >> S >> K;
    ll n = S.size();
    if(S[0] == S[n-1] && K > 1){
        ll l = 0, r = 0;
        for(int i = 0; i < n; ++i){
            if(S[i] == S[0]){
                ++l;
            }
            else{
                break;
            }
        }
        for(int i = n-1; i >= 0; --i){
            if(S[i] == S[n-1]){
                ++r;
            }
            else{
                break;
            }
        }
        if(l + r < n){
            ll ans1 = 0, ans2 = 0;
            S += S;
            for(int i = l; i < n - 1 - r; ++i){
                if(S[i] == S[i+1]){
                    S[i+1] = 'A';
                    ++ans1;
                }
            }
            for(int i = n - r; i < n + l; ++i){
                if(S[i] == S[i+1]){
                    S[i+1] = 'A';
                    ++ans2;
                }
            }
            cout << ans1 * K + ans2 * (K-1) + (l/2) + (r/2)<< endl;
        }
        else{
            ll ans = 0;
            S += S;
            for(int i = 0; i < 2 * n-1; ++i){
                if(S[i] == S[i+1]){
                    S[i+1] = 'A';
                    ++ans;
                }
            }
            ll tmp = 0;
            if(K % 2 == 1){
                tmp = (n/2);
            }
            cout << ans * (K/2) + tmp << endl;
        }
    }
    else{
        ll ans = 0;
        for(int i = 0; i < n-1; ++i){
            if(S[i] == S[i+1]){
                S[i+1] = 'A';
                ++ans;
            }
        }
        ll tmp = 0;
        if(S[0] == S[n-1]){
            tmp = K-1;
        }
        cout << ans * K + tmp<< endl;
    }
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

