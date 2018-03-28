#include <observer.hpp>

#include <iostream>

using namespace design_patterns;

int main()
{

  // I simulate the loop of a PID controller.
  // The topics are: (1) set-point, SP(t), sent to achieve a target, (2) process-value, PV(t) coming out of the actuator activated by the PID. Together these two topics make the error, e(t) = SP(t) - PV(t) used by each PID component to draw the next output u(t+1). This output will be converted by the actuator into the next PV(t+1). And so on ...
  // the observers are: (1) Proportional, (2) Integral, (3) Derivative parts of the controller PID

  // create observers
  std::cout << "----- wake up observers -----" << std::endl;
  std::shared_ptr<Observer> p(new Observer("PID-P"));
  std::shared_ptr<Observer> i(new Observer("PID-I"));
  std::shared_ptr<Observer> d(new Observer("PID-D"));

  // init topics and subscribe the observers
  std::cout << "----- init topics -----" << std::endl;

  Subject sp("Set-Point");
  sp.attach("PID-P", p);
  sp.attach("PID-I", i);
  sp.attach("PID-D", d);

  Subject pv("Proc-Value");
  pv.attach("PID-P", p);
  pv.attach("PID-I", i);
  pv.attach("PID-D", d);

  // first notification
  std::cout << "----- notification: first loop -----" << std::endl;
  sp.notify("3.50");
  pv.notify("1.00");

  // adjustments
  std::cout << "----- adjustment -----" << std::endl;
  sp.detach("PID-I");
  pv.detach("PID-I");

  // second notification
  std::cout << "----- notification: second loop -----" << std::endl;
  sp.notify("1.00");
  pv.notify("0.50");

  std::cout << "----- termination -----" << std::endl;

  return 0;
}
