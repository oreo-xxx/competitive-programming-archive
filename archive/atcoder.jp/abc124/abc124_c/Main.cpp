#include<iostream>
#include<vector>
#include<string>
#include<utility>
#include<algorithm>
using namespace std;

int main()
{
    string s;
    cin >> s;
  
    int n = s.size();
  
    string w;
    string b;
    char wb[] = {'0','1'};
    for(int i = 0; i < n; ++i){
      w += wb[i % 2];
      b += wb[(i+1) % 2];
    }

    int count_w = 0;
    int count_b = 0;
  
    for(int i = 0; i < n; ++i){
      if(s[i] != w[i]) count_w++;
      if(s[i] != b[i]) count_b++;
    }
  
    cout << min(count_w, count_b) << endl;
    return 0;
}
