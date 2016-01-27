#pragma once

template< typename _type_ >
inline void SwapValues ( _type_ & a, _type_ & b ) {
    _type_ * t = a;
    a = b;
    b = t;
}