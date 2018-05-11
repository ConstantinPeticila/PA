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
	int source;
	vector<int> adj[kNmax];

	void read_input() {
		ifstream fin("in");
		fin >> n >> m >> source;
		for (int i = 1, x, y; i <= m; i++) {
			fin >> x >> y;
			adj[x].push_back(y);
			adj[y].push_back(x);
		}
		fin.close();
	}

	vector<int> get_result() {
		vector<int> d(n + 1);
		vector<bool> visited(n + 1);
		for (int i = 1; i <= n; i++)
			visited[i] = false; //toate nodurile nevizitate
		visited[source] = true; //nodul sursa vizitat
		queue <int> queue;
		queue.push(source); //adaug nodul sursa in coada
		d[source] = 0;	//si ii setez distanta 0
		int node;
		int neighbor;
		bool ok = true;
		while (ok) 
		{
			node = queue.front(); //iau primul element din coada apoi il scot 
		
			int j = 0;
		 	while(j < adj[node].size()){
		 	//for (int i = 0; i < adj[node].size(); i++) //pentru toti vecinii
		 //	{

			  	if (!visited[adj[node][j]]) //verific daca nu a fost vizitat
				{
					queue.push(adj[node][j]); //apoi il adaug in coada
			
					d[adj[node][j]] = d[node] + 1; //ii isedez distanta
					visited[adj[node][j]] = true; //si il vizitez
				}
				j++;
			}
			queue.pop();
			if(queue.empty() == true){
				ok = false;
			}
			
		}
		for (int i = 1; i <= n; i++) //toate nodurile care nu au fost vizitate
		  	if(!visited[i])	//nu se poate ajunge la ele
		  		d[i] = -1;
		return d;
	}

	void print_output(vector<int> result) {
		ofstream fout("out");
		for (int i = 1; i <= n; i++) {
			cout << result[i] << (i == n ? '\n' : ' ');
			fout << result[i] << (i == n ? '\n' : ' ');
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
