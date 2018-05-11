#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

class Task {
public:
	void solve() {
		read_input();
		print_output(compute_sqrt());
	}

private:
	double n;

	void read_input() {
		ifstream fin("in");
		fin >> n;
		fin.close();
	}


	double 	sqr(double n,double s,double d)
	{
		if(d-s <= 0.0001) return d;
		else 
		{
			double m =(s+d)/2;
			if(m*m < n) return sqr(n,m,d);
				else return sqr(n,s,m);
		}
	}


	double compute_sqrt() {
		if(n < 1) return sqr(n,0,1);
			else return sqr(n,0,n);
		return 0.0;
	}

	void print_output(double result) {
		ofstream fout("out");
		fout << setprecision(4) << fixed << result;
		fout.close();
	}
};

int main() {
	Task task;
	task.solve();
	return 0;
}
