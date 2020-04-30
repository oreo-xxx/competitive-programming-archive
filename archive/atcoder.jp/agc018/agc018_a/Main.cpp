#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using P = pair<ll, ll>;

const ll INF64 = 1LL << 60;
const int INF32 = 1 << 29;
const int MOD = 1000000007;

const int CASES = 4;

int gcd(int a, int b) { return a ? gcd(b%a, a) : b; }

void solve(){
    int N, K;
    cin >> N >> K;
    
    vector<int> A(N);
    for(int i = 0; i < N; ++i){
        cin >> A[i];
        if(A[i] == K){
            cout << "POSSIBLE\n";
            return;
        }
    }
    sort(A.begin(), A.end());

    if(A.back() < K){
        cout << "IMPOSSIBLE\n";
        return;
    }

    int g = A[0];
    for(int i = 1; i < N; ++i){
        g = gcd(g, A[i]);
    }

    if(K % g == 0){
        cout << "POSSIBLE\n";
        return;
    }

    cout << "IMPOSSIBLE\n";
    return;
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

