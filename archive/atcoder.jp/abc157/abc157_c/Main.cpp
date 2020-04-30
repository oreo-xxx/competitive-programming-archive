#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pint = pair<int, int>;
using pll = pair<ll, ll>;
using Edge = pair<int, ll>;
using Graph = vector<vector<int>>;
using WeightedGraph = vector<vector<Edge>>;
const ll INF64 = 1LL << 60;
const int INF32 = 1 << 29;
const ll MOD = 1000000007;

const int CASES = 3;

void solve() {
    ll N, M; cin >> N >> M;
    vector<ll> a(N);
    vector<bool> used(N, false);

    bool f = true;
    for(int i = 0; i < M; ++i){
        int s, c; cin >> s >> c;
        if(used[s-1] == true && a[s-1] != c){
            f = false;
            break;
        }
        a[s-1] = c;
        used[s-1] = true;
    }

    if(a[0] == 0 && N != 1){
        if(used[0] == true){
            f = false;
        }
        else{
            a[0] = 1;
        }
    }

    if(f){
        for (int i = 0; i < N; ++i) {
            cout << a[i];
        }
        cout << endl;
    }
    else{
        cout << -1 << endl;
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
