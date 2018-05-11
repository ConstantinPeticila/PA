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
	vector<<int> intrari;

	void read_input() {
		ifstream fin("in");
		fin >> n >> m;
		for (int i = 1, x, y; i <= m; i++) {
			fin >> x >> y;
			adj[x].push_back(y);
			intrari[i]++;
		}
		fin.close();
	}

	vector<int> get_result() {

	   
		queue<int> q;

		for(int i = 1; i <= n ;i++){
			if(intrari[i] == 0){
				topsort.push_back(i);
				q.push(i);
			}
		}

		while(!q.empty()){
			int u = q.front();
			q.pop();
			for(int i = 0; i < adj[u].size();i++){
				intrari[adj[u][i]]--;
				if(intrari[adj[u][i]] == 0){
					topsort.push_back(adj[u][i]);
					q.push(adj[u][i]);
				}
			}
		}

		if(topsort.size() < n -1){
			vector<int> null;
			return null;
		}

		return topsort;
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
