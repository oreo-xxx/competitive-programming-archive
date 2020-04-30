#include<iostream>
#include<vector>
#include<string>
#include<utility>
#include<algorithm>
#include<limits.h>
using namespace std;

int main()
{
    int n; cin >> n;
    vector<int>  a(n);
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
    bool flag = true;
  
    while(flag){
      int tmp = INT_MAX;
      int min_index = 0;
      for(int i = 0; i < n; ++i){
        if(a[i] == 0) continue;
        if(tmp > a[i]) {
          tmp = a[i];
          min_index = i;
        }
      }
                 
      for(int i = 0; i < n; ++i){
        if(i != min_index) a[i] = a[i] % a[min_index];
      }
      
      int count = 0;
      for(int i = 0; i < n; ++i){
        if(a[i] != 0) ++count;
      }

      if(count == 1){
        flag = false;
        cout << a[min_index] << endl;
      }
    }
    return 0;
}
