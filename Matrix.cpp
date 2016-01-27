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

matrix * matrix::operator + ( const matrix & o ) const {

    assert( rows == o.rows || cols == o.cols );
    matrix * newM = new matrix( rows, cols );

    for( int i = 0; i < rows; i++ ) {
        for( int j = 0; j < cols; j++ ) {
            newM->m[ i ][ j ] = m[ i ][ j ] + o.m[ i ][ j ];
        }
    }

    return newM;
}

matrix * matrix::operator - ( const matrix & o ) const {
    assert( rows == o.rows || cols == o.cols );
    matrix * newM = new matrix( rows, cols );

    for( int i = 0; i < rows; i++ ) {
        for( int j = 0; j < cols; j++ ) {
            newM->m[ i ][ j ] = m[ i ][ j ] - o.m[ i ][ j ];
        }
    }

    return newM;
}

matrix * matrix::operator * ( const matrix & o ) const {
    assert( cols == o.rows );
    matrix * newM = new matrix( rows, cols );

    for( int i = 0; i < rows; i++ ) {
        for( int j = 0; j < cols; j++ ) {
            for( int k = 0; k < cols; k++ ) {
                newM->m[ i ][ j ] += m[ i ][ k ] * o.m[ k ][ j ];
            }
        }
    }

    return newM;
}

matrix * matrix::operator * ( const float a ) const {
    matrix * newM = new matrix( rows, cols );

    for( int i = 0; i < rows; i++ ) {
        for( int j = 0; j < cols; j++ ) {
            m[i][j] *= a;
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

void matrix::MakeIdentity() {
    
    assert(rows == cols);
    
    if( m == nullptr ) {
        m = Create();
    }
    
    // for( int i = 0; i < rows; i++ ) {
    //     for( int j = 0; j < cols; j++ ) {
    //         if( i != j ) {
    //             m[i][j] = 0.0f;
    //         } else {
    //             m[i][j] = 1.0f;
    //         }
    //     }
    // }
    
    std::memset(m, 0, rows * cols * sizeof( float ) );
    
    for( int i = 0; i < rows; i++ ) {
        m[i][i] = 1.0f;
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


float** matrix::Create() {
    m = new float*[ rows ];

    for( int i = 0; i < cols; i++ ) {
        m[ i ] = new float[ cols ];
    }
    
    return m;
}