#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include  <bits/stdc++.h>
using namespace std;

struct Result {
	int len;
	vector<int> subsequence;
};

class Task {
 public:
	void solve() {
		read_input();
		print_output(get_result());
	}

 private:
	int n, m;
	vector<int> v;
	vector<int> w;

	void read_input() {
		ifstream fin("in");
		fin >> n >> m;

		v.push_back(-1); // adaugare element fictiv - indexare de la 1
		for (int i = 1, e; i <= n; i++) {
			fin >> e;
			v.push_back(e);
		}

		w.push_back(-1); // adaugare element fictiv - indexare de la 1
		for (int i = 1, e; i <= m; i++) {
			fin >> e;
			w.push_back(e);
		}

		fin.close();
	}

	Result get_result() {
		Result result;
		result.len = 0;


		int dp[n+1][m+1];
		int i, j;

		for (i=0; i<=n; i++)
		{
			for (j=0; j<=m; j++)
			{

				if (i == 0 || j == 0) // nu exista
					dp[i][j] = 0;

				else if (v[i] == w[j])  //daca sunt comune maresc subsirul maxim
					dp[i][j] = dp[i-1][j-1] + 1;

				else if (dp[i-1][j] > dp[i][j-1]) //lungimea ramane maximul dintre lungimi
					dp[i][j] = dp[i-1][j];
				else
					dp[i][j] =  dp[i][j-1];
				printf("%d  ",dp[i][j] );
			}
			printf("\n");
		}
	
	 result.len = dp[n][m]; //lungimea subsirului

	 i = n,j = m;
	while( i > 0 && j > 0) //cat timp nu am parcus in intregime niciunul din siruri
	{
		
		if(v[i] == w[j]) //daca am element comun pun in vector si decrementez ambele siruri
		{

			result.subsequence.push_back(v[i]);
			i--;
			j--;
		}
		else if(dp[i-1][j] > dp[i][j-1]) //decrementez astfel incat subsirul sa ramana maximal
			i--;
		else
			j--;
	}	

	return result;
	}



		
	void print_output(Result result) {
		ofstream fout("out");
		fout << result.len << '\n';
		for (int i = result.len -1 ; i >= 0; i--)
		 {
		 fout << result.subsequence[i]<<' ';
		}
		fout << '\n';
		fout.close();
	}
};

int main() {
	Task task;
	task.solve();
	return 0;
}
