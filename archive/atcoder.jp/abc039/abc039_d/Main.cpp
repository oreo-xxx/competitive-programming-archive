#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pint = pair<int,  int>;
using edge = int;
using graph = vector<vector<edge>>;
const ll INF = 1LL << 60;
const int INF32 = 1 << 29;
const ll MOD = 1000000007;

int dx[]={-1,-1,-1,0,0,0,1,1,1};
int dy[]={-1,0,1,-1,0,1,-1,0,1};

int main() {
    int h, w; cin>>h>> w;
    vector<string > a(h);
    vector<vector<int> >used(h, vector<int> (w));
    vector<pint> ans;
    for(int i = 0; i < h; ++i){
        cin >>a[i];
    }
    for(int i = 0; i < h; ++i){
        for(int j = 0; j < w; ++j){
            bool flag = true;
            for(int k = 0; k < 9; ++k){
                int nh = i+dy[k];
                int nw = j+dx[k];
                if(0<=nh&& nh<h&& 
                    0<=nw&& nw<w&& 
                    a[nh][nw]=='.'){flag = false;break;}
            }
            if(flag){
                ans.push_back({i, j});
                for(int k = 0; k < 9; ++k){
                    int nh = i+dy[k];
                    int nw = j+dx[k];
                    if(0<=nh&& nh<h&& 
                    0<=nw&& nw<w&& 
                    a[nh][nw]=='#'){used[nh][nw]=1;}
                }
            }
        }
    }
    int num = 0, tmp=0;
    for(int i = 0; i < h; ++i){
         for(int j = 0; j < w; ++j){
             if(a[i][j]=='#'){++tmp;}
             if(used[i][j]==1){++num;}
         }
     }
     if(num!=tmp){
         cout << "impossible" << endl;
         return 0;
     }
     cout << "possible" << endl;
     vector<string > f(h);
     for(int i = 0; i < h; ++i){
         for(int j = 0; j < w; ++j){
             f[i]+='.';
         }
     }
     for(int i = 0; i < ans.size(); ++i){
         pint p=ans[i];
         f[p.first][p.second]='#';
    }
    for(int i = 0; i < h; ++i){
        cout << f[i] << endl;
    }
}
