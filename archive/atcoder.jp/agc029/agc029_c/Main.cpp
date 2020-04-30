#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

const ll INF64 = 1LL << 60;
const int INF32 = 1 << 29;
const int MOD = 1000000007;
//const int MOD = 998244353;

// Lib
//
void normalize(vector<pll> &nums) {
    if (nums.size() > 1) {
        if (nums[nums.size()-1].first == nums[nums.size()-2].first) {
            nums[nums.size()-2].second += nums[nums.size()-1].second;
            nums.pop_back();
        }
    }
}

void zouka(vector<pll> &nums) {
    if (nums.back().second == 1) {
        nums.back().first += 1;
    }
    else {
        nums.back().second--;
        nums.push_back(pll(nums.back().first+1, 1));
    }
    normalize(nums);
}

int main(){
#ifdef MYLOCAL
    ifstream in("input.txt");
    cin.rdbuf(in.rdbuf());
#endif
    int N; cin >> N;
    vector<ll> a(N);
    for (int i = 0; i < N; ++i) cin >> a[i];

    ll low = 0, high = N+1;
    while (high - low > 1) {
        ll mid = (low + high) / 2;

        vector<pll> nums;
        nums.push_back( {0, a[0]} );

        bool ok = true;
        for (int i = 1; i < N; ++i) {
            if (a[i-1] < a[i]){
                nums.push_back(pll(0, a[i] - a[i-1]));
            }
            else {
                ll sum = 0;
                while (nums.size() > 0 && sum + nums.back().second <= a[i-1] - a[i]) {
                    sum += nums.back().second;
                    nums.pop_back();
                }
                nums.back().second -= a[i-1] - a[i] - sum;

                if (nums.back().first == mid-1) {
                    if (nums.size() == 1) {
                        ok = false;
                        break;
                    }
                    long long num = nums.back().second;
                    nums.pop_back();
                    zouka(nums);
                    nums.push_back(pll(0, num));
                }
                else zouka(nums);
            }
            normalize(nums);
        }

        if (ok) high = mid;
        else low = mid;
    }
    cout << high << endl;
    return 0;
}
