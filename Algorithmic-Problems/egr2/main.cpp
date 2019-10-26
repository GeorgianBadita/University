#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    int delta = b * b - 4 * a * c;
    delta = sqrt(delta);
    if(delta < 0) {cout << "Ecuatia nu are solutii reale"; return 0;}
    int x1 = (-b + delta) / (2 * a);
    int x2 = (-b - delta) / (2 * a);
    cout << "Solutiile sunt: " << x1 << ' ' << x2;
    return 0;
}
