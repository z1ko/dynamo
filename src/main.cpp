
#include <array>
#include <iostream>

namespace dynamo {

using vec2 = std::array<float, 2>;

vec2 vec2_mul(vec2 a, float b) { return {a[0] * b, a[1] * b}; }
vec2 vec2_add(vec2 a, vec2 b) { return {a[0] + b[0], a[1] + b[1]}; }

class dynamical_system {
public:
  // Implements the system dynamics
  virtual vec2 df(const vec2 &state) const = 0;
};

namespace systems {

class lotka_volterra : public dynamical_system {

  // Parameters
  const float a, b, c, d;

public:
  lotka_volterra(float a, float b, float c, float d) : a{a}, b{b}, c{c}, d{d} {}

  vec2 df(const vec2 &state) const override {
    return {state[0] * (a - b * state[1]), state[1] * (c * state[0] - d)};
  };
};

} // namespace systems

class integrator {
protected:
  const float deltatime = 0.01;

public:
  // Return the next step in the simulation of the dynamical system
  virtual vec2 integrate(const dynamical_system &dyn,
                         const vec2 &state) const = 0;
};

/*
using dynamical_system_1 = dynamical_system<float>;
using dynamical_system_2 = dynamical_system<float, float>;
using dynamical_system_3 = dynamical_system<float, float, float>;
*/

namespace integrators {

class forward_euler : public integrator {
public:
  vec2 integrate(const dynamical_system &dyn,
                 const vec2 &state) const override {
    const auto &df = dyn.df(state);
    return vec2_add(state, vec2_mul(df, deltatime));
  }
};

class RK4 : public integrator {
public:
  vec2 integrate(const dynamical_system &dyn,
                 const vec2 &state) const override {

    vec2 k1 = dyn.df(state);
    vec2 k2 = dyn.df(vec2_add(state, vec2_mul(k1, deltatime * 0.5f)));
    vec2 k3 = dyn.df(vec2_add(state, vec2_mul(k2, deltatime * 0.5f)));
    vec2 k4 = dyn.df(vec2_add(state, vec2_mul(k3, deltatime)));

    // x_k+1 = x_k + dt/6 * (k1 + 2k2 + 2k3 * k1)
    return vec2_add(state, vec2_mul(vec2_add(vec2_add(k1, vec2_mul(k2, 2)),
                                             vec2_add(vec2_mul(k3, 2), k4)),
                                    deltatime / 6.f));
  }
};

class RK2 : public integrator {
public:
  vec2 integrate(const dynamical_system &dyn,
                 const vec2 &state) const override {

    vec2 k1 = dyn.df(state);
    vec2 k2 = dyn.df(vec2_add(state, vec2_mul(k1, deltatime * 0.5f)));
    return vec2_add(state, vec2_mul(k2, deltatime));
  }
};

} // namespace integrators

} // namespace dynamo

int main(int argc, char **argv) {

  dynamo::integrators::RK4 integrator{};
  dynamo::systems::lotka_volterra lv(0.5f, 0.5f, 0.5f, 0.5f);
  dynamo::vec2 state = {3.0f, 3.0f};

  for (int i = 0; i < 10000; i++) {
    state = integrator.integrate(lv, state);
    std::cout << state[0] << ":" << state[1] << std::endl;
  }

  return 0;
}
