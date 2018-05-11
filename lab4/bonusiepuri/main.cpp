#include <fstream>
#include <cstring>
 
using namespace std;
 
#define kMod 666013
 
ifstream fin("iepuri.in");
ofstream fout("iepuri.out");
 
int a[3][3], sol[3][3], c[3][3];
 
void Inmultire(int a1[3][3], int a2[3][3]) {
    for (int i = 0; i < 3; i++) 
    {
        for (int j = 0; j < 3; j++)
         {
            c[i][j] = 0;
 
            for (int k = 0; k < 3; k++) 
                c[i][j] = (c[i][j] + (1LL * a1[i][k] * a2[k][j]) % kMod)%kMod;
                
            
        }
    }
 
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++)
            a1[i][j] = c[i][j];
    }
}
 
void Ridicare(int a[3][3], int n) {
    while (n) {
         if (n & 1) {
            n--;
            Inmultire(sol, a);
         }
         n >>= 1;
 
         Inmultire(a, a);
    }
}
 
 void Read() {
    int x, y, z, A, B, C, n, T;
 
    fin >> T;
 
    for(int i = 1;i <= T ;i++){
        fin >> x >> y >> z >> A >> B >> C >> n; //n++;
 
        if (n == 1) {
            fout << x << "\n";
            continue;
        }
        else if (n == 2) {
            fout << y << "\n";
            continue;
        }
        else if (n == 3) {
            fout << z << "\n";
            continue;
        }
 
        a[0][0] = 0; a[0][1] = 0; a[0][2] = C;
        a[1][0] = 1; a[1][1] = 0; a[1][2] = B;
        a[2][0] = 0; a[2][1] = 1; a[2][2] = A;
 
        
 
        sol[0][0] = sol[1][1] = sol[2][2] = 1;
 
        Ridicare(a, n -2);
 
        fout << ((1LL * sol[0][2] * z) % kMod+ (1LL * sol[1][2] * y) + (1LL * sol[2][2] * x) % kMod) % kMod << "\n";
    }
}
 
int main () {
    Read();
  return 0;
}


