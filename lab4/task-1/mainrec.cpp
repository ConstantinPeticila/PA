
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

const int kMod = 1e9 + 7;

class Task {
 public:
	void solve() {
		read_input();
		print_output(get_result());
	}

 private:
	int n;
	vector<int> v;

	void read_input() {
		ifstream fin("in");
		fin >> n;
		v.push_back(-1); // adaugare element fictiv - indexare de la 1
		for (int i = 1, e; i <= n; i++) {
			fin >> e;
			v.push_back(e);
		}
		fin.close();
	}

	
	int pow1(int a, unsigned int b)
	{
		if(b == 0)
			return 1;
		long long t = pow1(a,b/2)%kMod;
		if((b%2) == 0)
			return (t*t)%kMod;
		else 
			return (a *(t*t)%kMod)%kMod;
	} 

	
	int get_result() {

		int sum = 0, dp[n];
		
		for(int i = 0;i < n ; i++)
			dp[i] = 0;

		if(v[1]%2 == 0)
		 {
			sum = 1;
			dp[0] =1;
		 }
		if(n == 1) return sum;
		
		for(int i = 1;i < n;i++){
			if(v[i+1] %2 == 0)
				dp[i] = (2*dp[i-1] + 1)%kMod;
			else dp[i] = pow1(2,i) -1;

		}
		return dp[n-1];
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
