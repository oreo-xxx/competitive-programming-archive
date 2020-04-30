#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using P = pair<ll, ll>;

const ll INF64 = 1LL << 60;
const int INF32 = 1 << 29;
const int MOD = 1000000007;

const int CASES = 2;

void solve(){
    int N;
    cin >> N;

    vector<int> A(N);
    for(int i = 0; i < N; ++i){
        cin >> A[i];
    }
    int ans = 0;
    for(int i = 0; i < N; ++i){ ans ^= A[i];}
    if(ans == 0){
        cout << "Yes\n";
    }
    else{
        cout << "No\n";
    }
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

