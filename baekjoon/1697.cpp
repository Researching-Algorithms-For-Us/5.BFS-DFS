#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
int board[100001];
int N, K;
void bfs()
{
	queue<int> q;
	q.push(N);
	board[N] = 1;

	while (!q.empty())
	{
		auto xpos = q.front();
		q.pop();

		int MoveCount = board[xpos];

		if (xpos == K)
		{
			cout <<  MoveCount - 1 << "\n";
			return;
		}

		if (xpos - 1 >= 0 && board[xpos - 1] == 0)
		{
			q.push(xpos - 1);
			board[xpos - 1] = MoveCount + 1;
		}

		if (xpos + 1 <= 100000 && board[xpos + 1] == 0)
		{
			q.push(xpos + 1);
			board[xpos + 1] = MoveCount + 1;
		}
		
		if (xpos * 2 <= 100000 && board[xpos * 2] == 0)
		{
			q.push(xpos * 2);
			board[xpos * 2] = MoveCount + 1;
		}

	}
	
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> K;

	bfs();

	return 0;
}