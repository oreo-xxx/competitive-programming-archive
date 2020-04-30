#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using P = pair<ll, ll>;

const ll INF64 = 1LL << 60;
const int INF32 = 1 << 29;
const int MOD = 1000000007;

void solve(){
    string S; int K; cin >> S >> K;
    int N = S.size();
    for(int i = 0; i < N; ++i){
        if(S[i] == 'a') continue;
        int nokori = 26 - (S[i] - 'a');
        if(nokori <= K){
            S[i] = 'a';
            K -= nokori;
        }
    }
    S[N - 1] = S[N - 1] + (K % 26);
    cout << S << '\n';
}



int main() {
    #ifdef MYLOCAL
    const int CASES = 3;
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

