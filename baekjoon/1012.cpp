#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
int board[51][51];
bool visited[51][51];
int M, N; // 가로(X), 세로(Y)
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 }; 
// ret : true searched, false not searched
bool bfs(int Y, int X)
{
	if (visited[Y][X] || board[Y][X] == 0)
		return false;
	
	queue<pair<int, int>> queue;
	visited[Y][X] = true;
	queue.push({ Y, X });

	while (!queue.empty())
	{
		auto pos = queue.front();
		queue.pop();

		board[pos.first][pos.second] = 0;

		for (int i = 0; i < 4; ++i)
		{
			int tx = pos.second + dx[i];
			int ty = pos.first + dy[i];

			if (board[ty][tx] == 0 || tx < 0 || tx >= M || ty < 0 || ty >= N || visited[ty][tx])
				continue;

			visited[ty][tx] = true;
			queue.push({ ty, tx });
		}
	}

	return true;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int TestCase = 0;
	cin >> TestCase;

	vector<pair<int, int>> pairPos;
	while (TestCase--)
	{
		pairPos.clear();
		memset(board, 0, sizeof(int) * 51 * 51);
		memset(visited, 0, sizeof(bool) * 51 * 51);

		int K;
		int X, Y;

		cin >> M >> N >> K;

		for (int i = 0; i < K; ++i)
		{
			cin >> X >> Y;
			board[Y][X] = 1;

			pairPos.push_back({ Y, X });
		}

		int Area = 0;
		for (auto pos : pairPos)
		{
			if (bfs(pos.first, pos.second))
				Area++;
		}

		cout << Area << "\n";
	}

	return 0;
}