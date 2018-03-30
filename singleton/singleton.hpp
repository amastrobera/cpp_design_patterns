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

  friend std::unique_ptr<Singleton>::deleter_type; // call private destructor!

  private:
  Singleton(); // can be called from within "Singleton::instance()"
  virtual ~Singleton(); // can't be called by ~Logger()
						// can be called by "friend unique_ptr::deleter"

  static std::mutex mMutex; // needs first instance 
  static std::unique_ptr<Singleton> mInstance; // same 
};

class Logger : public Singleton
{
  public:
  // "static Singleton::instance()" is inherited, and because it
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
  // Logger is never destroyed or constructed because we use Logger::instance()
  // that returns a dynamic_cast of Singleton::instance (constructed/destructed) 
  // and then all the important bits of the Logger* are static memebers or 
  // public member functions, which are both accessible.
  // Do I lose memory with the extra symbols of dynamic_cast(Logger*) ?!
  Logger() = default;
  ~Logger() = default;

  void printMsg(std::string const& msg);
  static std::mutex mMutex; // needs a first instance 
};
}

#endif
