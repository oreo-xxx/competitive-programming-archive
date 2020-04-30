#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using P = pair<int, int>;

const ll INF64 = 1LL << 60;
const int INF32 = 1 << 29;
const int MOD = 1000000007;

bool comp(P a, P b){return a.second < b.second;}

void findAllOccurances(vector<size_t>& vec, string& data, string toSearch)
{
    size_t pos = data.find(toSearch);
    while( pos != string::npos)
    {
        vec.push_back(pos);
        pos = data.find(toSearch, pos + toSearch.size());
    }
}

int main() {
#ifdef MYLOCAL
    ifstream in("input.txt");
    cin.rdbuf(in.rdbuf());
#endif
     int a, b; cin >> a >> b;

     int ans = 0;
     if(a > b){
         ans += a;
         --a;
     }
     else{
         ans += b;
         --b;
     }

    if(a > b){
        ans += a;
        --a;
    }
    else{
        ans += b;
        --b;
    }

    cout << ans << endl;

    return 0;
}

