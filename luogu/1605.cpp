#include <iostream>
#include <stack>
using namespace std;
int direction[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
struct Node
{
    int x, y;
    Node(int xi, int yi) : x(xi), y(yi) {}
};
int map[6][6];
int visited[6][6];
int T;
int SX , SY, FX, FY;
int xi, yi;
int N, M;
int cnt;
void dfs(int x, int y)
{
    if (x == FX - 1 && y == FY - 1)
    {
        cnt++;
        return;
    }
    for (int k = 0; k < 4; k++)
    {
        int dx = x + direction[k][0];
        int dy = y + direction[k][1];
        if ((0 <= dx && dx < N) && (0 <= dy && dy < M) && map[dx][dy] != 5 && visited[dx][dy] != 1)
        {
            visited[dx][dy] = 1;
            dfs(dx, dy);
            visited[dx][dy] = 0;
        }
    }
}
int main()
{
    cin >> N >> M >> T;
    cin >> SX  >> SY >> FX >> FY;
    for (int i = 0; i < T; i++)
    {
        cin >> xi >> yi;
        map[xi - 1][yi - 1] = 5;
    }
    visited[SX - 1][SY - 1] = 1;
    dfs(SX - 1, SY - 1);
    cout << cnt << endl;
    return 0;
}