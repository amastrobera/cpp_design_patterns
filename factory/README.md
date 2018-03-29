#### Factory Pattern ###

A task factory abstract class returns the appropriate concrete task to achieve, according to a run-time request. Two ways of doing it: 

* Two classes. `Task` to inherit from, and `TaskFactory` to call the `createTask("name")` function

       client: execute "task_name"  -->  TaskFactory::create("task_name")

* Only one class, `Task` used as base class, and with a *static* function `create("name")`.

       client: execute "task_name" --> Task::create("task_name")

Which is reflected in the execution. 

    ubuntu: ~/development/c++/design_patterns/build
    $ ./factory/factory 
    executing CheckExists
    executing CopyFile
    executing NullTask



