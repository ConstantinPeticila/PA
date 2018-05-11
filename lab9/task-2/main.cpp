#include <fstream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cassert>
#include <climits>
using namespace std;

const int kNmax = 50005;

class Task {
 public:
	void solve() {
		read_input();
		print_output(get_result());
	}

 private:
	int n;
	int m;
	int source;
	vector<pair<int, int> > adj[kNmax];

	void read_input() {
		ifstream fin("in");
		fin >> n >> m >> source;
		for (int i = 1, x, y, w; i <= m; i++) {
			fin >> x >> y >> w;
			adj[x].push_back(make_pair(y, w));
		}
		fin.close();
	}

	vector<int> get_result() {
		
		vector<int> d(n + 1, 0);
		vector<bool> visited(n, false);

		for (int i = 1; i <= n; i++) {
			visited[i] = false;
			d[i] = INT_MAX/2;
		}
		
		d[source] = 0;
		for (int i = 0; i < adj[source].size(); i++ ) {
			int v = adj[source][i].first ;
			int w = adj[source][i].second;
			d[ v] = d[source] + w;
		}


		bool ok = false;

		//relaxari succesive
		for (int i = 1; i <= n - 2; i++) {
			if (ok == true)
				break;
			ok = true;
			for (int j = 1; j <= n; j++) {
				for (int k = 0; k < adj[j].size(); k++){
					int v = adj[j][k].first;
					int w = adj[j][k].second;
					if (d[v] > d[j] + w) {
						d[v] = d[j] + w;
						ok = false;
					}
				}
			}
		}

		//daca se mai pot face relaxari
		for (int j = 1; j <= n; j++) {
			for (int k = 0; k < adj[j].size(); k++){
				int u = adj[j][k].first;
				int w = adj[j][k].second;
				if (d[u] > d[j] + w) {
					return vector<int>();
				}		
			}
		}

		return d;
		/*
		TODO: Gasiti distantele minime de la nodul source la celelalte noduri
		folosind BellmanFord pe graful orientat cu n noduri, m arce stocat in adj.
			d[node] = costul minim / lungimea minima a unui drum de la source la nodul
		node;
			d[source] = 0;
			d[node] = -1, daca nu se poate ajunge de la source la node.

		Atentie:
		O muchie este tinuta ca o pereche (nod adiacent, cost muchie):
			adj[x][i].first = nodul adiacent lui x,
			adj[x][i].second = costul.

		In cazul in care exista ciclu de cost negativ, returnati un vector gol:
			return vector<int>();
		*/
	}

	void print_output(vector<int> result) {
		ofstream fout("out");
		if (result.size() == 0) {
			fout << "Ciclu negativ!\n";
		} else {
			for (int i = 1; i <= n; i++) {
				fout << result[i] << ' ';
			}
			fout << '\n';
		}
		fout.close();
	}
};

int main() {
	Task *task = new Task();
	task->solve();
	delete task;
	return 0;
}
