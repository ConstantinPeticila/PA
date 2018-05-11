#include <fstream>
#include <iomanip>
#include <vector>
#include <algorithm>
using namespace std;
#define INF 9999

class Task {
 public:
	void solve() {
		read_input();
		print_output(get_result());
	}

 private:
	int n, S;
	vector<int> v;

	void read_input() {
		ifstream fin("in");
		fin >> n >> S;
	//	printf("%d\n",S );
		v.push_back(-1); // adaugare element fictiv - indexare de la 1
		for (int i = 1, e; i <= n; i++) {
			fin >> e;
			v.push_back(e);
		}
		fin.close();
	}

bool static comparator (int a, int b)
	 {

    return a < b;
	}


	
	int get_result() {
	sort(v.begin(),v.end(),comparator );	
	//pe pozitia i din dp[] se va afla nr minin de monezi echivalente cu i	
    int dp[S+1];

 	//caz de baza
 	dp[0] = 0;
 	//initializez cu infinit 
 	for(int i = 1; i <= S;i++)
 	{
 		dp[i] = INF;
 	}
 
 	for(int j = 1; j <= n;j++)
 	{ //pentru fiecare tip de moneda
 		for(int i = 1;i <= S;i++)
 		{ //pentru fiecare valoare pana la suma pe care trb sa o echivalez
 			if(i >= v[j])
 			{ //verific moneda e mai mica decat suma ce se poate calcula cu ea
 				 //daca nu echivalat suma din dp[i] cu un nr mai mic de monezi
 					dp[i] = 1 + dp[i - v[j]];
 				
 			}

 		}
 	}

 
 	if(dp[S] == INF)
 		return -1;
 	return dp[S];

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
