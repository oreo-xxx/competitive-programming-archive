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
     int n; cin >> n;
     vector<string> s(n);
     for (int i = 0; i < n; ++i){
         cin >> s[i];
     }

     for (int i = 0; i < n; ++i){
         vector<size_t> vec;
         findAllOccurances(vec, s[i], "tokyo");
         findAllOccurances(vec, s[i], "kyoto");

         if(vec.size() == 0){
             cout << 0 << endl;
             continue;
         }

         vector<P> a( vec.size() );
         for(int j = 0; j < vec.size(); ++j){
             a[j].first = vec[j];
             a[j].second = vec[j] + 4;
         }

         sort(a.begin(), a.end(), comp);

         int ans = 0, end = 0;
         for (int j = 0; j < vec.size(); ++j) {
             if (a[j].first >= end) {
                 end = a[j].second;
                 ++ans;
             }
         }
         cout << ans << endl;
     }

     return 0;
}

