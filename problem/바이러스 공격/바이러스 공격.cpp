#include <iostream>
#include <queue>

#define N_MAX 100
#define M_MAX 100
using namespace std;

typedef struct {
    int row;
    int col;
} Point;

const int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

int N, M, T;
bool chk[N_MAX + 1][M_MAX + 1];

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    queue<Point> q;

    cin >> N >> M >> T;

    for(int row = 1; row <= N; ++row) {
        for(int col = 1; col <= M; ++col) {
            char c;
            cin >> c;

            if(c == '*') {
                q.push({row, col});
            } else if(c == '#') {
                chk[row][col] = 1;
            }
        }
    }

    for(int t = 0; t < T; ++t) {
        int size = q.size();

        while(!q.empty() && size > 0) {
            int cur_Row = q.front().row, cur_Col = q.front().col;
            q.pop();
            size--;

            if(chk[cur_Row][cur_Col]) continue;

            chk[cur_Row][cur_Col] = 1;

            for(int i = 0; i < 4; ++i) {
                int next_Row = cur_Row + dir[i][0], next_Col = cur_Col + dir[i][1];

                if(next_Row < 1 || next_Row > N || next_Col < 1 || next_Col > M || chk[next_Row][next_Col]) continue;

                q.push({next_Row, next_Col});
            }
        }
    }

    for(int row = 1; row <= N; ++row) {
        for(int col = 1; col <= M; ++col) {
            if(chk[row][col]) continue;

            cout << row << ' ' << col << '\n';
        }
    }

    return 0;
}