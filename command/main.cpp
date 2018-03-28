#include <iostream>

#include <command.hpp>
#include <memory>

using namespace design_patterns;

int main()
{
  std::shared_ptr<Joint> elbow(new Joint("Elbow", Joint::degrees)); // receiver

  std::unique_ptr<Command> actuator(new Actuator(elbow.get(), "Elb_Act"));

  ArgPack pack;
  pack.set("position", 30);
  pack.set("speed", 10);

  actuator->execute(pack); // reach position 30°, with speed 1 deg/S

  return 0;
}
