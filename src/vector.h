#pragma once
#include <cstdint>

namespace ELL
{
    // Define a template class for vectors
    template<typename T>
    struct Vector
    {
        T x, y, z;

        Vector(T& x, T& y)
            :
            x{x},
            y{y}
        {
        }

        Vector(T& x, T& y, T& z)
            :
            x{x},
            y{y},
            z{z}
        {
        }

        void clear()
        {
            x = 0;
            y = 0;
        }
    };

    // Define aliases for specific vector types
    using Vec2i = Vector<int>;
    using Vec2f = Vector<float>;
    using Vec3i = Vector<int>;
    using Vec3f = Vector<float>;
}
