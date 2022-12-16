#pragma once

#include <array>

namespace dynamo {
    
struct vector {

    float x, y;

    vector(float a, float b);
    vector operator + (const vector& o) const;
    vector operator * (float k) const;
    vector operator / (float k) const;
};

using state = vector;

} // namespace dynamo