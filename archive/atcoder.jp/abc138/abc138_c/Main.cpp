#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

const ll INF64 = 1LL << 60;
const int INF32 = 1 << 29;
const int MOD = 1000000007;

// Lib
//

int main(){
#ifdef MYLOCAL
    ifstream in("input.txt");
    cin.rdbuf(in.rdbuf());
#endif
    int N; cin >> N;
    vector<double> v(N);
    for(int i = 0; i < N; ++i){
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    for(int i = 1; i < N; ++i){
        v[i] += v[i-1];
        v[i] /= 2.0;
    }
    cout << v[N-1] << endl;

    return 0;
}
