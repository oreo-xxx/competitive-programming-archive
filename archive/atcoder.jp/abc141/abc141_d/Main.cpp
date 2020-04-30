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
    int N, M;
    cin >> N >> M;
    priority_queue<int> a;
    for(int i = 0 ; i < N; ++i){
        int tmp; cin >> tmp;
        a.push(tmp);
    }

    for(int i = 0; i < M; ++i){
        int tmp = a.top(); a.pop();
        tmp /= 2;
        a.push(tmp);
    }
    ll ans = 0;
    while(!a.empty()){
        ll tmp = a.top(); a.pop();
        ans += tmp;
    }
    cout << ans << endl;

    return 0;
}

