#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using P = pair<ll, ll>;

const ll INF64 = 1LL << 60;
const int INF32 = 1 << 29;
const int MOD = 1000000007;

void solve(){
    int N; cin >> N;
    vector<int> A(N);
    vector<int> alt(N);
    for(int i = 0; i < N ; ++i){
        cin >> A[i];
        alt[i] = A[i];
    }

    sort(alt.begin(), alt.end());

    int ans = 0;
    for (int i = 0; i < N; ++i) {
        int it = lower_bound(alt.begin(), alt.end(), A[i]) - alt.begin();
        if (abs(it - i) % 2 == 1) ans++;
    }

    cout << ans/2 << '\n';
}



int main() {
    #ifdef MYLOCAL
    const int CASES = 2;
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

