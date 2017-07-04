# StateAnimations
StateAnimations is a small program where I play around with **Qt State Machines** to do some transitions 
and change some text to labels. </br>
The first thing I do is I create two push buttons (One on the center and the other one on the top-left corner) and a label (on the top-right corner). </br>
The button at the center will have an **QPropertyAnimation** of type **OutBounce**.
Then, I declare a **QStateMachine** and two **QState** objects attached to it.</br>
The two QState objects will take care of changing the text of the QLabel as well as changing
the dimensions of the push button at the center.</br>
Two **QEventTransition** objects will be created and attached to the top-left button and they
will be triggered on a **QEvent::MouseButtonPress** mouse event.
In the end, I add the QState objects to the machine and I start the machine.
