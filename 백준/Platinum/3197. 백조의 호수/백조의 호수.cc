#pragma once
#include <bits/stdc++.h>
const int dy[] = { 0, 0, 1, -1 };
const int dx[] = { 1, -1, 0, 0 };
int r, c;
const int max = 1501;
char arr[max][max];
bool visited_swan[max][max];
struct Pos
{
	int y;
	int x;
	Pos(int _y, int _x)
	{
		y = _y;
		x = _x;
	}
};
std::queue<Pos> q_swan;
std::queue<Pos> q_swan_next;
std::queue<Pos> q_ices;
std::queue<Pos> q_ices_next;

bool Bfs_swan()
{
	while (q_swan.size())
	{
		Pos pos = q_swan.front();
		q_swan.pop();
		for (int dir = 0; dir < 4; dir++)
		{
			int ny = pos.y + dy[dir];
			int nx = pos.x + dx[dir];
			if (ny < 0 || nx < 0 || ny >= r || nx >= c || visited_swan[ny][nx])
				continue;
			visited_swan[ny][nx] = true;
			if (arr[ny][nx] == 'L')
				return true;
			if (arr[ny][nx] == 'X')
			{
				q_swan_next.push(Pos(ny, nx));
				continue;
			}
			q_swan.push(Pos(ny, nx));
		}
	}
	return false;
}

void Bfs_ice()
{
	while (q_ices.size())
	{
		Pos pos = q_ices.front();
		q_ices.pop();
		for (int dir = 0; dir < 4; dir++)
		{
			int ny = pos.y + dy[dir];
			int nx = pos.x + dx[dir];
			if (ny < 0 || nx < 0 || ny >= r || nx >= c)
				continue;
			if (arr[ny][nx] == 'X')
			{
				arr[ny][nx] = '.';
				q_ices_next.push(Pos(ny, nx));
				continue;
			}
		}
	}
}

int main(void)
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	std::cin >> r >> c;
	Pos swan(0, 0);
	for (int i = 0; i < r; i++)
	{
		std::string str;
		std::cin >> str;
		for (int j = 0; j < c; j++)
		{
			arr[i][j] = str[j];
			if (arr[i][j] == 'L')
			{
				swan.y = i;
				swan.x = j;
			}
			if (arr[i][j] != 'X')
			{
				q_ices.push(Pos(i, j));
			}
		}
	}
	q_swan.push(Pos(swan));
	visited_swan[swan.y][swan.x] = true;

	int count = 0;
	while (!Bfs_swan())
	{
		count++;	
		Bfs_ice();
		while (q_swan_next.size())
		{
			q_swan.push(q_swan_next.front());
			q_swan_next.pop();
		}
			
		while (q_ices_next.size())
		{
			q_ices.push(q_ices_next.front());
			q_ices_next.pop();
		}
			
	}
	std::cout << count;
	return 0;
}