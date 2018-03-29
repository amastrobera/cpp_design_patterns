#include <proxy.hpp>

#include <iostream>

using namespace design_patterns;

int main()
{
  std::shared_ptr<Router> router(new Router());
  Proxy proxy(router);
  std::cout << "<Router " 
            << (proxy.connected() ? "online" : "offline") 
            << ">" << std::endl;
  proxy.request();

  return 0;
}
