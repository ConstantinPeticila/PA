#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <set>
#include <queue>
#include <tuple>
using namespace std;

const int kNmax = 2e5 + 10;
const int Inf = 1 << 30;

class Task {
 public:
	void solve() {
		read_input();
		print_output(get_result());
	}

 private:
	int n;
	int m;
	vector<pair<int, int> > adj[kNmax];
	int d[kNmax];
	int p[kNmax];
	priority_queue<pair<int, int>, vector<pair<int, int> >, std::greater<pair<int, int> > > min_heap;
	int used[kNmax];

	void read_input() {
		ifstream fin("in");
		fin >> n >> m;
		for (int i = 1, x, y, w; i <= m; i++) {
			fin >> x >> y >> w;
			adj[x].push_back(make_pair(y, w));
			adj[y].push_back(make_pair(x, w));
		}
		fin.close();
	}

	int get_result() {
		/*
		TODO: Calculati costul minim al unui arbore de acoperire
		folosind algoritmul lui Prim.
		*/
		for (int i = 1; i <= n; ++i) {
			d[i] = Inf;
			p[i] = 0;
			used[i] = 0;
		}

		int root = 1;
		d[root] = 0;
		min_heap.push(make_pair(d[root], root));

		int cost = 0;

		for (int i = 1; i <= n; ++i) {
			int node;

			
			do{
				auto e = min_heap.top();
				min_heap.pop();
				node = e.second;
			} while (used[node]);

			


			cost += d[node];
			used[node] = 1;

			for (auto x : adj[node]) {
				int neighbour = x.first;
				int neighbour_weight = x.second;

				if (neighbour_weight < d[neighbour])
				{
					d[neighbour] = neighbour_weight;
					p[neighbour] = node;
					min_heap.push( make_pair(d[neighbour], neighbour) );

				}
			}
		}

		return cost;
	}

	void print_output(int result) {
		ofstream fout("out");
		fout << result << "\n";
		fout.close();
	}
};

int main() {
	Task *task = new Task();
	task->solve();
	delete task;
	return 0;
}