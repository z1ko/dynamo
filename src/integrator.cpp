#include <integrator.hpp>

namespace dynamo::integrators {
    
state forward_euler(const dynamical_system_2D &dyn, const state &s, float dt) {
    return s + dyn.df(s) * dt;
}

state rk2(const dynamical_system_2D &dyn, const state &s, float dt) {

    vector k1 = dyn.df(s);
    vector k2 = dyn.df(s + k1 * dt * 0.5f);

    return s + k2 * dt;
}

state rk4(const dynamical_system_2D &dyn, const state &s, float dt) {

    vector k1 = dyn.df(s);
    vector k2 = dyn.df(s + k1 * dt * 0.5f);
    vector k3 = dyn.df(s + k2 * dt * 0.5f);
    vector k4 = dyn.df(s + k3 * dt);

    return s + (k1 + k2 * 2.f + k3 * 2.f + k4) * dt / 6.f; 
}

} // namespace dynamo::integrators
