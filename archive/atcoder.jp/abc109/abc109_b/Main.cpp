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
    int n; cin >> n;

    vector<string> w(n);
    set<string> se;
    for (int i = 0; i < n; ++i){
        cin >> w[i];
        se.insert(w[i]);
    }

    if(se.size() != n){
        cout << "No" << endl;
        return 0;
    }

    char before = w[0][w[0].size() - 1];
    for (int i = 1; i < n; ++i){
        char now = w[i][0];
        if(before != now){
            cout << "No" << endl;
            return 0;
        }
        before = w[i][w[i].size() - 1];
    }

    cout << "Yes" << endl;
    return 0;
}
