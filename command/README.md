#### Command Pattern ###

In *abstract* terms, Invoker calls interface Command. 

In *concrete* terms, a Client is linked to a Receiver. The Receiver is the platform on which the command is run, and receives the consequences of the its action. 


In the example, the Receiver is a **Joint**, which is told to reach a position of `degrees` [0,180] with a given `speed` [deg/s]. The Joint can be initialized in *degree mode* or *meter mode* according to what type of joint it is (rotating or translating). The Command is an **Actuator**. 


As reflected in the execution:

    ubuntu: ~/development/c++/design_patterns/build
    $ ./command/command 
    --- using joint 'Elbow' in degrees mode
    --- activated Actuator Elb_Act on joint 'Elbow'
    exception: no arg 'ciao' 
    > Actuator.execute(30, 10)
    > Joint 'Elbow' move to pos: 30 with speed: 10
    --- deactivated Actuator Elb_Act

