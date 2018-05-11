#include <fstream>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Task {
 public:
	void solve() {
		read_input();
		print_output(get_result());
	}

 private:
	int n;

	void read_input() {
		ifstream fin("in");
		fin >> n;
		fin.close();
	}

	int check(vector<int> v,int k) //1 true
	{
		if(k != 1)
		 {
			
			for(int i=1;i<k;i++)
			{
				if(v[i] == v[k] || k+v[k] == i+v[i] || k+v[i] == i+v[k])
					return 0;
			}
		}	
			return 1;	
	}

	void backtracking(int k,vector<int> *v,int *ok){
		if(k == n+1){
			(*ok)=1; //conditie de oprire
			return;
		}
		for(int i=1;i<=n;i++){
			if(*ok == 0){
			(*v)[k]= i;
			if(check(*v,k) == 1)
				backtracking(k+1,v,ok);
			}
		}
	}

	vector<int> get_result() {
		vector<int> sol(n+1,0);

		
		int ok=0;
		backtracking(1,&sol,&ok);
		for(int i=1;i<=n;i++)
			cout<<sol[i]<<" ";
	

		return sol;
	}

	void print_output(vector<int> result) {
		ofstream fout("out");
		for (int i = 1; i <= n; i++) {
			fout << result[i] << (i != n ? ' ' : '\n');
		}	
		fout.close();
	}
};

int main() {
	Task task;
	task.solve();
	return 0;
}
