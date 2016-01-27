#pragma once

template< class _type_, int numElements > 
class Array {
public:

    // return number of elements in List
	int			        Num() const { return numElements; }

    // return the number of bytes that the array takes up
	int			        ByteSize() const { return sizeof( ptr ); }

    // memset the entire array with zero
    void                Zero () { memset ( ptr, 0, sizeof ( ptr ) ); }

    // memset the entire array with a specific value
    void                Memset ( const char fill ) { memset ( ptr, fill, numElements * sizeof ( *ptr ) ); }

    // array operators
    const _type_ &      operator[] ( int index ) const { assert ( (unsigned) index < (unsigned) numElements ); return ptr[ index ]; }

    _type_ *            operator[] ( int index ) { assert ( (unsigned) index < (unsigned) numElements ); return ptr[ index ]; }

    // returns a pointer to the list
    const _type_ *      Ptr () const { return ptr; }

    _type_ *            Ptr () { return ptr; }

private:
    _type_              ptr[ numElements ];

};
