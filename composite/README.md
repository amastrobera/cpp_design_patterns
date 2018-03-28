#### Composite Pattern ###

This is a simulation of a behaviourial tree. Each node is an action. An action can be Composite or actual (like "Move", or "Check" conditions). The `main()` follows this strutural logic.

                 task_reach_target
                    /          \ 
      if_battery_charged      go_to_target
                               /        \
                      if_target_onsight  move_fwd_to_target



Which is reflected in the execution. 


    ubuntu: ~/development/c++/design_patterns
    $ ./build/composite/composite 
    executing COMPOSITE task_reach_target
    execute CHECK if_battery_charged
    executing COMPOSITE go_to_target
    execute CHECK if_target_onsight
    execute MOVE move_fwd_to_target


