#include<iostream>
#include<vector>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> v;
    for(int i = 0; i < n; ++i){
      int tmp_v;
      cin >> tmp_v;
      v.push_back(tmp_v);
    }

    vector<int> c;
    for(int i = 0; i < n; ++i){
      int tmp_c;
      cin >> tmp_c;
      c.push_back(tmp_c);
    }

    int answer = 0;

    for(int i = 0; i < n; ++i){
      int value = v[i] - c[i];
      if(value > 0){
        answer += value;
      }
    }

    cout << answer << endl;

    return 0;
}
