#include <observer.hpp>

#include <iostream>
#include <sstream>

namespace design_patterns
{

Observer::Observer(std::string const& name)
  : mName(name)
{
  std::cout << "activate: " << name << std::endl;
}

Observer::~Observer()
{
  std::cout << "deactivate: " << mName << std::endl;
}

void Observer::update(std::string const& msg)
{
  std::cout << mName << ": " << msg << std::endl;
}

Subject::Subject(std::string const& name)
  : mName(name)
{
  std::cout << "opening topic " << mName << std::endl;
}

Subject::~Subject()
{
  std::cout << "closing topic " << mName << std::endl;
}

void Subject::attach(std::string const& name, std::shared_ptr<Observer> obs)
{
  // inserts only if name doesn't exist. calls the constructor of weak_ptr
  mSubscribers.emplace(name, obs);
}

void Subject::detach(std::string const& name)
{
  std::cout << "topic " << mName << " detaches " << name << std::endl;
  auto it = mSubscribers.find(name);
  if (it != mSubscribers.end())
    mSubscribers.erase(it);
}

void Subject::notify(std::string const& msg)
{
  std::cout << "topic " << mName << " <" << msg << ">" << std::endl;

  std::ostringstream os;
  os << mName << " | " << msg;
  for (auto iter = mSubscribers.begin(); iter != mSubscribers.end();)
    if (auto shr_pt = iter->second.lock())
    {
      shr_pt->update(os.str());
      ++iter;
    }
    else
      //shared ptr has expired, remove it from the list
      mSubscribers.erase(iter++);
}
}
