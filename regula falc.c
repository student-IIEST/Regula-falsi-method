include <stdio.h>
include <math.h>

double f(double x){          // f(x)=e^x-3x
    return exp(x)-3.0*x;
}
int main(void){
    double a=0.0,b=1.0,c fa=f(a),fb=f(b);
    const double tol=1e-6;

    if(fa*fb>0.0){
        printf("choose a and b such that f(a) and f(b) have opposite sign.\n");
        return 1;
    }
    
    do{
        //false-position intersection(equivalent forms are okay)
        c=(a*fb-b*fb)/(fb-fa);
        double fc=f(c);

        if(fa*fc<0.0){b=c;fb=fc;}
        else       {a=c;fa=fc;}
    }while(fabs(f(c))>=tol);
    printf("Required root is:%.4f\n",c);
    return 0;
}

