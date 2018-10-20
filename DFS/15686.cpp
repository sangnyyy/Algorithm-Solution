#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
#include <cstring>
#include <math.h>
#define DIST 987654321
using namespace std;

vector<pair<int, int>> chicken;
vector<pair<int, int>> house;
vector<int> choose;

int a[51][51];
int n, m, rem, total, ans;

void dfs(int now, int depth) {
	if (depth == 0) {
		int temp = 0;
		for (int i = 0; i < house.size(); i++)
		{
			int hx = house[i].second;
			int hy = house[i].first;
			int dist = DIST;
			for (int j = 0; j < choose.size(); j++)
			{
				int cy = chicken[choose[j]].first;
				int cx = chicken[choose[j]].second;
				dist = min(dist, abs(cy - hy) + abs(cx - hx));
			}
			temp += dist;
		}
		ans = min(ans, temp);
	}
	for (int i = now+1; i < chicken.size(); i++)
	{
		choose.push_back(i);
		dfs(i, depth - 1);
		choose.pop_back();
	}
}

int main() {
	ans = DIST;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> a[i][j];
			if (a[i][j] == 1) {
				house.push_back(make_pair(i, j));
			}
			if (a[i][j] == 2) {
				chicken.push_back(make_pair(i, j));
			}
		}
	}
	dfs(-1, m);
	cout << ans << '\n';
	return 0;
}
