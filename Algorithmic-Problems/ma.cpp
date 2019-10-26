
#include <fstream>
using namespace std;
int main()
{
        int n, m, l, a[100][100], i, j, c;
        ifstream fin("matrixdel.in");
        fin >> l >> c >> n >> m;
        for(i = 1; i <= n; i++) {
                for(j = 1; j <= m; j++) {
                        fin >> a[i][j];
                }
        }
        fin.close();
        ofstream fout("matrixdel.out");
        fout << "Afisarea normala a matricei:\n\n";
        for(i = 1; i <= n; i++) {
                for(j = 1; j <= m; j++) {
                        fout << a[i][j] << " ";
                }
                fout << endl;
        }
        fout << "\n\nMatricea finala:";
        for(i = l + 1; i <= n; i++) {
                for(j = 1; j <= m; j++) {
                        a[i-1][j] = a[i][j];
                }
                fout << endl;
        }
        n--;
        for(i = 1; i <= n; i++) {
                for(j = c + 1; j <= m; j++) {
                        a[i][j-1] = a[i][j];
                }
        }
        m--;
        for(i = 1; i <= n; i++) {
                for(j = 1; j <= m; j++) {
                        fout << a[i][j] << " ";
                }
                fout << endl;
        }
        for(i = 1; i <= n; i++) {
                for(j = c + 1; j <= m; j++) {
                        a[i][j-1] = a[i][j];
                }
        }
        return 0;
}
