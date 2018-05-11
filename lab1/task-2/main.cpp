#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <stdlib.h>
#include  <bits/stdc++.h>
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





	double compute_sqrt() {
		double mare,mic;
		if(n < 1) {
			mic = n;
			mare = 1;
		}
		else 
			{mic = 0;
			mare = n;}
			double mij = (mic+mare)/2;

			while(fabs(mij*mij - n) >= 0.0001){
			 mij = (mic + mare)/2;
				if(mij*mij <= n) 
					mic = mij;
				else
					mare = mij;
				
			}
			
				return mij;
		
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
