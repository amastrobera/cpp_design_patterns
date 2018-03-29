#ifndef singleton_h
#define singleton_h

#include <memory>
#include <mutex>

namespace design_patterns
{

class Singleton
{
  public:
  static Singleton* instance();

  Singleton(Singleton const& cp) = delete;
  Singleton& operator=(Singleton const& cp) = delete;

  friend std::unique_ptr<Singleton>::deleter_type; // call private costructor!

  private:
  Singleton(); //= default
  virtual ~Singleton(); // = default

  static std::mutex mMutex;
  static std::unique_ptr<Singleton> mInstance;
};

class Logger : public Singleton
{
  public:
  // The function "static Singleton* instance()" is inherited, and because it
  // is static, it cannot be overridden. The way to go is dynamic_cast
  // the base class return value to receive a Logger* instead of a Singleton*
  // so I created the following convenience function
  static Logger* instance();

  void info(std::string const& msg);
  void error(std::string const& msg);
  // etc ...

  Logger(Logger const& cp) = delete;
  Logger& operator=(Logger const& cp) = delete;

  private:
  Logger() = default;
  ~Logger() = default;

  void printMsg(std::string const& msg);
  static std::mutex mMutex;
};
}

#endif
