#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using P = pair<ll, ll>;

const ll INF64 = 1LL << 60;
const int INF32 = 1 << 29;
const int MOD = 1000000007;

const int CASES = 4;

vector<bool> isprime;
vector<int> Era(int n) {
    isprime.resize(n, true);
    vector<int> res;
    isprime[0] = false; isprime[1] = false;
    for (int i = 2; i < n; ++i) isprime[i] = true;
    for (int i = 2; i < n; ++i) {
        if (isprime[i]) {
            res.push_back(i);
            for (int j = i*2; j < n; j += i) isprime[j] = false;
        }
    }
    return res;
}


bool check(int N, int mb){
    return false;
}

void solve() {
    ll N, M;
    cin >> N >> M;

    if(M % N == 0){
        cout << M/N << endl;
        return;
    }
    
    ll ans = 1;
    for(ll i = 1; i < M / N + 1; ++i){
        if((M - i * N) % i == 0){
            ans = max(ans, i);
        }
    }
    cout << ans << endl;
    return ;
}

int main() {
    #ifdef MYLOCAL
    vector<string> filenames {"input1.txt", "input2.txt", "input3.txt", "input4.txt"};
    cout << "------------\n";
    for(int i = 0; i < CASES; ++i){
        ifstream in(filenames[i]);
        cin.rdbuf(in.rdbuf());
        solve();
        cout << "------------\n";
    }
    #else

    solve();

    #endif
    return 0;
}

