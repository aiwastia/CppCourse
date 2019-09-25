//
//  DotProduct.cpp
//  
//
//  Created by Aidan Wastiaux on 24/09/2019.
//

#include "DotProduct.hpp"
#include <iostream>
//#include <cstdlib>

//srand(clock())
int main () {
    int dimvec, i;
    float vec1[100];
    float vec2[100];
    float dotprod=0, crossprod=0;
// pointers to the vectors
    float* loc1 = &vec1[0] ;
    float* loc2 = &vec2[0] ;

// input of dimension
    std:: cout << "Dimension (integer):";
    std:: cin >>  dimvec;
// input of vectors
    if (dimvec >= 100) {
        std:: cout << "Error: maximal size in this program is 100.";
        exit(1);
    } else {
        std:: cout << "Write the first vector a" << std::endl ;
        for(i=0;i < dimvec;i++){
            std:: cout << "Value ";
            std:: cin >> vec1[i];
        }
        std:: cout << "Write the second vector b" << std::endl ;
        for(i=0;i < dimvec;i++){
            std:: cout << "Value ";
            std:: cin >> vec2[i];
        }
    }
    
// dot product
    for(i=0;i < dimvec;i++) {
        dotprod += *(loc1+i) * *(loc2+i) ;
    }
    
// Levi-Civita symbol
//    int eps(i,j,k){
//        if (i==j)|(i==k)|(j==k) {
//            <#statements#>
//        } else {
//            <#statements#>
//        }
//    }
    
// cross product
//    for() {
//
//    }
    
    std:: cout << "a.b=" << dotprod << std::endl;
    return 0;
}
