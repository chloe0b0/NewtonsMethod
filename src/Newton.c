#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double f(double x){
    return x*x - 2.0;
}

double f_(double x){
    return 2.0*x;
}

double NewtonsMethod(double (*f)(double), double (*f_)(double), unsigned int max_iters){
    double x0, x1, y, y_;
    x0 = 1.0;

    for (int i = 0; i < max_iters; ++i){
        y = f(x0);
        y_ = f_(x0);

        x1 = x0 - (y/y_);
        x0 = x1;
    }

    return x1;
}

int main(void){
    double root = NewtonsMethod(&f, &f_, 50);
    printf("%f \n", root);
}