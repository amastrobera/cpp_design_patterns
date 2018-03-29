#include <proxy.hpp>

#include <chrono>
#include <iostream>
#include <thread>

namespace design_patterns
{

void Router::request()
{
  std::cout << "Router request " << std::endl;
}

Router::Router()
{
  std::cout << "--- started router --- " << std::endl;
}

Router::~Router()
{
}

Proxy::Proxy(std::shared_ptr<Router> injected)
  : mpRouter(injected)
{
  std::cout << "--- started proxy --- " << std::endl;
}

Proxy::~Proxy()
{
}

bool Proxy::connected()
{
  if (auto observe = mpRouter.lock())
    return true;
  return false;
}

void Proxy::request()
{
  std::cout << "Proxy request " << std::endl;
  if (auto router = mpRouter.lock())
    router->request();
}
}
