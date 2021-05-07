#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
bool Visisted[101][101];
int Board[101][101];
int Direction[101][101];
int n, m; // n = 행의 수, m = 열의 수
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 }; // 상하좌우 네 방향을 의미
int bfs(int startx, int starty, int endx, int endy)
{
	memset(Direction, -1, sizeof(int) * 101 * 101);

	queue<pair<int, int>> q;
	Visisted[starty][starty] = true;
	Board[starty][startx] = -1;
	q.push({ starty, startx });

	while (!q.empty())
	{
		auto cur = q.front();
		q.pop();

		if (cur.first == endy && cur.second == endx)
			break;

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
			Direction[ty][tx] = i;
			q.push({ ty, tx });
		}
	}

	// BackTrack
	int EndX = endx;
	int EndY = endy;
	int traversal = 1;

	while (EndX != startx || EndY != starty)
	{
		int reverseIndex = (Direction[EndY][EndX] + 2) % 4;
		EndX += dx[reverseIndex];
		EndY += dy[reverseIndex];
		traversal++;
	}

	return traversal;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	n = m = 0;
	cin >> n >> m;


	for (int i = 0; i < n; ++i)
	{
		string width;
		cin >> width;
		int j = 0;
		for(auto c: width)
		{
			Board[i][j++] = c - '0';
		}
	}

	cout << bfs(0, 0, m - 1, n - 1) << "\n";
	return 0;
}