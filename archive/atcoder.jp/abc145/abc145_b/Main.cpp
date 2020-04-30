#include <bits/stdc++.h>

using namespace std;
using ll = unsigned long long;
using P = pair<int, int>;

const ll INF64 = 1LL << 60;
const int INF = 1 << 29;
const ll MOD = 998244353;

const int CASES = 3;

void solve() {
    int n; string s;
    cin >> n >> s;
    if(n % 2 == 1){
        cout << "No" << endl;
        return ;
    }
    int half = n/2;
    for(int i = 0; i < half; ++i){
        if(s[i] != s[i+half]){
            cout << "No" << endl;
            return ;
        }
    }
    cout << "Yes" << endl;
    return ;
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

