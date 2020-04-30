#include<iostream>
#include<vector>
#include<string>
#include<utility>
#include<algorithm>
#include<unordered_map>
#include<climits>
using namespace std;

int main()
{
    int N; cin >> N;
    int K; cin >> K;

    vector<int> hs(N);
    for(int i = 0; i < N; ++i){
        cin >> hs[i];
    }
    sort(hs.begin(), hs.end());

    int ans = INT_MAX;
    for(int i = 0; i < N - (K - 1); ++i){
        int tmp = hs[i + K - 1] - hs[i];
        ans = min(ans, tmp);
    }
  
    cout << ans << endl;
    
    return 0;
}
