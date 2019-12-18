# Dining Philosopher Problem
Dining Philosopher Problem (Semaphore and Multithreading)

The Dining Philosopher Problem states that K philosophers seated around a circular 
table with one chopstick between each pair of philosophers. 
There is one chopstick between each philosopher. 
A philosopher may eat if he can pickup the two chopsticks adjacent to him. 
One chopstick may be picked up by any one of its adjacent followers but not both.

In my solution I used Multithreading in C with semaphores. 
I also created a checking program in Python to verify that no 2 adjacent philosophers are 
EATING at the same time.

For the test video I ran with the number of threads [# of philosophers] at 5
and number of iterations at 9000. 

Note:
When running the Python script indicating the number of philosopher is necessary for the correct result.

<img src="/Images/dining_phil.png"></img>
<img src="/Images/chopstick_2.PNG"></img>
<img src="/Images/chopstick_3.PNG"></img>
