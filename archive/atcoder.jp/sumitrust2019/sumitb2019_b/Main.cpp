#include <bits/stdc++.h>

using namespace std;
using ll = unsigned long long;
using P = pair<ll, ll>;

const ll INF64 = 1LL << 60;
const int INF32 = 1 << 29;
const ll MOD = 1000000007;

const int CASES = 3;

void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < 51000; ++i) {
        if(i * 108 / 100 == n){
            cout << i << endl;
            return ;
        }
    }
    cout << ":(" << endl;
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

