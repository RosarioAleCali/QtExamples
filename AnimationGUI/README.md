# Animations
Animations is a small program where I play around with the Qt Animation properites.

In this program I created 6 push buttons grouped into two rows with three buttons each.
Then I set up a **QPropertyAnimation** for each push button.
All the animations have a duration of 3000 milliseconds and different start/end values. </br>
After that, I created a **QEasingCurve** of type **OutBounce** and added all 6 animations to it. </br>
Then, I create two groups (one for each row) of type **QParallelAnimationGroup** and I finished by adding a
**QSequentialAnimationGroup** so that the animations of the first row start first.
