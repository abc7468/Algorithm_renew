#include<iostream>
#include<vector>
#include<unordered_map>
#include<set>
#include<string>
using namespace std;

unordered_map<string, int> person;
string personId[200001];
int parent[200001];
unordered_map<int, set<int>> con;



int find(int x) {
	if (parent[x] == x) {
		return x;
	}
	else {
		return parent[x] = find(parent[x]);
	}
}
int Union(int x, int y) {
	if (x > y) {
		int tmp = x;
		x = y;
		y = tmp;
	}
	int xP = find(x);
	int yP = find(y);
	if (xP == yP) {
		return con[xP].size();
	}
	for (int id : con[yP]) {
		con[xP].insert(id);
		parent[id] = xP;
	}
	con[yP].clear();
	return con[xP].size();
}




int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T; cin >> T;
	while (T--) {
		int id = 1;
		int nwk; cin >> nwk;
		for (int i = 0; i <= 2*nwk; i++) {
			parent[i] = i;
		}
		for (int i = 0; i < nwk; i++) {
			string person1, person2;
			cin >> person1;
			cin >> person2;
			if (person.find(person1) == person.end()) {
				person[person1] = id;
				personId[id] = person1;
				con[id].insert(id);
				id++;
			}
			else {

			}
			if (person.find(person2) == person.end()) {
				person[person2] = id;
				personId[id] = person2;
				con[id].insert(id);
				id++;
			}
			int tmp = Union(person[person1], person[person2]);
			cout << tmp << '\n';
		}




		person.clear();
		con.clear();
		
	}

	return 0;
}
