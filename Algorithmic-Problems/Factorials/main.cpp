#include <iostream>
#include <cstring>
using namespace std;
char s[40];

int main()
{
    int n = 0, k = 0;
    cin.getline(s, sizeof(s));
    for(int i = 0; i<strlen(s); i++)
    {
        if(s[i] >= '0' && s[i] <= '9')
            n = n * 10 + s[i] - 48;
        if(s[i] == '!') k ++;
    }
    int divide = 1;
    if(n % k != 0) divide = 0;
    int factorial = 1;
    while(n > 0)
    {
        factorial *= n;
        n -= k;
    }
    cout << factorial;
    return 0;
}
