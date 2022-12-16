#pragma once
#include <state.hpp>

namespace dynamo {
    
class dynamical_system_2D {
public:
  // Implements the system dynamics
  virtual vector df(const state &s) const = 0;
};

/// Systems already implemented
namespace systems {
  
class lotka_volterra : public dynamical_system_2D {

  const float alpha; // Prey reproduction rate
  const float beta;  // Rate at which prey descrease due to the predator
  const float gamma; // Predator reproduction rate
  const float yota;  // Predator death rate

public:
  lotka_volterra(float alpha, float beta, float gamma, float yota);

  // x_dot = x * (alpha - beta * y)
  // y_dot = y * (gamma * x - yota)
  vector df(const state &s) const override;
};

} // namespace systems
} // namespace dynamo

