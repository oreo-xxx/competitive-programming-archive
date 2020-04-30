#include <cstdio>
using namespace std;

int max(int a, int b) { return a < b ? b : a; }
int board[2010][2010];
int main() {
    int N, K; scanf("%d%d", &N, &K);

    int sum = 0, white = 0;
    for(int i=0; i<N; i++) {
        int x, y; char c; scanf(" %d%d %c", &x, &y, &c);
        x %= 2*K, y %= 2*K;
        if(c == 'B') board[x+1][y+1]++, sum++;
        if(c == 'W') board[x+1][y+1]--, sum--, white++;
    }

    for(int i=1; i<=2*K; i++) {
        for(int j=1; j<=2*K; j++) {
            board[i][j] += board[i][j-1];
        }
    }

    for(int j=1; j<=2*K; j++) {
        for(int i=1; i<=2*K; i++) {
            board[i][j] += board[i-1][j];
        }
    }

    int ma = -(1 << 25);
    for(int i=0; i<=K; i++) {
        for(int j=0; j<=K; j++) {
            int a = board[i][j];
            int b = board[i+K][j+K] - board[i+K][j] - board[i][j+K] + board[i][j];
            int c = board[2*K][j] - board[i+K][j];
            int d = board[i][2*K] - board[i][j+K];
            int e = board[2*K][2*K] - board[2*K][j+K] - board[i+K][2*K] + board[i+K][j+K];
            int tmp = a + b + c + d + e;
            ma = max(ma, max(tmp, sum - tmp));
        }
    }
    ma += white;
    printf("%d\n", ma);
    return 0;
}