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
    int N, M; cin >> N >> M;
    vector<ll> A(N);
    for (int i = 0; i < N; ++i){
        cin >> A[i];
    }
    sort(A.begin(), A.end());

    vector<P> CB(M);
    for (int i = 0; i < M; ++i){
        ll b, c; cin >> b >> c;
        CB[i] = {c, b};
    }
    sort(CB.begin(), CB.end(), greater<P>());

    ll sum = 0, K = 0;
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < CB[i].second; ++j) {
            if (K >= N){
                break;
            }
            sum += max(A[K++], CB[i].first);
        }
    }

    for (int i = K; i < N; ++i){
        sum += A[i];
    }
    
    cout << sum << endl;
    return 0;
}
