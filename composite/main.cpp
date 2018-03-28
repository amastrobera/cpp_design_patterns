#include <iostream>

#include <composite.hpp>

using namespace design_patterns;

int main()
{

  // behaviourial tree: each task is a Action or a Composite Pattern
  //
  //                 task_reach_target
  //                    /          \ 
    //      if_battery_charged      go_to_target
  //                               /        \
    //                      if_target_onsight  move_fwd_to_target

  std::unique_ptr<Action> root(new CompositeAction("task_reach_target"));

  std::unique_ptr<Action> left(new Check("if_battery_charged"));
  std::unique_ptr<Action> right(new CompositeAction("go_to_target"));

  std::unique_ptr<Action> child_left(new Check("if_target_onsight"));
  std::unique_ptr<Action> child_right(new Move("move_fwd_to_target"));

  right->add(std::move(child_left));
  right->add(std::move(child_right));

  root->add(std::move(left));
  root->add(std::move(right));

  root->execute();

  return 0;
}
