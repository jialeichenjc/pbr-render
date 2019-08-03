#if defined(_MSC_VER)
#define NOMINMAX
#pragma once 
#endif

#ifndef PBRT_CORE_GEOMETRY_H
#define PBRT_CORE_GEOMETRY_H

#include "pbrt.h"
#include "stringprint.h"
#include <iterator>

namespace pbrt {

template <typename T> 
inline bool isNaN(const T x) {
    return std::isnan(x);
}

template <> 
inline bool isNaN(const int x) {
    return false;
}

// Vector declarations
template <typename T>
class Vector2 {
public:
    Vector2() { x = y = 0; }
    Vector2(T xx, T yy) : x(xx), y(yy) { DCHECK(!HasNaNs()); }
    bool HasNaNs() const { return isNaN(x) || isNaN(y); }
    Vector2(const Vector2<T> &v) {
        DCHECK(!v.HasNaNs());
    }
};

} // namespace pbrt

#endif //PBRT_CORE_GEOMETRY_H