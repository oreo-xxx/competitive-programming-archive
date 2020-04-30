#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using P = pair<ll, ll>;

const ll INF64 = 1LL << 60;
const int INF32 = 1 << 29;
const int MOD = 1000000007;

const int CASES = 3;

void solve(){
    ll N, A, B, C, D;
    string S;
    cin >> N >> A >> B >> C >> D >> S;
    --A, --B, --C, --D;

    // C < D
    // C前にAがBを抜き去れるかどうか
    if(C > D) {
        bool flag = false;
        for(int i = B - 1; i < N; ++i){
            if(S[i] == '.' && S[i + 1] == '.'&& S[i + 2] == '.'){
                B = i + 2;
                A = i + 1;
                swap(C, D);
                if(A <= C && B <= D){
                    flag = true;
                }
                break;
            }
        }
        if(!flag){
            cout << "No\n";
            return;
        }
    }

    // B -> D
    for(int i = B; i < D; ++i){
        if(S[i] == '#' && S[i + 1] == '#'){
            cout << "No\n";
            return;
        }
    }

    // A -> C
    for(int i = A; i < C; ++i){
        if(S[i] == '#' && S[i + 1] == '#'){
            cout << "No\n";
            return;
        }
    }
    cout << "Yes\n";
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

