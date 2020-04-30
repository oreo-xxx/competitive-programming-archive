#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;

const ll INF64 = 1LL << 60;
const int INF32 = 1 << 29;
const int MOD = 1000000007;

int main()
{
#ifdef MYLOCAL
    ifstream in("input.txt");
    cin.rdbuf(in.rdbuf());
#endif

    int n; cin >> n;
    vector<int>  h(n + 1);
    for(int i = 0; i < n; ++i){
        cin >> h[i];
    }
    h[n] = 0;

    int count = 0;
    bool flag = true;
    while(flag){
        bool start = false;
        vector<P>lr;
        int l = 0, r = 0;
        for(int i = 0; i < n + 1; ++i){
            if( h[i] != 0 && start == false){
                start = true;
                l = i;
            }
            else if( (h[i] == 0) && (start == true)){
                start = false;
                r = i;
                lr.push_back({l,r});
            }
        }

        for(int t = 0; t < lr.size(); t++){
            int min_ = INF32;
            for(int i = lr[t].first; i < lr[t].second; ++i){
                min_ = min(min_, h[i]);
            }
            for(int i = lr[t].first; i < lr[t].second; ++i){
                h[i] -= min_;
            }
            count += min_;
        }

        flag = false;
        for(int i = 0; i < n; ++i){
            if(h[i] != 0){
                flag = true;
            }
        }
    }
    cout << count << endl;
    return 0;
}
