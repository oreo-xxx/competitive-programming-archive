#include <bits/stdc++.h>

using namespace std;
using ll = unsigned long long;
using P = pair<ll, ll>;

const ll INF64 = 1LL << 60;
const int INF32 = 1 << 29;
const ll MOD = 1000000007;


const int CASES = 3;

vector<vector<int> > calcNext(const string &S) {
    int n = (int)S.size();
    vector<vector<int> > res(n+1, vector<int>(10, n));
    for (int i = n-1; i >= 0; --i) {
        for (int j = 0; j < 10; ++j) res[i][j] = res[i+1][j];
        res[i][S[i]-'0'] = i;
    }
    return res;
}


void solve() {
    int n; string s;
    cin >> n >> s;

    vector<set<char> > sumr(n);
    for (int i = n-1; i >= 0; --i) {
        sumr[0].insert(s[i]);
        sumr[i] = sumr[0];
    }

    int ans = 0;
    set<char> used1;
    for (int i = 0; i < n-2; ++i) {
        if(used1.count(s[i]) != 0) continue;

        set<char> used2;
        for (int j = i+1; j < n-1; ++j) {
            if(used2.count(s[j]) != 0) continue;
            ans += sumr[j+1].size();
            used2.insert(s[j]);
        }

        used1.insert(s[i]);
    }
    cout << ans << endl;
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

