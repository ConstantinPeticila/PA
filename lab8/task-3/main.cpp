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

	struct Edge {
		int x;
		int y;
	};

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


	vector<Edge> get_result() {
		/*
		TODO: Gasiti muchiile critice ale grafului neorientat stocat cu liste
		de adiacenta in adj.
		*/

		vector<bool> visited(n+1,false);
		vector<int> discovery_time(n+1);
		vector<int> low_time(n+1);
		vector<int> parent(n+1,-1);
		vector<Edge> sol;


		for(int i=1;i<=n;i++)
			if(!visited[i])
				bridge(i,visited,discovery_time,low_time,parent,sol);		


		return sol;
	}


	void bridge(int node,vector<bool> &visited,vector<int> &discovery_time,vector<int> &low_time,vector<int> &parent,vector<Edge> &sol){
		
		static int time = 0;
		
		visited[node] = true;
		
		low_time[node] = discovery_time[node] = ++time;
		
		int nr_copii=0;
		
		for(int i=0;i<adj[node].size();i++){
			int next_node = adj[node][i];
			
			if(!visited[next_node]){
				parent[next_node] = node;
				bridge(next_node,visited,discovery_time,low_time,parent,sol);
				low_time[node] = min(low_time[node],low_time[next_node]);

				if(low_time[next_node] > discovery_time[node]){
					struct Edge edge;
					edge.x = node;
					edge.y = next_node;
					sol.push_back(edge);
				}

			}
			else if(next_node != parent[node])
				low_time[node] = min(low_time[node],discovery_time[next_node]);
		}

	}



	void print_output(vector<Edge> result) {
		ofstream fout("out");
		fout << result.size() << '\n';
		for (int i = 0; i < int(result.size()); i++) {
			fout << result[i].x << ' ' << result[i].y << '\n';
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
