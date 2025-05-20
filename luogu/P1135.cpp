#include <iostream>
#include <queue>
using namespace std;
#define maxn 201
int N, A, B;
int length_K[maxn];
bool visited[maxn] = {false};
int bfs()
{
    int next_up, next_down;
    int current;
    int times = 0;
    queue<int> nqueue;
    nqueue.push(A);
    visited[A] = true;
    while (!nqueue.empty())
    {
        int level_size = nqueue.size();
        times++;
        for (int i = 0; i < level_size; i++)
        {
            current = nqueue.front();
            nqueue.pop();
            if (current == B)
            {
                return times - 1; // 因为初始楼层A也算作第0层
            }

            next_up = current + length_K[current];
            next_down = current - length_K[current];

            if (next_up <= N && !visited[next_up])
            {
                nqueue.push(next_up);
                visited[next_up] = true;
            }
            if (next_down > 0 && !visited[next_down])
            {
                nqueue.push(next_down);
                visited[next_down] = true;
            }
        }
    }
    return -1; // 如果无法到达B，返回-1
}
int main()
{
    cin >> N >> A >> B;
    for (int i = 1; i <= N; i++)
    {
        cin >> length_K[i];
    }
    int ans = bfs();
    cout << ans << endl;
}