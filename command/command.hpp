#ifndef command_h
#define command_h

#include <exception>
#include <map>
#include <sstream>

namespace design_patterns
{

class Joint
{
  public:
  enum Mode
  {
    degrees,
    meters
  };

  Joint(std::string const& name = "", Mode mode = degrees);
  std::string name();
  void move(double pos, double speed);

  private:
  std::string mName;
  Mode mMode;
};

// Personal note: variadic functions cannot be inherited. it sucks.
// Therefore I must create a class that packs and unpacks its self

class ArgPack
{
  public:
  template <typename T>
  void set(std::string const& name, T val)
  {
    std::ostringstream os;
    os << val;
    mPack.emplace(name, os.str());
  }

  // to use before get<T>, which will throw
  bool has(std::string const& name) const;

  template <typename T>
  T get(std::string const& name) const throw(std::out_of_range)
  {
    std::string val = mPack.at(name);
    std::istringstream is(val);
    T retVal;
    is >> retVal;
    return retVal;
  }

  private:
  std::map<std::string, std::string> mPack;
};

class Command
{
  public:
  Command(std::string const& type, std::string const& name = "");
  virtual ~Command();
  virtual void execute(ArgPack const& pack) = 0;

  protected:
  std::string mType;
  std::string mName;
};

class Actuator : public Command
{
  public:
  Actuator(Joint* pJoint, std::string const& name = "");
  ~Actuator();
  virtual void execute(ArgPack const& pack);

  private:
  Joint* mpJoint;
};
}

#endif
