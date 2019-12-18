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



Note:
When running the Python script indicating the number of philosophers is necessary for the correct result.

<img src="/Images/dining_phil.png"></img>


For this test video I ran with the number of threads [# of philosophers] at 5 and number of iterations at 50. 
[<img src="/Images/dining_phil_vid.PNG"></img>](https://drive.google.com/open?id=1uP293kCbHgWahYEtaQsTWEm0xdZpCH_E)

For the test video I ran with the number of threads [# of philosophers] at 5 and number of iterations at 9000. 
[<img src="/Images/dining_phil_vid.PNG"></img>](https://drive.google.com/open?id=1dsveiNZWrVs7J4_WzXyOPGAMzD7HBMIf)
