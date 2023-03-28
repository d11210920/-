#include<iostream>
#include<vector>
#include<cmath>
#define MAX 987654321

using namespace std;

int n, m, Chicken_Num, Answer = MAX;
int city[51][51];
bool visited[14];

vector<pair<int, int>> home, chicken, v;

int Min(int A, int B) { if (A < B) return A; return B; }

void Input(){
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> city[i][j];
			if (city[i][j] == 1) home.push_back(make_pair(i, j));
			if (city[i][j] == 2) chicken.push_back(make_pair(i, j));
		}
	}
	Chicken_Num = chicken.size();
}

int Calculate_Distance(){
	int Sum = 0;
	for (int i = 0; i < home.size(); i++)
	{
		int x = home[i].first;
		int y = home[i].second;
		int d = MAX;

		for (int j = 0; j < v.size(); j++){
			int nx = v[j].first;
			int yy = v[j].second;
			int Dist = abs(nx - x) + abs(yy - y);

			d = Min(d, Dist);
		}
		Sum = Sum + d;
	}
	return Sum;
}

void Select_Chicken(int Idx, int Cnt){
	if (Cnt == m)
	{
		Answer = Min(Answer, Calculate_Distance());
		return;
	}

	for (int i = Idx; i < Chicken_Num; i++)	{
		if (visited[i] == true) continue;
		visited[i] = true;
		v.push_back(chicken[i]);
		Select_Chicken(i, Cnt + 1);
		visited[i] = false;
		v.pop_back();
	}
}

void Solution(){
	Select_Chicken(0, 0);
	cout << Answer << endl;
}

void Solve()
{
	Input();
	Solution();
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	Solve();

	return 0;
}
