#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

const ll INF64 = 1LL << 60;
const int INF32 = 1 << 29;
const int MOD =   1000000007;

int main()
{
#ifdef MYLOCAL
    ifstream in("input.txt");
    cin.rdbuf(in.rdbuf());
#endif
    int n, t, a;
    cin >> n >> t >> a;

    vector<int> h(n);
    for (int i = 0; i < n; ++i){
        cin >> h[i];
    }

    double mindiff = INF32;
    int idx = -1;
    for (int i = 0; i < n; ++i){
        double diff = abs( (t - h[i] * 0.006) - a );
        if(mindiff > diff){
            mindiff = diff;
            idx = i + 1;
        }
    }
    cout << idx << endl;
    return 0;
}
