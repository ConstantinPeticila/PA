#include <fstream>
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>
using namespace std;

const int kNmax = 100005;

class Task {
 public:
	void solve() {
		read_input();
		print_output(get_result());
	}

 private:
	int n;
	int m;
	vector<int> adj[kNmax];
	vector<int> topsort; //vectorul in care o sa tin sortarile

	void read_input() {
		ifstream fin("in");
		fin >> n >> m;
		for (int i = 1, x, y; i <= m; i++) {
			fin >> x >> y;
			adj[x].push_back(y);
		}
		fin.close();
	}

	vector<int> get_result() {

	    vector<bool> visited(n + 1, false); //pentru verificare nod vizitat
	    vector<int> ret;
	    
	    int i = 1,j = n-1;
	    while( i <= n) { //pentru fiecare nod aplic dfd
			DFS(visited, i);
			i++;
	    }
		

	    while (j >= 0) {
	    	ret.push_back(topsort[j]); //apoi intorc in oridie inversa
	    	j--;
	    }
		return ret;
	}

	void DFS(vector<bool>& visited, int u) {
		if (visited[u])	//verific daca e vizitat apoi il vizitez
			return;
		
		 

		int i = 0;
		while( i < adj[u].size()) { //pentru fiecare nod adiacent repet
			DFS(visited, adj[u][i]);
			i++;
		}

		topsort.push_back(u); // cand nu mai are vecini il pun in vector
	
		visited[u] = true;
	}

	void print_output(vector<int> result) {
		ofstream fout("out");
		for (int i = 0; i < int(result.size()); i++) {
			cout << result[i] << ' ';
		
			fout << result[i] << ' ';
		}
		fout << '\n';
		fout.close();
	}
};

int main() {
	Task *task = new Task();
	task->solve();
	delete task;
	return 0;
}
