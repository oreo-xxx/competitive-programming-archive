#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using P = pair<ll, ll>;

const ll INF64 = 1LL << 60;
const int INF32 = 1 << 29;
const int MOD = 1000000007;

const int CASES = 2;

struct Data{
    ll a;
    ll f;
    ll af;
    bool operator< (const Data& rhs) const{
        return af < rhs.af;
    };
};

bool check(ll N, ll K, const vector<Data>& vec, ll mb){
    for(ll i = 0; i < N; ++i) {
        ll a = vec[i].a;
        ll f = vec[i].f;
        ll af = vec[i].af;

        if(af > mb){
            ll tmp = mb / f;
            ll sub = vec[i].a - tmp;
            if(sub > K){
                return false;
            }
            else{
                K -= sub;
            }
        }
    }
    return true;
}


void solve() {
    ll N, K;
    cin >> N >> K;
    vector<ll> A(N);
    vector<ll> F(N);
    vector<Data> AF(N);

    for(ll i = 0; i < N; ++i){
        cin >> A[i];
    }
    sort(A.begin(), A.end(), greater<ll>());
    for(ll i = 0; i < N; ++i){
        cin >> F[i];
    }
    sort(F.begin(), F.end());

    ll tmp = 0;
    for(ll i = 0; i < N; ++i){
        tmp = max(tmp, A[i] * F[i]);
        AF[i] = {A[i], F[i], A[i] * F[i]};
    }

    ll lb = 0, ub = tmp;
    while(ub - lb > 1){
        ll mb = (lb + ub) / 2;
        if(check(N, K, AF, mb)){
            ub = mb;
        }else{
            lb = mb;
        }
    }

    if(ub == 1){
        if(check(N, K, AF, 0)){
            ub = 0;
        }
    }
    cout << ub << endl;
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

