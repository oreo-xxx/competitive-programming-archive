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
    int n; cin >> n;
    vector<P> ba(n);
    for(int i = 0; i < n; ++i){
        P tmp;
        cin >> ba[i].second >> ba[i].first ;
    }
    sort(ba.begin(), ba.end());

    ll now = 0;
    string ans = "Yes";
    for (int i = 0; i < n; ++i){
        now += ba[i].second;
        if(now > ba[i].first){
            ans = "No";
            break;
        }
    }
    cout << ans << endl;
    return 0;
}
