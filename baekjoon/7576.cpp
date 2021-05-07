#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
int Board[1001][1001];
int n, m; // n = 행의 수, m = 열의 수
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 }; // 상하좌우 네 방향을 의미

int BFS(queue<pair<int, int>>& q2)
{
	int Generation = 1;
	int MaxG = 1;
	queue<pair<int, int>> q;

	while (true)
	{
		if (q.empty())
		{
			if (q2.empty())
				break;

			Generation++;
			q2.swap(q);
		}

		auto cur = q.front();
		q.pop();

		for (int i = 0; i < 4; ++i)
		{
			int ty = cur.first + dy[i];
			int tx = cur.second + dx[i];

			if (ty < 0 || ty >= n || tx < 0 || tx >= m)
				continue;

			if (Board[ty][tx] == -1 || Board[ty][tx] > 0)
				continue;

			Board[ty][tx] = Generation;
			MaxG = max(Generation, MaxG);
			q2.push({ ty, tx });
		}	
	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (Board[i][j] == 0)
				return -1;
		}
	}

	return MaxG-1;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> m >> n;

	vector<pair<int, int>> StartPos;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cin >> Board[i][j];

			if (Board[i][j] == 1)
				StartPos.push_back({ i, j });
		}
	}

	queue<pair<int, int>> queue;
	for (auto& pair : StartPos)
	{
		queue.push(pair);
	}

	cout << BFS(queue) << endl;
	

	return 0;
}