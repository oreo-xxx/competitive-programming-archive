#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;

const ll INF64 = 1LL << 60;
const int INF32 = 1 << 29;
const int MOD = 1000000007;

vector<long long> calc_divisor(long long n) {
    vector<long long> res;
    for (long long i = 1LL; i*i <= n; ++i) {
        if (n % i == 0) {
            res.push_back(i);
            long long j = n / i;
            if (j != i) res.push_back(j);
        }
    }
    sort(res.begin(), res.end());
    return res;
}


int main()
{
#ifdef MYLOCAL
    ifstream in("input.txt");
    cin.rdbuf(in.rdbuf());
#endif
    int n; cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; ++i) cin >> a[i];

    vector<pair<bool, int> > box(n);
    for(int i = n; i > 0; --i){
        int tmp = n / i;
        int total = 0;
        for(int j = tmp; j > 0; --j){
            if(box[j * i - 1].first) {
                total += box[j * i - 1].second;
            }
        }

        box[i - 1].first = true;
        if(a[i - 1] == 0 && total % 2== 0){
            box[i - 1].second = 0;
        }
        else if(a[i - 1] == 0 && total % 2 == 1){
            box[i - 1].second = 1;
        }
        else if(a[i - 1] == 1 && total % 2 == 0){
            box[i - 1].second = 1;
        }
        else if(a[i - 1] == 1 && total % 2 == 1){
            box[i - 1].second = 0;
        }
    }
    vector<int> ans;
    for(int i = 0; i < n; ++i){
        if(box[i].second == 1){
            ans.push_back(i + 1);
        }
    }
    cout << ans.size() << endl;

    if(ans.size() != 0){
        for(int i = 0; i < ans.size() - 1; ++i){
            cout << ans[i] << " ";
        }
        cout << ans[ans.size() - 1] << endl;
    }
    return 0;
}
