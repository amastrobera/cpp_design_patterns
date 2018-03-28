#ifndef composite_h
#define composite_h

#include <memory>
#include <vector>

namespace design_patterns
{

class Action 
{
public:
    Action(std::string const& name);
    virtual ~Action();
    virtual void execute() = 0;
    virtual void add(std::unique_ptr<Action> action);
protected:
    std::string mName, mType;
};


class Check : public Action
{
public:
    Check(std::string const& name);
    virtual ~Check();
    virtual void execute();
};

class Move : public Action
{
public:
    Move(std::string const& name);
    virtual ~Move();
    virtual void execute();
};



class CompositeAction : public Action
{
public:
    CompositeAction(std::string const& name);
    virtual ~CompositeAction();
    virtual void execute();    
    virtual void add(std::unique_ptr<Action> action);
protected:
    std::vector<std::unique_ptr<Action>> mChildren;
};


}

#endif
