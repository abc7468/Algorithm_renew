#include<iostream>
#include<vector>
#include<queue>
using namespace std;

priority_queue < pair<int, pair<int, int>>> pq;
int parent[100001];

int getParent(int x) {
	if (parent[x] == x) return x;
	getP
}


int findParent(int a, int b) {

}

void unionParent(int a, int b) {

}

int main() {
	pq.push({ 7,{1,2} });
	pq.push({ 3,{2,4} });
	pq.push({ 10,{2,4} });


	return 0;
}