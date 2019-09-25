// Matrix multiplication performance
#include <iostream>
#include <cstdlib>

int n,i,j,k;
float A[10**6], B[10**6], C[10**6];

srand(clock());

int main(){
    std::cout << "Dimension n of sparse matrix" << std::endl;
    std::cin >> n;
    
    if (n>1000) {
        std:cout << "Dimension n should be less than 1000.";
        exit(0)
    } else {
        for (i=1; i<=n**2; <#increment#>) {
            <#statements#>
        }
    }
    
    return 0
}
