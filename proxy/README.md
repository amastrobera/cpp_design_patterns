#### Proxy Pattern ###

This is simple and useful. Once class Client wants to send a request to a Router, but it is far or it cannot access it directly. So it creates a Proxy to do it. 

Application (1): Middle men. *You know, between Bob and Alice, there is Mallory ...* 

Application (2): Stub class for testing. White collar ~~programmers~~ love it. 

In the client's `main.cpp` a Proxy is created and the request is made

```
Proxy proxy(router);
proxy.request();
```

Which is reflected in the execution. 

```
ubuntu: ~/development/c++/design_patterns/build
$ ./proxy/proxy 
--- started router --- 
--- started proxy --- 
<Router online>
Proxy request 
Router request
```


