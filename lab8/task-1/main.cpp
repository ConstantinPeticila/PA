#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
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
	vector<int> adjt[kNmax];

	void read_input() {
		ifstream fin("in");
		fin >> n >> m;
		for (int i = 1, x, y; i <= m; i++) {
			fin >> x >> y;
			adj[x].push_back(y);
			adjt[y].push_back(x);
		}
		fin.close();
	}

	vector< vector<int> > get_result() {
		
		stack<int> stack;
		vector<int> visited(n+1,false);
		vector<vector<int> > sol;
		int node;
		
		for(int i=1;i<=n;i++)
			if(!visited[i])
				dfs1(visited,i,stack);
			
		for(int i=1;i<=n;i++)
			visited[i] = false;	
		

		while(1){
		
			node = stack.top();
		
			if(!visited[node]){
				visited[node] = true;

				vector<int> aux;
				aux.push_back(node);

				for(int i=0;i<adjt[node].size();i++)
					dfs2(visited,adjt[node][i],aux);
				
				sol.push_back(aux);
			
			}
			stack.pop();
			if(stack.empty() == true)
				break;
		}	

		return sol;
	}


	void dfs1(vector<int> &visited,int node,stack<int> &stack){
		
			visited[node] = true;
			for(int i=0;i<adj[node].size();i++)
				if(!visited[adj[node][i]])
					dfs1(visited,adj[node][i],stack);
			stack.push(node);
		
	}

	void dfs2(vector<int> &visited,int node,vector<int> &v){
		if(!visited[node]){
			visited[node] = true;
			v.push_back(node);
			for(int i=0;i<adjt[node].size();i++)
					dfs2(visited,adjt[node][i],v);
		}
	}

	void print_output(vector<vector<int> > result) {
		ofstream fout("out");
		fout << result.size() << '\n';
		for (const auto& ctc : result) {
			for (int nod : ctc) {
				fout << nod << ' ';
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
