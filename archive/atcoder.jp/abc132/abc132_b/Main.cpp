#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;

const ll INF64 = 1LL << 60;
const int INF32 = 1 << 29;
const int MOD =   1000000007;

int main()
{
#ifdef MYLOCAL
    ifstream in("input.txt");
    cin.rdbuf(in.rdbuf());
#endif
    int n; cin >> n;
    vector<int> p(n);
    for(int i = 0; i < n; ++i){
        cin >> p[i];
    }
    int ans = 0;
    for(int i = 1; i < n - 1; ++i){
        int l = p[i-1];
        int c = p[i];
        int r = p[i+1];
        if( (l < c && c < r) || (r < c && c < l) ){
            ++ans;
        }
    }

    cout << ans << endl;

    return 0;
}
