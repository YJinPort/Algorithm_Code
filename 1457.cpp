#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int N, M, K;
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { 1, -1, 0, 0 };
int map[101][101];
int visit[101][101];

int check(int x, int y)
{
	int cnt = 1;
	stack<pair<int, int>> s;
	s.push({ x , y });
	visit[x][y] = 1;
	while (!s.empty())
	{
		pair<int, int> cur = s.top();
		s.pop();
		if (visit[cur.first][cur.second] == 0)
			cnt++;
		visit[cur.first][cur.second] = 1;


		for (int i = 0; i < 4; i++)
		{
			int nx = cur.first + dx[i];
			int ny = cur.second + dy[i];

			if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;

			if (map[nx][ny] == 1 || visit[nx][ny] == 1) continue;

			s.push({ nx, ny });
		}
	}
	return cnt;
}

int main()
{
	vector<int> v;
	// M 세로 N 가로
	cin >> M >> N >> K;

	for (int i = 0; i < K; i++)
	{
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;

		for (int y = y1; y < y2; y++)
		{
			for (int x = x1; x < x2; x++)
			{
				map[x][y] = 1;
			}
		}
	}

	for(int y = 0; y < M; y++)
	{
		for (int x = 0; x < N; x++)
		{
			if (map[x][y] == 0 && visit[x][y] == 0)
			{
				v.push_back(check(x, y));
			}
		}
	}

	sort(v.begin(), v.end());

	cout << v.size() << endl;
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
	}

	return 0;
}