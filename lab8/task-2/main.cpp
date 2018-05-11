#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <queue>
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
	
	void read_input() {
		ifstream fin("in");
		fin >> n >> m;
		for (int i = 1, x, y; i <= m; i++) {
			fin >> x >> y;
			adj[x].push_back(y);
			adj[y].push_back(x);
		}
		fin.close();
	}

	vector<int> get_result() {
		vector<bool> visited(n+1,false);
		vector<int> discovery_time(n+1);
		vector<int> low_time(n+1);
		vector<int> parent(n+1,-1);
		vector<bool> sol(n+1,false);
		vector<int> result;

		for(int i=1;i<=n;i++){
			if(!visited[i])
				cut_vertex(i,visited,discovery_time,low_time,parent,sol);		
		
			if(sol[i])
				result.push_back(i);
		}
		
		return result;
	}

	void cut_vertex(int node,vector<bool> &visited,vector<int> &discovery_time,vector<int> &low_time,vector<int> &parent,vector<bool> &sol){
		
		static int time = 0;
		
		visited[node] = true;
		
		low_time[node] = discovery_time[node] = ++time;
		
		int nr_copii=0;
		
		for(int i=0;i<adj[node].size();i++){
			int next_node = adj[node][i];
			
			if(!visited[next_node]){
				parent[next_node] = node;
				nr_copii++;
				
				cut_vertex(next_node,visited,discovery_time,low_time,parent,sol);
				low_time[node] = min(low_time[node],low_time[next_node]);

				if(parent[node] == -1 && nr_copii > 1)
					sol[node] = true;
				else if(parent[node] != -1 && low_time[next_node] >= discovery_time[node])
					sol[node] = true;

			}
			else if(next_node != parent[node])
				low_time[node] = min(low_time[node],discovery_time[next_node]);
		}

	}

	void print_output(vector<int> result) {
		ofstream fout("out");
		for (int i = 0; i < int(result.size()); i++) {
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
