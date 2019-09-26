// Recursive function : Fibonacci series a_n=a_(n-1)+a_(n-2), a_0=1, a_1=1
#include <iostream>

double N,fibN;

// very slow version and  memory overload
/*
double Fibonacci(double N){
    double last;
    if (N==0) {
        last=1;
    } else if (N==1) {
        last=1;
    } else {
        last=Fibonacci(N-1)+Fibonacci(N-2);
    }
    return last;
}
*/

double Fibonacci(int N){
    double a,b,c;
    int i;
    a=1;
    b=1;
    if (N<0){
        std::cout << "The rank should be non-negative." << std::endl;
        exit(1);
    } else if (N>1){
        for (i=1; i<=N-1; i++) {
            a=a+b;
            c=a;
            a=b;
            b=c;
        }
    }
    return a;
}
int main(){
    
    std::cout << "Rank of desired Fibonacci number : ";
    std::cin >> N;
    fibN=Fibonacci(N);
    std::cout << "The " << N << "th Fibonacci number is " << fibN << std::endl;
    
    return 0;
}
