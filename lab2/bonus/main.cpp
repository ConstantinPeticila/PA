#include <fstream>
#include <vector>
#include  <bits/stdc++.h>
using namespace std;


class Task {
 public:
	void solve() {
		read_input();
		print_output(get_result());
	}
	 int rez;

 private:
	int n,k;
	vector<int> a;
	vector<int> b;
	vector<int> c;

	void read_input() {
		ifstream fin("in2");
		fin >> n;
		fin >> k;
		for (int i = 0,ai; i < n; i++) 
		{
			fin >> ai ;
			a.push_back(ai);
			
		}
		for (int i = 0,ai; i < n; i++) 
		{
			fin >> ai ;
			b.push_back(ai);
			rez += b[i];

		}
		
		fin.close();
	}

	bool static comparator (int i1, int i2) 
	{
		
		return(i1 <i2);				
	}

	int get_result() {

		int aux = 0;

		for(int i = 0;i < n;i++)
		{
			c.push_back(a[i] - b[i]);
			
		}
		cout << endl;
		sort(c.begin(), c.end(),comparator);
		
		for(int i = 0;i < n;i++)
		{
			if(aux < k || c[i] < 0) rez+= c[i];
			aux ++;
		}

		return	rez;
	}

	void print_output(int result) {

		cout << result;
	
	}
};

int main() {
	Task task;
	task.rez = 0;
	task.solve();
	return 0;
}