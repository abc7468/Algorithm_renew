#include<iostream>
#include<vector>
using namespace std;
pair<int, int> people[50];
vector<int> tmp;
int main() {
	int N; cin >> N;

	for (int i = 0; i < N; i++) {
		int w, h; cin >> w >> h;
		people[i] = {w,h};
	}
	int rank = 1;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			if (people[i].first < people[j].first && people[i].second < people[j].second)
				rank++;
		cout << rank << ' ';
		rank = 1;
	}




	return 0;
}