#include <composite.hpp>

#include <iostream>

namespace design_patterns
{

Action::Action(std::string const& name)
  : mName(name)
  , mType("Action")
{
}

Action::~Action()
{
}

void Action::add(std::unique_ptr<Action> action)
{
  //do nothing, by default
}

Check::Check(std::string const& name)
  : Action(name)
{
  this->mType = "Check";
}

Check::~Check()
{
}

void Check::execute()
{
  std::cout << "execute CHECK " << mName << std::endl;
}

Move::Move(std::string const& name)
  : Action(name)
{
  this->mType = "Move";
}

Move::~Move()
{
}

void Move::execute()
{
  std::cout << "execute MOVE " << mName << std::endl;
}

CompositeAction::CompositeAction(std::string const& name)
  : Action(name)
{
  this->mType = "CompositeAction";
}

CompositeAction::~CompositeAction()
{
}

void CompositeAction::add(std::unique_ptr<Action> action)
{
  mChildren.push_back(std::move(action));
}

void CompositeAction::execute()
{
  std::cout << "executing COMPOSITE " << mName << std::endl;
  for (size_t i = 0; i < mChildren.size(); ++i)
    mChildren[i]->execute();
}
}
