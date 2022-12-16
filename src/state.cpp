#include <state.hpp>

namespace dynamo {
    
vector::vector(float a, float b) : x{a}, y{b} { }

vector vector::operator + (const vector& o) const {
    return { x + o.x, y + o.y };
}

vector vector::operator * (float k) const {
    return { x * k, y * k };
}

vector vector::operator / (float k) const {
    return { x / k, y / k };
}

} // namespace dynamo
