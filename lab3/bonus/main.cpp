#include <bits/stdc++.h>
using namespace std;
#define N 1000
ifstream fin("custi.in");
ofstream fout("custi.out");

int rd[N][N], dp[N][N], wrt[N];

int minim (int a,int b,int c)
{

    if(a  > b)
        return min(b,c);
    return min(a,c);
}


int main()
{
    int n, i, j;
    fin >> n;

    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            fin >> rd[i][j];

    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            if (rd[i][j] == 1) // in caz ca e valida
            {
                dp[i][j] = 1 +minim(dp[i-1][j],dp[i][j-1],dp[i-1][j-1]); //dimenisunea maxima a matricei curente
                wrt[dp[i][j]]++; //actualizez nr de submatrici de dim fix aia
            }

    for (i = 1; i <= n; i++){
        for (j = 1; j <= n; j++)
            printf("%d ",dp[i][j] );      
        printf("\n");
    }

    for (i = n-1; i >= 1; i--)
        wrt[i] += wrt[i+1]; //nr de submatrici de dimensiune minim i

    for (i = 1; i <= n; i++)
        fout << wrt[i] << '\n';

    fin.close();
    fout.close();
    return 0;
}