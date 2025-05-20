#include <iostream>
#include <queue>
using namespace std;
int map[5][5];
int visited[5][5];
struct Node
{
    int x, y;
    Node *before;
    Node() : before(NULL) {}
    Node(int xi, int yi, Node *p) : x(xi), y(yi), before(p) {}
};
int direction[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
Node *lastNode;
void bfs()
{
    queue<Node*> nqueue;
    Node *newNode = new Node(0, 0, NULL);
    visited[0][0] = 1;
    nqueue.push(newNode);
    while (!nqueue.empty())
    {
        Node *curr = nqueue.front();
        nqueue.pop();
        for(int i = 0;i < 4;i++){
            int dx = curr->x + direction[i][0];
            int dy = curr->y + direction[i][1];
            if((0 <= dx && dx < 5) && (0 <= dy && dy < 5) && (map[dx][dy] == 0) && (visited[dx][dy] == 0)){
                visited[dx][dy] = 1;
                Node *next = new Node(dx,dy,curr);
                nqueue.push(next);
                if((next->x == 4) && (next->y == 4)){
                    lastNode = next;
                    return;
                }
            }
        }
    }
}
int main()
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cin >> map[i][j];
        }
    }
    bfs();
    int trace_x[20],trace_y[20];
    int count = 0;
    while(lastNode != NULL){
        trace_x[count] = lastNode->x;
        trace_y[count] = lastNode->y;
        lastNode = lastNode->before;
        count++;
    }
    for (int i = count - 1; i >= 0; --i)
	{
		cout << "("  << trace_x[i] << ", "  << trace_y[i] << ")";
	}
    return 0;
}