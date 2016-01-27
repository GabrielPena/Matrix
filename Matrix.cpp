#include "Matrix.h"

matrix::matrix( ) {
    rows = 3;
    cols = 3;

    *m = new float[ rows ];

    for( int i = 0; i < cols; i++ ) {
        m[ i ] = new float[ cols ];
    }
}

matrix::matrix( const int rows, const int cols ) {
    this->rows = rows;
    this->cols = cols;

    m = new float*[ rows ];

    for( int i = 0; i < cols; i++ ) {
        m[ i ] = new float[ cols ];
    }

    for( int i = 0; i < rows; i++ ) {
        for( int j = 0; j < cols; j++ ) {
            m[ i ][ j ] = 0.0f;
        }
    }
}

matrix::matrix( const float ** o, const int rows, const int cols ) {
    this->rows = rows;
    this->cols = cols;

    m = new float*[ rows ];

    for( int i = 0; i < cols; i++ ) {
        m[ i ] = new float[ cols ];
    }

    for( int i = 0; i < rows; i++ ) {
        for( int j = 0; j < cols; j++ ) {
            m[ i ][ j ] = o[ i ][ j ];
        }
    }
}

matrix::matrix( matrix & o ) {
    rows = o.rows;
    cols = o.cols;

    m = new float*[ rows ];

    for( int i = 0; i < cols; i++ ) {
        m[ i ] = new float[ cols ];
    }

    for( int i = 0; i < rows; i++ ) {
        for( int j = 0; j < cols; j++ ) {
            m[ i ][ j ] = o.m[ i ][ j ];
        }
    }
}

matrix & matrix::operator=( const matrix & o ) {
    rows = o.rows;
    cols = o.cols;

    if( m == nullptr ) {
        m = new float*[ rows ];

        for( int i = 0; i < cols; i++ ) {
            m[ i ] = new float[ cols ];
        }
    }

    for( int i = 0; i < rows; i++ ) {
        for( int j = 0; j < cols; j++ ) {
            m[ i ][ j ] = o.m[ i ][ j ];
        }
    }

    return *this;
}

matrix matrix::operator + ( const matrix & o ) const {

    assert( rows == o.rows || cols == o.cols );
    matrix newM( rows, cols );

    for( int i = 0; i < rows; i++ ) {
        for( int j = 0; j < cols; j++ ) {
            newM.m[ i ][ j ] = m[ i ][ j ] + o.m[ i ][ j ];
        }
    }

    return newM;
}

matrix matrix::operator - ( const matrix & o ) const {
    assert( rows == o.rows || cols == o.cols );
    matrix newM( rows, cols );

    for( int i = 0; i < rows; i++ ) {
        for( int j = 0; j < cols; j++ ) {
            newM.m[ i ][ j ] = m[ i ][ j ] - o.m[ i ][ j ];
        }
    }

    return newM;
}

matrix matrix::operator * ( const matrix & o ) const {
    assert( cols == o.rows );
    matrix newM( rows, cols );

    for( int i = 0; i < rows; i++ ) {
        for( int j = 0; j < cols; j++ ) {
            for( int k = 0; k < cols; k++ ) {
                newM.m[ i ][ j ] += m[ i ][ k ] * o.m[ k ][ j ];
            }
        }
    }

    return newM;
}

void matrix::Fill( float v ) {
    for( int i = 0; i < rows; i++ ) {
        for( int j = 0; j < cols; j++ ) {
            m[ i ][ j ] = v;
        }
    }
}

std::ostream & operator << ( std::ostream &out, const matrix & a ) {
    for( int i = 0; i < a.rows; i++ ) {
        for( int j = 0; j < a.cols; j++ ) {
            out << a.m[ i ][ j ] << " ";
        }
        out << "\n";
    }
    out << "\n";
    return out;
}