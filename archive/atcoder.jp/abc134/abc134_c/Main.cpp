#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;

const ll INF64 = 1LL << 60;
const int INF32 = 1 << 29;
const int MOD = 1000000007;

int main()
{
#ifdef MYLOCAL
    ifstream in("input.txt");
    cin.rdbuf(in.rdbuf());
#endif
    int n; cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; ++i) cin >> a[i];

    vector<int> sl(n + 1);
    for(int i = 0; i < n; ++i){
        sl[i + 1] = max(sl[i], a[i]);
    }
    vector<int> sr(n + 1);
    for(int i = n - 1; i >= 0; --i){
        sr[i] = max(sr[i + 1], a[i]);
    }

    for(int i = 0; i < n; ++i){
        int ans = max(sl[i], sr[i + 1]);
        cout << ans << endl;
    }
    return 0;
}
