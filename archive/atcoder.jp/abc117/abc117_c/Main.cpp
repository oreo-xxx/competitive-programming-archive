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
    int M; cin >> M;

    if(N >= M){
        cout << 0 << endl;
        return 0;
    }

    vector<int> Xs(M);
    for(int i = 0; i < M; ++i){
        cin >> Xs[i];
    }
    sort(Xs.begin(), Xs.end());

    vector<int> dists(M - 1);
    for(int i = 0; i < M - 1; ++i){
        dists[i] = Xs[i + 1] - Xs[i]; 
    }

    sort(dists.begin(), dists.end());

    int ans = 0;
    for(int i = 0; i < M - N; ++i){
        ans += dists[i];
    }
  
    cout << ans << endl;
    
    return 0;
}
