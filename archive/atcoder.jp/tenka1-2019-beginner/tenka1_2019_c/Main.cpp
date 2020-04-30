#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using P = pair<ll, ll>;

const ll INF64 = 1LL << 60;
const int INF32 = 1 << 29;
const int MOD = 1000000007;

int main() {
#ifdef MYLOCAL
    ifstream in("input.txt");
    cin.rdbuf(in.rdbuf());
#endif
    int N; string S;
    cin >> N >> S;
    vector<int> whsum(N+1, 0);
    vector<int> blsum(N+1, 0);
    for (int i = 0; i < N; ++i) {
        whsum[i+1] = whsum[i] + (S[i] == '.' ? 1 : 0);
        blsum[i+1] = blsum[i] + (S[i] == '#' ? 1 : 0);
    }

    ll res = 1LL<<60;
    for (int left = 0; left <= N; ++left) {
        long long tmp = 0;
        // left を全部白に
        tmp += blsum[left] - blsum[0];

        // right を全部黒に
        tmp += whsum[N] - whsum[left];

        res = min(res, tmp);
    }
    cout << res << endl;
    return 0;
}

