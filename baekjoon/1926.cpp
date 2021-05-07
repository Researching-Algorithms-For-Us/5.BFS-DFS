#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
bool Visisted[501][501];
int Board[501][501];
int n, m; // n = 행의 수, m = 열의 수
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 }; // 상하좌우 네 방향을 의미
int bfs(int y, int x)
{
	queue<pair<int, int>> q;
	Visisted[y][x] = true;
	Board[y][x] = 0;
	q.push({ y, x });
	int traversal = 0;

	while (!q.empty())
	{
		auto cur = q.front();
		++traversal;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int ty = cur.first + dy[i];
			int tx = cur.second + dx[i];

			if (ty < 0 || ty >= n || tx < 0 || tx >= m)
				continue;

			if (Visisted[ty][tx] || Board[ty][tx] == 0)
				continue;

			Visisted[ty][tx] = true;
			Board[ty][tx] = 0;
			q.push({ ty, tx });
		}
	}

	return traversal;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;

	vector<pair<int, int>> onePair;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cin >> Board[i][j];

			if (Board[i][j])
			{
				onePair.push_back({ i, j });
			}
		}
	}

	int CountPic = 0;
	int Large = 0;

	for (auto& pair : onePair)
	{
		int y = pair.first;
		int x = pair.second;

		if (Board[y][x] == 1)
		{
			CountPic++;
			Large = std::max(Large, bfs(y, x));
		}
	}
	

	cout << CountPic << "\n" << Large << "\n";
	return 0;
}