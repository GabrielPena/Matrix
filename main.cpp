#include <iostream>
#include <thread>
#include <cstdlib>
#include "Matrix.h"

int main( ) {

    matrix A(3,3), B(3,3);

    A.Fill( 1 );
    B.Fill( 2 );

    matrix C = A * B;

    std::cout << C;

    std::getchar( );

    return 0;
}