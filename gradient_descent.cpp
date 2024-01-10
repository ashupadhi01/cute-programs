#include <stdio.h>
#include <stdlib.h>
#define size 13
#define h 0.0001
#define alpha 0.01
#define num_epoch 20

// Declaring the three parameters of our linear model
double a;
double b;
double c;

double data[size][size][size][1];

double func(double x, double y, double z) {
    return 13 * x + 2 * y + 7 * z;
}

double model(double x, double y, double z) {
    return a * x + b * y + c * z;
}


double cost_function(double x, double y, double z, double label) {
    double pure_error = model(x, y, z) - label;
    return 0.5 * pure_error * pure_error;
}
// One parameter of this function is the point in input space, and the varible w.r.t which you wanna compute the gradient

double gradient(double x, double y, double z, char c, double label){

    double grad; 
    double new, old;

    if(c == 'a') {
        old = cost_function(x, y, z, label);
        a += h;
        new = cost_function(x, y, z, label);
        a -= h;
        grad = (new - old) / h;
    }

    else if(c == 'b') {
        old = cost_function(x, y, z, label);
        b += h;
        new = cost_function(x, y, z, label);
        b -= h;
        grad = (new - old) / h;
    }

    else {
        old = cost_function(x, y, z, label);
        a += h;
        new = cost_function(x, y, z, label);
        a -= h;
        grad = (new - old) / h;
    }

    return grad;
}

int main(void) {

    // Creating the dataset

    int index = 0;

    for(int x = 0; x < size; x++) {
        for(int y = 0; y < size; y++) {
            for(int z = 0; z < size; z++) {
                data[x][y][z][0] = func(x, y, z);
            }
        }
    }

    // Randomly intialising the prameters of out model consisting of 3 parameters: f(x, y, z) = a * x + b * y + c * z

    a = rand() % 100;
    b = rand() % 100;
    c = rand() % 100;

    // printf("a = %lf, b = %lf, c = %lf", a, b, c);
    
   
    // The training loop
    
    for(int epoch = 0; epoch < num_epoch; epoch++) {
        
        // Iterating through all the datapoints

        for(int x = 0; x < size; x++) {
            for(int y = 0; y < size; y++) {
                for(int z = 0; z < size; z++) {
                    printf("a = %lf, b = %lf, c = %lf\n", a, b, c);

                    double grad_a = gradient(x, y, z, 'a', data[x][y][z][0]);
                    a = a - alpha * grad_a;
                    double grad_b = gradient(x, y, z, 'b', data[x][y][z][0]);
                    b = b - alpha * grad_b;
                    double grad_c = gradient(x, y, z, 'c', data[x][y][z][0]);
                    c = c - alpha * grad_c;

                }
            }
        }

        printf("Next Epoch ....");       
    }

    printf("Parameters after learning: ");
    printf("a = %lf, b = %lf, c = %lf", a, b, c);

    return 0;
}
