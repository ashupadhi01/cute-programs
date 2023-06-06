#include <iostream>
using namespace std;
#define size 100

int t; 
int multiplicand[size] = {0};
int result[size] = {0};
int intermediate[size] = {0};

int no_of_digits(int a) {
    int count = 0;
    
    while(a > 0) {
        a /= 10;
        count++;
    }
    
    return count;
}

int add(int a) { 
    int k = t;
    int temp = 0;

    for(int i = 0; i < a; i++) {
        temp +=  result[k] + intermediate[i];
        result[k++] = temp % 10;
        temp /= 10;
    }

    t++;

    return k;
}

int product(int a, int b) {
    int k = 0, j = 0;

    while(a >= 0) {
        k += multiplicand[a--] * b;
        intermediate[j++] = k % 10;
        k /= 10;
    }
    
    if(k != 0) intermediate[j++] = k;

   return add(j);
}

int mul(int a, int b) {
    int k, temp, c;

    temp = no_of_digits(a) - 1;
    k = temp;

    while(a > 0) {
        multiplicand[k--] = a % 10;
        a /= 10;
    }  

    k = temp; 

    while(b > 0) {
        c = product(k, b % 10);
        b /= 10;
    }

    return c;
}

int main(void) {

    int a, b, c; 
    t = 0;
    cout << "Enter the two numbers to multiply: \n";
    cin >> a >> b;

    c = mul(a, b);
    for(int i = c - 1; i >= 0; i--) printf("%d ", result[i]);

    return 0;
}
