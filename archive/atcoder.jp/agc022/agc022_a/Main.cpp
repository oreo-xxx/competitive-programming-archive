#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using P = pair<ll, ll>;

const ll INF64 = 1LL << 60;
const int INF32 = 1 << 29;
const int MOD = 1000000007;

const int CASES = 4;

void solve(){
    string S; cin >> S;
    int n = S.size();

    set<char> se;
    for(int i = 0; i < n; ++i){
        se.insert(S[i]);
    }
    if(se.size() == 26){
        int point = INF32;
        for(int i = n-1; i > 0; --i){
            if(S[i] > S[i-1]){
                point = i-1;
                break;
            }
        }

        if(point == INF32){
            cout << -1 << endl;
            return;
        }

        int minpoint = INF32;
        for(int i = n-1; i > point; --i){
            if(S[i] > S[point]){
                if(minpoint != INF32 && S[minpoint] < S[i]){
                    continue;
                }
                minpoint = i;
            }
        }
        string ans = S.substr(0, point);
        ans += S[minpoint];
        cout << ans << endl;
    }
    else{
        char tmp;
        for(int i = 0; i < 26; ++i){
            tmp = (char)('a' + i);
            if(se.count(tmp) == 0){
                break;
            }
        }
        S += tmp;
        cout << S << endl;
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

