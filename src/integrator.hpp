#pragma once
#include <state.hpp>
#include <system.hpp>

/// Integrators already implemented
namespace dynamo::integrators {

/// forward Euler
/// x_k+1 = x_k + dt * k1 
state forward_euler(const dynamical_system_2D &dyn, const state &s, float dt = 0.01);

/// Runga-Kutta 2th order
/// x_k+1 = x_k + dt * k2
state rk2(const dynamical_system_2D &dyn, const state &s, float dt = 0.01);

/// Runga-Kutta 4th order
/// x_k+1 = x_k + dt/6 * (k1 + 2k2 + 2k3 * k1)
state rk4(const dynamical_system_2D &dyn, const state &s, float dt = 0.01);

} // namespace dynamo::integrators
