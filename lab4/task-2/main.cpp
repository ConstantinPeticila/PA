#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <cstring>
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
	string expr;

	void read_input() {
		ifstream fin("in");
		fin >> n >> expr;
		expr = " " + expr; // adaugare caracter fictiv - indexare de la 1
		fin.close();
	}

	int get_result() {

		string simboluri ;
		for(int i = 1;i <= n ;i++)
		{
			if(expr[i] == 'T' || expr[i] == 'F')
			{
				simboluri += expr[i];
			}
		}

		string operatii;
		
		for(int i = 1;i <= n ;i++)
		{
			if(expr[i] != 'T' && expr[i] !=  'F')
			{
				operatii += expr[i];
			}
		}
		
		
	int nrsimb = simboluri.size();


	//T[i][j] nr de moduri in care putem paranteza subexpresia de la i la j astfel incat sa fie adevarata
	//F[i][j] --------falsa
	long F[nrsimb][nrsimb], T[nrsimb][nrsimb];
 

    for (int i = 0; i < nrsimb; i++)
    {
    	for(int j = 0; j < nrsimb ;j++)
    		T[i][j] = F[i][j] =0;
    	if(simboluri[i] == 'T') 
    		//diagonala o sa fie 1 pt T daca pe pozitia i din simblouri se afla True
    		//subsecventa de la i la i
    		T[i][i] = 1;
    	else F[i][i] = 1;
    }

    //completam toate diferentele de lungime pt secvente de pe linia i ;T[i][i+1];T[i][i+2]
    for (int dif=1; dif<nrsimb; ++dif)
    {
        for (int i=0, j=dif; j<nrsimb; ++i, ++j)
        {
            T[i][j] = F[i][j] = 0;
            for (int g=0; g<dif; g++)
            {
            	//gasim locul parantezarii folosind decalajul curent 
                int k = i + g;
                //salvam valaorea totala pt (i,k) si (k+1,j)
                long tik = (T[i][k] + F[i][k])%kMod;
                long tkj = (T[k+1][j] + F[k+1][j])%kMod;

				//formulele recursive in functie de operatori          
                if (operatii[k] == '&')
                {
                    T[i][j] = (T[i][j] + (T[i][k]*T[k+1][j])%kMod)%kMod;
                    F[i][j] = (F[i][j] + ((tik*tkj)%kMod - (T[i][k]*T[k+1][j])%kMod)%kMod)%kMod;
                   
                }
              else  if (operatii[k] == '|')
                {
                    F[i][j] =(F[i][j] + (F[i][k]*F[k+1][j])%kMod)%kMod;
                    T[i][j] = (T[i][j]+((tik*tkj)%kMod - (F[i][k]*F[k+1][j])%kMod)%kMod)%kMod;
                    
                }
                else if (operatii[k] == '^')
                {
                    T[i][j] = (T[i][j] + ((F[i][k]*T[k+1][j])%kMod + (T[i][k]*F[k+1][j])%kMod)%kMod)%kMod;
                    F[i][j] = (F[i][j] + ((T[i][k]*T[k+1][j])%kMod + (F[i][k]*F[k+1][j])%kMod)%kMod)%kMod;
                	
                }
                else cout <<"errrrrorrrrr"<<endl;
                for(int ii = 0 ; ii < nrsimb ;ii++){
						for(int jj = 0 ; jj < nrsimb ; jj++)
							cout<<T[ii][jj]<<" ";
						cout <<endl;
						}
					cout<<"-----------" <<endl;
            }
        }

    }
  
  	cout <<"------>>>>>>>>>"<< T[0][nrsimb-1]%kMod;
    return T[0][nrsimb-1];
}
	
		
	

	void print_output(int result) {
		ofstream fout("out");
		fout << result << '\n';
		fout.close();
	}
};

int main() {
	Task task;
	task.solve();
	return 0;
}
