#include <fstream>
#include <vector>
#include <algorithm>
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

	vector<int> aparitie;


	void back(int k,vector<int> v,vector<vector<int> > *all)
	{
			
		int i = (k > 0) ? v[k-1] +1 : 1;
			while(i<=n)
			{
				v.push_back(i);
				all->push_back(v);
				back(k+1,v,all);
				

				v.pop_back();

				i++;	
		}
	}

	vector<vector<int> > get_result()
	 {
		vector<vector<int> > all;

		vector<int> v;
		all.push_back(v);
		back(0,v,&all);
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

int main() {
	Task task;
	task.solve();
	return 0;
}
