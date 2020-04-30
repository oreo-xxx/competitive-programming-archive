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
    bool ans = false;
    for(int i = 1; i <= 9; ++i){
        if(N % i != 0) continue;
        int tmp = N / i;
        if(1 <= tmp && tmp <= 9 ){
            ans = true;
            break;
        }
    }
    if(ans){
        cout << "Yes\n";
    }
    else{
        cout << "No\n";
    }
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

