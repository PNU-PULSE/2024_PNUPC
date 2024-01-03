#include <iostream>

#define MAX_N 10000000
using namespace std;

const int dir[5][2] = {{0, 0}, {0, 1}, {0, -1}, {1, 0}, {-1, 0}};

int N;
int balls[MAX_N][2];
int cache[MAX_N][3][3];

int DFS(int index, int r, int c)
{
    if(index >= MAX_N || r < 0 || r >= 3 || c < 0 || c >= 3) return 0;

    int &ret = cache[index][r][c];
    if(ret != -1) return ret;

    for(int i = 0; i < 5; ++i) {
        int next_r = r + dir[i][0], next_c = c + dir[i][1];

        ret = max(ret, DFS(index + 1, next_r, next_c));
    }

    ret += balls[index][0] == r && balls[index][1] == c ? 1 : 0;

    return ret;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int ans = -1;

    cin >> N;

    for(int i = 0; i < N; ++i) {
        int r, c;
        cin >> r >> c;
        balls[i][0] = r - 1; balls[i][1] = c - 1;
    }

    for(int i = 0; i < N; ++i)
        for(int r = 0; r < 3; ++r)
            for(int c = 0 ; c < 3; ++c)
                cache[i][r][c] = -1;


    for(int r = 0; r < 3; ++r)
        for(int c = 0; c < 3; ++c)
            ans = max(ans, DFS(0, r, c));

    cout << ans;

    return 0;
}