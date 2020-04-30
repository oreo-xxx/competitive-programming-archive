#include<iostream>
#include<vector>
#include<string>
#include<utility>
#include<algorithm>
using namespace std;

int main()
{
    int n; cin >> n;
    int m; cin >> m;
    vector< pair<int, int> > ab;
    for(int i = 0; i < n; ++i){
        int a; cin >> a;
        int b; cin >> b;
        pair<int, int> tmp = make_pair(a, b);
        ab.push_back(tmp);
    }
    sort(ab.begin(), ab.end());
    
    int count = 0;
    long long answer = 0;
    for (int i = 0; i < n; ++i){
      for (int j=0; j < ab[i].second; ++j){
        ++count;
        answer += ab[i].first;
        if(count == m){
          cout << answer << endl; 
          return 0;
        }
      }
    }
    return 0;
}
