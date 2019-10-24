#include <stdio.h>
#include <assert.h>
#define eps 1e-5
#define True 1
#define False 0



float solve(float x, int n) {
    /*
     * Function that computes x^n using only multiplication and rising to the power of 2
     * :param x: real number
     * :param n: natural number
     * :post: the function will return the result x^n
     */

    if(n == 0) {
        return  1;
    }
    else if(n % 2 == 0) {
        return solve(x, n/2) * solve(x, n/2);
    }
    else return x * solve(x, n - 1);

}

void test_solve() {
    /*
     * Function that tests the solve function
     */

    assert((float)solve(3.14, 2) - (float)9.8596 <= eps);
    assert((float)solve(3, 3) - (float)27 <= eps);
    assert((float)solve(5.11, 5) - (float)3484.2116 <= eps);
    assert((float)solve(2, 6) - (float)64 <= eps);
}

float read_float() {
    /*
     * Function that reads a float number from keyboard
     * :return: The function will return the number
     */
    float num;
    printf("Dati baza numarului: ");
    scanf("%f", &num);
    return num;
}

int read_integer() {
    /*
     * Function that reads an integer number from keyboard
     * :return: The function will return the number
     */
    int num;
    printf("Dati exponentul: ");
    scanf("%d", &num);
    return num;
}


void print_result(float x, int n) {
    /*
     * Function that prints the result
     * :param x: float number - base
     * :param n: integer - exponent
     * :post: will print the result x^n
     */
    printf("\n%f\n", solve(x, n));
}

void ui() {
    /*
     * Function that prints the user menu
     */
    printf("Apasati tasta 1, pentru a efectua o ridicare la putere!\n"
           "Apasati tasta 2 pentru a iesi din aplicatie!\n\n");

    float x;
    int n;
    while(True) {
        int cmd = 0;
        printf("Comanda: ");
        scanf("%d", &cmd);
        if(cmd == 1){
            x = read_float();
            n = read_integer();
            print_result(x, n);
        }
        else {
            return;
        }

    }

}

int main() {
    test_solve();
    ui();

    return 0;
}