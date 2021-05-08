#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
int M, N, H; // X, Y, H
int board[101][101][101];
int dz[] = { 1, -1 };
int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 }; 

int bfs(vector<tuple<int, int, int>>& tuples)
{
	queue<tuple <int, int, int >> queue;

	for (auto tuple : tuples)
	{
		queue.push(tuple);
	}

	int MaxGeneration = 0;
	while (!queue.empty())
	{
		auto pos = queue.front();
		queue.pop();
		
		int Y = std::get<0>(pos);
		int X = std::get<1>(pos);
		int Z = std::get<2>(pos);

		int Generation = board[Y][X][Z];
		MaxGeneration = max(MaxGeneration, Generation);
		
		for (int i = 0; i < 4; ++i)
		{
			int tY = Y + dy[i];
			int tX = X + dx[i];

			if (tY < 0 || tY >= N || tX < 0 || tX >= M || board[tY][tX][Z] != 0)
				continue;

			queue.push(make_tuple(tY, tX, Z));
			board[tY][tX][Z] = Generation + 1;
		}

		for (int i = 0; i < 2; ++i)
		{
			int tZ = Z + dz[i];

			if (tZ < 0 || tZ >= H || board[Y][X][tZ] != 0)
				continue;

			queue.push(make_tuple(Y, X, tZ));
			board[Y][X][tZ] = Generation + 1;
		}
	}

	return MaxGeneration-1;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> M >> N >> H;
	
	vector<tuple<int, int, int>> tuples;
	vector<tuple<int, int, int>> zerotuples;


	for (int z = 0; z < H; ++z)
	{
		for (int y = 0; y < N; ++y)
		{
			for (int x = 0; x < M; ++x)
			{
				int temp;
				cin >> temp;

				board[y][x][z] = temp;
				if (temp == 1)
				{
					tuples.push_back(make_tuple(y, x, z));
				}
				else if (temp == 0)
				{
					zerotuples.push_back(make_tuple(y, x, z));
				}
			}
		}
	}

	int Generation = bfs(tuples);
	for (auto pos : zerotuples)
	{
		int Y = std::get<0>(pos);
		int X = std::get<1>(pos);
		int Z = std::get<2>(pos);

		if (board[Y][X][Z] == 0)
		{
			cout << "-1\n";
			return 0;
		}
	}

	cout << Generation << "\n";
	
	return 0;
}