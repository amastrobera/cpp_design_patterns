#ifndef factory_h
#define factory_h

#include <map>
#include <memory>

namespace design_patterns
{

class Subject;
class Observer
{
  public:
  Observer(std::string const& name);
  ~Observer();
  void update(std::string const& msg);

  private:
  std::string mName;
};

class Subject
{
  public:
  Subject(std::string const& name);
  ~Subject();
  void attach(std::string const& name, std::shared_ptr<Observer> obs);
  void detach(std::string const& name);
  void notify(std::string const& msg);

  private:
  std::string mName;
  std::map<std::string, std::weak_ptr<Observer> > mSubscribers;
};
}

#endif
