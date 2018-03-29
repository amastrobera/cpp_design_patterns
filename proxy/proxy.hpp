#ifndef proxy_h
#define proxy_h

#include <memory>

namespace design_patterns
{

class Router
{
  public:
  Router();
  virtual void request();
  virtual ~Router();
};

class Proxy : public Router
{
  public:
  Proxy(std::shared_ptr<Router> injected);
  ~Proxy();
  virtual void request();
  bool connected();

  private:
  std::weak_ptr<Router> mpRouter;
};
}

#endif
