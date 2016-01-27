#pragma once

#include <cstdio>
#include <iostream>
#include <cassert>

class matrix {
public:
    float ** m;
    int rows;
    int cols;

    matrix( );
    matrix( const int rows, const int cols );
    matrix( const float ** o, const int rows, const int cols );
    matrix( matrix & m );

    friend std::ostream & operator << ( std::ostream &out, const matrix & a );

    matrix & operator = ( const matrix & o );
    matrix operator + ( const matrix & o ) const;
    matrix operator - ( const matrix & o ) const;
    matrix operator * ( const matrix & o ) const;

    void Fill( float v );
};