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
    int N, K, Q; cin >> N >> K >> Q;
    vector<int> vec(N , K-Q);
    vector<int> a(Q);
    for(int i = 0 ; i < Q; ++i){
        cin >> a[i];
        --a[i];
    }

    for(int i = 0; i < Q; ++i){
        vec[a[i]]++;
    }

    for(int i = 0 ; i < N; ++i){
        if(vec[i] > 0){
            cout << "Yes" << endl;
        }
        else{
            cout << "No" << endl;
        }
    }


    return 0;
}

