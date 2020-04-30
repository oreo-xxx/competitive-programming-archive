#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using P = pair<int, int>;

const ll INF = 1LL << 60;
const int MOD = 1000000007;

int main() {
#ifdef MYLOCAL
    ifstream in("input.txt");
    cin.rdbuf(in.rdbuf());
#endif

    string s; cin >> s;
    int n = s.size() - 1;
    ll ans = 0;
    for(ll bit = 0; bit < (1 << n); ++bit){
        vector<string> num;
        int l = 0;
        int count = 1;
        for (int i = 0; i < n; ++i) {
            if (bit & (1<<i)) {
                string tmp = s.substr(l, count);
                num.push_back(tmp);
                l = i + 1;
                count = 1;
            }else{
                ++count;
            }
        }
        string tmp = s.substr(l, s.size() - l);
        num.push_back(tmp);
        for(int i = 0; i < num.size(); ++i){
            ans += stoll(num[i]);
        }
    }
    cout << ans << endl;
    return 0;
}

