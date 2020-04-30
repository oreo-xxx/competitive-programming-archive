#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using P = pair<ll, ll>;

const ll INF64 = 1LL << 60;
const int INF32 = 1 << 29;
const int MOD = 1000000007;

const int CASES = 4;

bool check(const string& S, int p){
    for(int i = p+1;i < S.size(); ++i) {
        int tmp = (int)(S[i]-'0');
        if(tmp != 9){
            return true;
        }
    }
    return false;
}

void solve(){
    string N; cin >> N;
    int n = N.size();
    if(n == 1){
        cout << N << endl;
        return;
    }

    bool flag = false;
    int ans = 0;
    for(int i = 0; i < n-1; ++i){
        int tmp = (int)(N[i]-'0');
        if(flag){
            ans += 9;
        }
        else if(tmp != 9){
            if(check(N , i)){
                flag = true;
                ans += tmp-1;
            }
            else{
                ans += tmp;
            }
        }
        else{
            ans += tmp;
        }
    }
    int las = (int)(N.back() - '0');
    if(flag){
        ans += 9;
    }
    else if(flag == false && las != 9){
        --ans;
        ans += 9;
    }
    else{
        ans += las;
    }

    cout << ans << endl;
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

