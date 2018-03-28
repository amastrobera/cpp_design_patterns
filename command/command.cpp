#include <command.hpp>

#include <iostream>

namespace design_patterns
{

Joint::Joint(std::string const& name, Mode mode)
  : mName(name)
  , mMode(mode)
{
  std::cout << "--- using joint '" << mName << "' in "
            << (mMode == degrees ? "degrees" : "meters")
            << " mode" << std::endl;
}

std::string Joint::name()
{
  return mName;
}

void Joint::move(double pos, double speed)
{
  std::cout << "> Joint '" << mName << "' move to pos: "
            << pos << " with speed: " << speed << std::endl;
}

bool ArgPack::has(std::string const& name) const
{
  return mPack.count(name) > 0;
}

Command::Command(std::string const& type, std::string const& name)
  : mType(type)
  , mName(name)
{
}

Command::~Command()
{
}

Actuator::Actuator(Joint* pJoint, std::string const& name)
  : Command("Actuator", name)
  , mpJoint(pJoint)
{
  std::cout << "--- activated " << mType << " " << mName
            << " on joint '" << mpJoint->name() << "'" << std::endl;
}

Actuator::~Actuator()
{
  std::cout << "--- deactivated " << mType << " " << mName << std::endl;
}

void Actuator::execute(ArgPack const& pack)
{
  if (!pack.has("position") || !pack.has("speed"))
    return;

  double pos = pack.get<double>("position");
  double speed = pack.get<double>("speed");
  std::cout << "> Actuator.execute(" << pos << ", " << speed << ")" << std::endl;
  mpJoint->move(pos, speed);
}
}
