#ifndef factory_h
#define factory_h

#include <memory>

namespace design_patterns
{

class Task;
class TaskFactory
{
  public:
  static std::unique_ptr<Task> create(std::string const& name);
};

class Task
{
  public:
  Task(std::string const& name = "");
  virtual ~Task();
  virtual void execute() = 0;

  protected:
  std::string mName;
};

class CopyFile : public Task
{
  public:
  CopyFile();
  ~CopyFile();
  virtual void execute();
};

class CheckExists : public Task
{
  public:
  CheckExists();
  ~CheckExists();
  virtual void execute();
};

class NullTask : public Task
{
  public:
  NullTask();
  ~NullTask();
  virtual void execute();
};
}

#endif
