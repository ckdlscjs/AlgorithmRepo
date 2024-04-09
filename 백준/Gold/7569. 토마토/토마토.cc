#pragma once
#include <bits/stdc++.h>
int N, M, H;
const int MaxN = 105;
const int dy[] = { 0, 0 ,1, -1, 0, 0 };
const int dx[] = { 1, -1, 0, 0, 0, 0 };
const int dz[] = { 0, 0, 0, 0, -1, 1 };
int arr[MaxN][MaxN][MaxN];
struct Pos
{
	int z;
	int y;
	int x;
	Pos(int _z, int _y, int _x) : z(_z), y(_y), x(_x) {}
};
std::queue<Pos> tomatos;
int count_all;
int count_tomatos;
int result = 0;
int main(void)
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	std::cin >> M >> N >> H;
	for (int k = 0; k < H; k++)
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				std::cin >> arr[k][i][j];
				if (arr[k][i][j] == -1) continue;
				count_all++;
				if (arr[k][i][j] == 1)
				{
					tomatos.push(Pos(k, i, j));
					count_tomatos++;
				}
			}
		}
	}
	
	if (count_all == tomatos.size())
	{
		std::cout << result;
	}
	else
	{
		while (tomatos.size() && count_tomatos != count_all)
		{
			std::queue<Pos> nexttomatos;
			while (tomatos.size())
			{
				Pos cur = tomatos.front();
				tomatos.pop();
				for (int dir = 0; dir < 6; dir++)
				{
					int nz = cur.z + dz[dir];
					int ny = cur.y + dy[dir];
					int nx = cur.x + dx[dir];
					if (ny < 0 || nx < 0 || nz < 0 || ny >= N || nx >= M || nz >= H || arr[nz][ny][nx])
						continue;
					nexttomatos.push(Pos(nz, ny, nx));
					arr[nz][ny][nx] = 1;
				}
			}
			result++;
			while (nexttomatos.size())
			{
				count_tomatos++;
				tomatos.push(nexttomatos.front());
				nexttomatos.pop();
			}
		}
		if (count_tomatos == count_all)
			std::cout << result;
		else
			std::cout << -1;
	}
	return 0;
}