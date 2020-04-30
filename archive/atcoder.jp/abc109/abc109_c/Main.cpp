#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>
#include <climits>

using namespace std;

int gcd(int a,int b)
{
    if (a%b==0)
    {
        return(b);
    }
    else
    {
        return(gcd(b,a%b));
    }
}

int main() {
    int N; cin >> N;
    int X; cin >> X;

    vector<int> xs(N);
    for(int i = 0; i < N; ++i){
        cin >> xs[i];
    }
    xs.push_back(X);

    sort(xs.begin(), xs.end());

    vector<int> diffs(N);
    for(int i = 0; i < N; ++i){
        diffs[i] = xs[i + 1] - xs[i];
    }

    int ans = INT_MAX;
    if(N == 1) {
        ans = diffs[0];
    }
    else{
        for(int i = 0; i < N - 1; ++i){
            int tmp = gcd( diffs[i + 1], diffs[i]);
            ans = min(ans, tmp);
        }
    }

    cout << ans << endl;

    return 0;
}