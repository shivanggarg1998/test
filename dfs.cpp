#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Graph {
	vector<vector<int> > v;
	int nv;

	void bfsHidden(int src, vector<bool>& visited) {
		queue<int> q;
		q.push(src);
		visited[src] = true;

		while (q.empty() == false) {
			int curVtx = q.front();
			q.pop();
			cout << curVtx << " ";

			for (int i = 0; i < v[curVtx].size(); ++i) {
				int ngbr = v[curVtx][i];
				if (visited[ngbr] == false) {
					q.push(ngbr);
					visited[ngbr] = true;
				}
			}
		}
	}


	void tarjan(int src, vector<bool>& visited, vector<int>& ans) {
		visited[src] = true;
		for (int i = 0; i < v[src].size(); ++i) {
			int ngbr = v[src][i];

			if (visited[ngbr] == false) {
				tarjan(ngbr, visited, ans);
			}
		}
		ans.push_back(src);
	}

public:
	Graph(int n) {
		v.resize(n + 1);
		nv = n;
	}

	void addEdge(int src, int dest, bool isBirectional = false) {
		v[src].push_back(dest);
		if (isBirectional == true) v[dest].push_back(src);
	}

	void dfs(int src, vector<bool>& visited) {
		visited[src] = true;
		cout << src << " ";

		for (int i = 0; i < v[src].size(); ++i) {
			int ngbr = v[src][i];
			if (visited[ngbr] == false) {
				dfs(ngbr, visited);
			}
		}
	}

	void connectedComponents() {
		vector<bool> visited(nv + 1, false);

		for (int v = 1; v <= nv; ++v) {
			if (visited[v] == false) {
				dfs(v, visited);
				cout << endl;
			}
		}
	}

	void bfs(int src) {
		vector<bool> visited(nv + 1, false);
		bfsHidden(src, visited);
	}

	int shortestDistance(int src, int dest) {
		const int inf = 1e7;
		vector<int> distance(nv + 1, inf);
		vector<int> parent(nv + 1, 0);

		//vector<bool> visited(nv+1);

		queue<int> q;
		q.push(src);
		//visited[src] = true;
		distance[src] = 0;
		parent[src] = 0;
		while (q.empty() == false) {
			int curVtx = q.front();
			q.pop();

			for (int i = 0; i < v[curVtx].size(); ++i) {
				int ngbr = v[curVtx][i];
				//if(visited[ngbr]==false){}
				if (distance[ngbr] == inf) {
					q.push(ngbr);
					//visited[ngbr]=true;
					distance[ngbr] = distance[curVtx] + 1;
					parent[ngbr] = curVtx;
				}

			}
		}


		//printing the path
		int x = dest;
		while (x != src) {
			cout << x << "<--";
			x = parent[x];
		}
		cout << x << endl;
		return distance[dest];
	}
	vector<int> tarjan() {
		vector<bool> visited(nv + 1, false);
		vector<int> ans;

		for (int i = 1; i < nv; ++i) {
			if (visited[i] == false) {
				tarjan(i, visited, ans);
			}
		}
		reverse(ans.begin(), ans.end());
		return ans;
	}

	vector<int> topological() {
		vector<int> indegree(nv + 1, 0);

		for (int cur = 1; cur <= nv; ++cur) {
			for (int i = 0; i < v[cur].size(); ++i) {
				int ngbr = v[cur][i];
				indegree[ngbr]++;
			}
		}
		queue<int> q;
		for (int i = 1; i <= nv; ++cur) {
			if (indegree[i] == 0) q.push(i);
		}
		vector<int> ans;
		while (q.empty() == false) {
			int reqBeingFulfilled = q.front();
			ans.push_back(reqBeingFulfilled);
			q.pop();

			for (int i = 0; i < v[reqBeingFulfilled].size(); ++i) {
				int ngbr = v[reqBeingFulfilled][i];
				indegree[ngbr]--;
				if (indegree[ngbr] == 0) {
					q.push(ngbr);
				}
			}
		}
		return ans;
	}

};
int main() {

	Graph g(36);
	int snakeLadder[37] = {}; //Zero initialised
	snakeLadder[2] = 7;
	snakeLadder[9] = 27;
	snakeLadder[17] = 4;
	snakeLadder[18] = 29;
	snakeLadder[20] = 6;
	snakeLadder[24] = 16;
	snakeLadder[25] = 35;
	snakeLadder[32] = 30;
	snakeLadder[34] = 12;

	for (int box = 1; box < 36; ++box) {
		for (int dice = 1; dice <= 6; ++dice) {
			if (dice + box <= 36)
			{
				int dest = box + dice;
				if (snakeLadder[dest] != 0) dest = snakeLadder[dest];
				g.addEdge(box, dest);
			}
		}
	}
	cout << g.shortestDistance(1, 36);

}
