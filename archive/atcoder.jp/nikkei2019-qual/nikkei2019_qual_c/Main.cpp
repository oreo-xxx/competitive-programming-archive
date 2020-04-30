#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using P = pair<ll, ll>;

const ll INF64 = 1LL << 60;
const int INF32 = 1 << 29;
const int MOD = 1000000007;

bool comp(P a, P b) { return a.second > b.second; }

void solve(){
    int N; cin >> N;
    vector<ll> A(N), B(N);
    vector<P> AB(N);
    for(int i = 0; i < N ; ++i){
        cin >> A[i] >> B[i];
        AB[i] = {i, A[i] + B[i]};
    }
    sort(AB.begin(), AB.end(), comp);

    ll ans = 0;
    for(int i = 0; i < N ; ++i){
        if(i % 2 == 0) {
            ans += A[AB[i].first];
        }
        else{
            ans -= B[AB[i].first];
        }
    }
    cout << ans << '\n';
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

