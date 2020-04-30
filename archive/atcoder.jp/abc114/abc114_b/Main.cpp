#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using P = pair<ll, ll>;

const ll INF64 = 1LL << 60;
const int INF32 = 1 << 29;
const int MOD = 1000000007;

const int CASES = 3;

ll dp[1100][5000];

void solve(){
    string S; cin >> S;
    int n = S.size();
    vector<int> vec;
    for(int i = 0; i < n-2; ++i){
        int a = (int)(S[i] - '0');
        int b = (int)(S[i+1] - '0');
        int c = (int)(S[i+2] - '0');
        int tmp = 100 * a + 10 * b + c;
        vec.push_back(abs(tmp-753));
    }
    sort(vec.begin(), vec.end());
    cout << vec[0] << endl;
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

