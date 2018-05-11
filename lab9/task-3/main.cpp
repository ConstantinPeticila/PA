#include <fstream>
#include <vector>
#include <algorithm>
#include <queue>

#define inf 999999999
using namespace std;

const int kNmax = 105;

class Task {
 public:
	void solve() {
		read_input();
		compute();
		print_output();
	}

 private:
	int n;
	int d[kNmax][kNmax];
	int a[kNmax][kNmax];

	void read_input() {
		ifstream fin("in");
		fin >> n;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				fin >> a[i][j];
			}
		}
		fin.close();
	}


	void compute (){
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= n; j++){
                if(a[i][j] == 0)
                    d[i][j] = inf;
                else
                    d[i][j] = a[i][j];
            }    
        }

       
        for (int k = 1; k <= n; k++) {
             for (int i = 1; i <= n; i++){
				for (int j = 1; j <= n; j++){
				    if (d[i][k] + d[k][j] < d[i][j])
                        d[i][j] = d[i][k] + d[k][j];
				}
			}
		}		
               
   		 for(int i=1;i<=n;i++){
        	for(int j=1;j<=n;j++){
            	if(d[i][j]>= inf||i==j)
                	d[i][j] = 0;
       		}
    	}	

    }



	void print_output() {
		ofstream fout("out");
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				fout << d[i][j] << ' ';
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
