#include <fstream>
#include <vector>
using namespace std;

class Task {
 public:
	void solve() {
		read_input();
		print_output(get_result());
	}

 private:
	int n, m;
	vector<int> dist;

	void read_input() {
		ifstream fin("in");
		fin >> n >> m;
		for (int i = 0, d; i < n; i++) {
			fin >> d;
			dist.push_back(d);
		}
		fin.close();
	}

	int get_result() {

		int rez = 0,d = 0;
		for(int i =0;i < n -1;i++)
		{
			if( dist[i+1] -d > m){ //compar distanta la care vreau sa ajung cu ultima benzinarie la care am alimentat 
				rez++;
				d = dist[i];

			}
		}
		/*
		TODO: Aflati numarul minim de opriri necesare pentru a ajunge
		la destinatie.
		*/
		return rez;
	}

	void print_output(int result) {
		ofstream fout("out");
		fout << result;
		fout.close();
	}
};

int main() {
	Task task;
	task.solve();
	return 0;
}