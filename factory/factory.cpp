#include <factory.hpp>

#include <iostream>

namespace design_patterns
{

std::unique_ptr<Task> TaskFactory::create(std::string const& name)
{
  if (name == "CopyFile")
    return std::unique_ptr<Task>(new CopyFile());
  else if (name == "CheckExists")
    return std::unique_ptr<Task>(new CheckExists());
  return std::unique_ptr<Task>(new NullTask());
}

Task::Task(std::string const& name)
  : mName(name)
{
}

Task::~Task()
{
}

CopyFile::CopyFile()
  : Task("CopyFile")
{
}

CopyFile::~CopyFile()
{
}

void CopyFile::execute()
{
  std::cout << "executing " << mName << std::endl;
}

CheckExists::CheckExists()
  : Task("CheckExists")
{
}

CheckExists::~CheckExists()
{
}

void CheckExists::execute()
{
  std::cout << "executing " << mName << std::endl;
}

NullTask::NullTask()
  : Task("NullTask")
{
}

NullTask::~NullTask()
{
}

void NullTask::execute()
{
  std::cout << "executing " << mName << std::endl;
}
}
