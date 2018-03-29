#include <singleton.hpp>

#include <iostream>

namespace design_patterns
{

// we need to have an explicit implementation of these static variables
std::mutex Singleton::mMutex;
std::unique_ptr<Singleton> Singleton::mInstance;

Singleton* Singleton::instance()
{
  std::lock_guard<std::mutex> lock(mMutex);
  if (!mInstance)
    mInstance.reset(new Singleton());
  return mInstance.get();
}

Singleton::Singleton()
{
  std::cout << "created instance Singleton" << std::endl;
}

Singleton::~Singleton()
{
  std::cout << "destroyed instance Singleton" << std::endl;
}

// we need to have an explicit implementation of these static variables
std::mutex Logger::mMutex;

Logger* Logger::instance()
{
  return dynamic_cast<Logger*>(Singleton::instance());
}

void Logger::info(std::string const& msg)
{
  std::lock_guard<std::mutex> lock(mMutex);
  printMsg("[info] " + msg);
}

void Logger::error(std::string const& msg)
{
  std::lock_guard<std::mutex> lock(mMutex);
  printMsg("[error] " + msg);
}

void Logger::printMsg(std::string const& msg)
{
  std::cout << msg << std::endl;
}
}
