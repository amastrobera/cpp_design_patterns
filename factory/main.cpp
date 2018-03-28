#include <iostream>

#include <factory.hpp>

using namespace design_patterns;

int main()
{

  std::unique_ptr<Task> check = TaskFactory::create("CheckExists");
  std::unique_ptr<Task> copy = TaskFactory::create("CopyFile");
  std::unique_ptr<Task> other = TaskFactory::create("blabla");

  check->execute();
  copy->execute();
  other->execute();

  return 0;
}
