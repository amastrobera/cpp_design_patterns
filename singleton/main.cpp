#include <singleton.hpp>

#include <chrono>
#include <iostream>
#include <thread>

using namespace design_patterns;

void log_thread(std::string const& id)
{
  // Singleton* logger = Logger::instance() can also be used but it's useless
  // here anyway. let's stick to the logger static function

  Logger* logger = Logger::instance();

  size_t num_logs = 3;
  while (num_logs--)
  {
    logger->info(id);
    std::this_thread::sleep_for(std::chrono::seconds(1));
  }
}

int main()
{

  std::thread t1(log_thread, "t1");
  std::thread t2(log_thread, "t2");

  t1.join();
  t2.join();

  return 0;
}
