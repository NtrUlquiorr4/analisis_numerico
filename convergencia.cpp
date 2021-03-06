#include <iostream>
#include <cmath>

using namespace std;


double fa(double);
double fb(double);
double fc(double);
double fd(double);
double fclase1(double);
double fclase2(double);

double alpha( double(*funcion)(double), double, double);

int main()
{
    double exactitud = 0.003;
    double diferencia = 1;
    double alpha1, alpha2;
    int n = 2; //TENDERÁ AL INFINITO
    while( diferencia > exactitud ){
            alpha1 = alpha(fd,0, n); //alpha(FUNCION, LIMITE, n) 
            alpha2 = alpha(fd, 0, n+1);
            diferencia = abs(alpha1 -  alpha2);
            n++;
    }
    cout << "Para la función  \"d\" [1.0/(n*n*n)], se tiene: \n";
    cout <<  "alpha = " << alpha1 << ", n creció hasta " << n << " para tener una exactitud de "<<exactitud<<'\n';
    
    return 0;
}

double alpha( double(*funcion)(double), double limite , double n)
{
    double xnmas1 = funcion(n+1);
    double xn = funcion(n);
    double xnmenos1 = funcion(n-1);
    return log(abs((xnmas1-limite)/(xn-limite)))/log(abs((xn-limite)/(xnmenos1-limite)));
}

double fclase1(double n)
{
    return 1.0/n; //limite 0
}

double fclase2(double n)
{
    return 1.0/pow(2.0,pow(2.0,n)); // limite 0
}


double fa(double n)
{
    return (n*n*n - 2*n +4)/(2*n*n*n + 1); // limite 0.5
}

double fb(double n)
{
    return 2.0/(pow(3.0, pow(3.0,n))+(n*n)); // limite 0
}

double fc(double n)
{
    double r = 0;
    double fact = 1;
    for(int i=0; i <= n; i++){
        r += 1.0/(fact);
        fact = fact*(i+1);  //limite e=2.71828
    }
    return r;
}

double fd(double n)
{
    return 1.0/(n*n*n); // limite 0
}

