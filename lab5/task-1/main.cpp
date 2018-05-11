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
	int n, k;

	void read_input() {
		ifstream fin("in");
		fin >> n >> k;
		fin.close();
	}

	bool check(vector<int> v,int k){
		int i = 0;
		while(i < k)
		{
			if(v[k] == v[i])
				return false;
			i++;
		}
			return true;
	}

	void backtracking(int crt,vector<int> v,vector<vector<int> > *all){
		
		if(crt == k)
		 {
			all->push_back(v);
			cout<<all->size();
			//break;
		}
	else
		{
			

			int i = 1;
			while (i <= n)
			{
				v.push_back(i);
				if(check(v,crt) == true)
				{
					backtracking(crt+1,v,all);
				}	
				v.pop_back();
				i++;
			}
		}
	}

	vector<vector<int> > get_result() 
	{
		vector<vector<int> > all;

		

		vector<int> x;
		backtracking(0,x,&all);
		return all;
	}

	void print_output(vector<vector<int> > result) {
		ofstream fout("out");
		fout << result.size() << '\n';
		for (int i = 0; i < (int)result.size(); i++) {
			for (int j = 0; j < (int)result[i].size(); j++) {
				fout << result[i][j] <<
					(j + 1 != result[i].size() ? ' ' : '\n');
			}
		}
		fout.close();
	}
};

int main(){
	Task task;
	task.solve();
	return 0;
}
