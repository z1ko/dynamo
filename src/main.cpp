
#include <array>
#include <iostream>

#include <system.hpp>
#include <integrator.hpp>
#include <state.hpp>

int main(int argc, char **argv) {

  dynamo::systems::lotka_volterra lv(0.5f, 0.5f, 0.5f, 0.5f);
  dynamo::state state{ 3.0f, 3.0f };

  for (int i = 0; i < 10000; i++) {
    state = dynamo::integrators::rk4(lv, state);
    std::cout << state.x << ":" << state.y << std::endl;
  }

  return 0;
}
