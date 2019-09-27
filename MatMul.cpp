// Matrix multiplication performance
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

int i,j,k;
//const int maxpow = 4;
//const int maxsize = pow(10.,2*maxpow);
float A[100000000], B[100000000], C[100000000];
clock_t t1,t2,t3; //way of defining variables for t, also: long long t1,t2,t3 because of huge size
float n,dt1,dt2,dt1av,dt2av;

int main(){
    srand(clock());
    
    std::cout << "Dimension n of square matrix" << std::endl;
    std::cin >> n;
    
    if (n>10000) {
        std::cout << "Dimension n should be less than " << 10000 << "." << std::endl;
        exit(1);
    } else {
        for (i=0; i<pow(n,2); i++) {
            A[i]=rand()%9+1; // using modulo to avoid arbitrarly large numbers
            B[i]=rand()%9+1;
            C[i]=0.;
        }
        dt1av=0.;
        dt2av=0.;
        
        for (int l=0; l<5; l++) {
            t1=clock();
            for (i=0; i<n; i++) {
                for (j=0; j<n; j++) {
                    for (k=0; k<n; k++) {
                        C[i*int(n)+j] += A[i*int(n)+k]*B[k*int(n)+j];
                        //C[i][j] += A[i][k] * B[k][j]; //have to declare it with the max depth I'll need
                    }
                }
            }
            t2=clock();
            for (i=0; i<n; i++) {
                for (k=0; k<n; k++) {
                    for (j=0; j<n; j++) {
                        C[i*int(n)+j] += A[i*int(n)+k]*B[k*int(n)+j];
                    }
                }
            }
            t3=clock();
            dt1=t2-t1;
            dt2=t3-t2;
            dt1av+=dt1/5.;
            dt2av+=dt2/5.;
        }
        
        std::cout << "Average time for matrix multiplication of rank " << n << std::endl ;
        std::cout << "with method ijk : " << dt1av << std::endl;
        std::cout << "with method ikj : " << dt2av << std::endl;
        
    }
    
    return 0;
}


// SOME OUTPUTS
/*
 wl047:CppCourse aidanwastiaux$ ./a.out
 Dimension n of sparse matrix
 300
 Average time for matrix multiplication of rank 300
 with method ijk : 149840
 with method ikj : 135081
 
 wl047:CppCourse aidanwastiaux$ ./a.out
 Dimension n of sparse matrix
 500
 Average time for matrix multiplication of rank 500
 with method ijk : 719224
 with method ikj : 631994
 
 wl047:CppCourse aidanwastiaux$ ./a.out
 Dimension n of sparse matrix
 1000
 Average time for matrix multiplication of rank 1000
 with method ijk : 9.29078e+06
 with method ikj : 5.04963e+06
 */
