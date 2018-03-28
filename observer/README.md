#### Observer Pattern ###

I simulate the loop of a PID controller.

* The topics are:
    1. set-point, `SP(t)`, sent to achieve a target 
    2. process-value, `PV(t)` coming out of the actuator activated by the PID.

    Together these two topics make the error, `e(t) = SP(t) - PV(t)` used by each PID component to draw the next output `u(t+1)`. This output will be converted by the actuator into the next `PV(t+1)`.  And so, the loops moves forward again ...

* The observers are the components of the PID controller
    1. Proportional
    2. Integral
    3. Derivative


Which is reflected in the execution. 

	ubuntu: ~/development/c++/design_patterns/build
	$ ./observer/observer 
	----- wake up observers -----
	activate: PID-P
	activate: PID-I
	activate: PID-D
	----- init topics -----
	opening topic Set-Point
	opening topic Proc-Value
	----- notification: first loop -----
	topic Set-Point <3.50>
	PID-D: Set-Point | 3.50
	PID-I: Set-Point | 3.50
	PID-P: Set-Point | 3.50
	topic Proc-Value <1.00>
	PID-D: Proc-Value | 1.00
	PID-I: Proc-Value | 1.00
	PID-P: Proc-Value | 1.00
	----- adjustment -----
	topic Set-Point detaches PID-I
	topic Proc-Value detaches PID-I
	----- notification: second loop -----
	topic Set-Point <1.00>
	PID-D: Set-Point | 1.00
	PID-P: Set-Point | 1.00
	topic Proc-Value <0.50>
	PID-D: Proc-Value | 0.50
	PID-P: Proc-Value | 0.50
	----- termination -----
	closing topic Proc-Value
	closing topic Set-Point
	deactivate: PID-D
	deactivate: PID-I
	deactivate: PID-P


