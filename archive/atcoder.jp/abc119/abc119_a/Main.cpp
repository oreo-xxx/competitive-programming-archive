#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using P = pair<ll, ll>;

const ll INF64 = 1LL << 60;
const int INF32 = 1 << 29;
const int MOD = 1000000007;

// Library

//

int main() {
#ifdef MYLOCAL
    ifstream in("input.txt");
    cin.rdbuf(in.rdbuf());
#endif
    string s; cin >> s;
    string yyyy = s.substr(0, 4);
    string mm = s.substr(5, 2);
    int year = stoi(yyyy);
    int month = stoi(mm);

    string ans;
    if(year <= 2018){
         ans = "Heisei";
    }
    else if(year > 2019){
        ans = "TBD";
    }
    else if(year == 2019 && month <= 4){
        ans = "Heisei";
    }
    else if(year == 2019 && month > 4){
        ans = "TBD";
    }

    cout << ans << endl;
    return 0;
}

