#### Singleton Pattern ###

A singleton is a class that can be constructed only once. Its instance, within a program, is shared across all all those which request it. 

In this example I have a base class `Singleton` which satisfies this requirement. Then, a derived class `Logger` uses this pattern and implements its own functions. Finally, I wanted the logger to be *thread safe*, so I applied a lock_guard. 


The main executes this code. Two threads use the same logger. Only once instance is created. Its usage is monitored by the lock.

```
void log_thread(std::string const& id)
{
  Logger* logger = Logger::instance();
  size_t num_logs = 3;
  while (num_logs--)
  {
    logger->info(id);
    std::this_thread::sleep_for(std::chrono::seconds(1));
  }
}
```

The result in execution is the following:

```
ubuntu: ~/development/c++/design_patterns/build
$ ./singleton/singleton 
created instance Singleton
[info] t1
[info] t2
[info] t2
[info] t1
[info] t2
[info] t1
destroyed instance Singleton

```


