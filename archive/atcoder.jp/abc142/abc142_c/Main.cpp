#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using P = pair<ll, ll>;

const ll INF64 = 1LL << 60;
const int INF32 = 1 << 29;
const int MOD = 1000000007;

const int CASES = 3;

void solve(){
    int N;
    cin >> N;
    vector<P> A(N);
    for(int i = 0; i < N; ++i){
        int a; cin >> a;
        A[i] = {a, i+1};

    }
    sort(A.begin(), A.end());


    for(int i = 0; i < N-1; ++i){
        cout << A[i].second << " ";
    }
    cout << A[N-1].second << "\n";
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

