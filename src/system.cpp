#include <system.hpp>

namespace dynamo::systems {
    
lotka_volterra::lotka_volterra(float alpha, float beta, float gamma, float yota) 
: alpha{alpha}, beta{beta}, gamma{gamma}, yota{yota} {}

vector lotka_volterra::df(const state &s) const {
    return { s.x * (alpha - beta * s.y), s.y * (gamma * s.x - yota) };
};

} // namespace dynamo::system 
