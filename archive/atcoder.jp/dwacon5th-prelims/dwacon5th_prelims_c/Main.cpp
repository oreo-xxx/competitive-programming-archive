#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pint = pair<int, int>;
using pll = pair<ll, ll>;
//using Edge = pair<int, ll>;
//using Graph = vector<vector<int>>;
//using WeightedGraph = vector<vector<Edge>>;
const ll INF64 = 1LL << 60;
const int INF32 = 1 << 29;
const ll MOD = 1000000007;

const int CASES = 3;

string S;
long long m, c, t;

void add(int i) {
    if (S[i] == 'M'){
        ++m;
    }
    else if (S[i] == 'C') {
        ++c;
        t += m;
    }
}

void erase(int i) {
    if (S[i] == 'M'){
        --m;
        t -= c;
    }
    else if (S[i] == 'C'){
        --c;
    }
}

void solve() {
    int N;
    cin >> N >> S;
    int Q; cin >> Q;
    for (int i = 0; i < Q; ++i) {
        int k; cin >> k;
        ll ans = 0;
        m = 0; t = 0;

        int r = 0;
        for (int l = 0; l < N;) {
            while (r < N && r - l < k) add(r++);
            if (S[l] == 'D') ans += t;
            erase(l++);
        }
        cout << ans << endl;
    }
}

int main() {
#ifdef MYLOCAL
    vector<string> filenames {"input1.txt", "input2.txt", "input3.txt", "input4.txt", "input5.txt"};
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
