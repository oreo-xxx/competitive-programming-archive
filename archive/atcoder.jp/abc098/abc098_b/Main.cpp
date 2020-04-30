#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using P = pair<int, int>;

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

    int n; string s; cin >> n >> s;
    int ans = 0;
    for(int i = 0; i < n; ++i){
        set<char> st1;
        for(int j = 0; j < i; ++j){
            st1.insert(s[j]);
        }
        int tmp = 0;
        set<char> st2;
        for(int j = i; j < n; ++j){
            auto it1 = st1.find(s[j]);
            auto it2 = st2.find(s[j]);
            if(it1 != st1.end() && it2 == st2.end()){
                st2.insert(s[j]);
                ++tmp;
            }
        }
        ans = max(ans, tmp);
    }
    cout << ans << endl;
}
