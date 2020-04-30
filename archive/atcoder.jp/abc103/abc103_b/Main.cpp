#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using P = pair<ll, ll>;

const ll INF64 = 1LL << 60;
const int INF32 = 1 << 29;
const int MOD = 1000000007;

// Library

//
int main() {
#ifdef MYLOCAL
    ifstream in("input.txt");
    cin.rdbuf(in.rdbuf());
#endif
    string s, t;
    cin >> s >> t;
    if(s == t){
        cout << "Yes" << endl;
        return 0;
    }
    for(int i = 0; i < s.size(); ++i){
        s = (s[s.size() - 1]) + s;
        s.erase(s.begin() + s.size() - 1);
        if(s == t){
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}

