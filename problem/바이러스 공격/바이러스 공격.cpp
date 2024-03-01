#include <iostream>
#include <queue>

#define N_MAX 100
#define M_MAX 100
using namespace std;

typedef struct {
    int row;
    int col;
    int delay;
} Point;

const int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

int N, M, TG, TB;

char grid[N_MAX + 1][M_MAX + 1];
bool chk[N_MAX + 1][M_MAX + 1];

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    queue<Point> q;
    bool flag = 0;

    cin >> N >> M >> TG >> TB;

    for(int row = 1; row <= N; ++row) {
        for(int col = 1; col <= M; ++col) {
            cin >> grid[row][col];

            if(grid[row][col] == '*')
                q.push({row, col, 0});
        }
    }

    for(int t = 0; t <= TG; ++t) {
        int size = q.size();

        while(!q.empty() && size > 0) {
            int cur_Row = q.front().row, cur_Col = q.front().col, cur_Delay = q.front().delay;
            q.pop();
            size--;

            if(chk[cur_Row][cur_Col]) continue;

            if(cur_Delay > 0) {
                q.push({cur_Row, cur_Col, cur_Delay - 1});
                continue;
            }

            chk[cur_Row][cur_Col] = 1;

            for(int i = 0; i < 4; ++i) {
                int next_Row = cur_Row + dir[i][0], next_Col = cur_Col + dir[i][1], next_Delay;

                if(next_Row < 1 || next_Row > N || next_Col < 1 || next_Col > M || chk[next_Row][next_Col]) continue;

                next_Delay = grid[next_Row][next_Col] == '#' ? TB : 0;

                q.push({next_Row, next_Col, next_Delay});
            }
        }
    }

    for(int row = 1; row <= N; ++row) {
        for(int col = 1; col <= M; ++col) {
            if(chk[row][col]) continue;

            flag = 1;
            cout << row << ' ' << col << '\n';
        }
    }

    if(!flag) cout << -1;

    return 0;
}