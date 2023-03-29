# DLA

At this simulation, we try to create a code for DLA (Diffusion Limited Aggregation) problem in C. 
The first step is to generate a 2-dimensional square grid with leght L = 400. 
The second step is to create a circle with Radial R=200 and the center of the circle to be the same with the square. 
The simulation can be started when we place a particle on the circumference of the circle randomly. 
The paticle perfoms a random walk, which can be stopped when (a) the new particle occupies a position next to the central particle or (b) 
the new particle go far away from the original region (out off the grid). 
In the situation (a) the new particle attaches with original particle creating an aggregate of two particles. 
In the situation (b) the new particle repositioned on the new random point on the circumference of circle. 
The simulation stop when the aggregate of all particles touch the circumference of circle. 
After that when simulation continue we calculate the fractal dimension at matlab. 
The method that we used was to select a random region with shape square and side legth L = 10, and then we calculate the sum of positions that have been occupied M. 
Afterwards we repeat this procedure with the side of square to be increased by 10, but with same centre at every new square. 
Finally, the fractal diamention is the mean of 20 consecutive repetitions, that can calculated from the slope of the least squares line at the graph M(L) 