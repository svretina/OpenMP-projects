# OpenMP-projects
Some simple C codes that I wrote for the course OpenMP

Eliptic_ode.c 
Implementation of the Liebmann method for solving the eliptic differential equation

![first equation](https://latex.codecogs.com/gif.latex?%5Cinline%20%5Cdpi%7B120%7D%20%5Clarge%20%24%20u_%7Bxx%7D%20&plus;%20u_%7Byy%7D%20%3D%2010.0%20e%5E%7B-0.5%20%5Csqrt%7B%28x-0.5%29%5E2&plus;%28y-0.5%29%5E2%7D%7D%24)
with initial conditions
![cond](https://latex.codecogs.com/gif.latex?%5Cinline%20%5Cdpi%7B120%7D%20%5Clarge%20%24%20u%28x%2Cy%29%3D1.0%20%24) at any boundary

wave.c 

Implementation of the Lax-Wendroff scheme to solve the wave equation 

![seconde equation](https://latex.codecogs.com/gif.latex?%5Cinline%20%5Cdpi%7B120%7D%20%5Clarge%20%24%20u_%7Btt%7D-%5Calpha%5E2%20u_%7Bxx%7D%3D0%24)

with parameters
![parameter](https://latex.codecogs.com/gif.latex?%5Cinline%20%5Cdpi%7B120%7D%20%5Clarge%20%24%20%5Calpha%5E2%20%3D%202/%5Cpi%5E2%20%24) in the range ![range](https://latex.codecogs.com/gif.latex?%5Cinline%20%5Cdpi%7B120%7D%20%5Clarge%20%24%200%20%5Cleq%20x%20%5Cleq%2012%20%24)
for initial conditions  ![init cond](https://latex.codecogs.com/gif.latex?%5Cinline%20%5Cdpi%7B120%7D%20%5Clarge%20%24u%28x%2C0%29%20%3D%20sin%28%5Cpi%20x%29%20%5Cquad%20for%20%5Cquad%200%20%5Cleq%20x%20%5Cleq%204%20%24)
and ![2nd init cond](https://latex.codecogs.com/gif.latex?%5Cinline%20%5Cdpi%7B120%7D%20%5Clarge%20%24%20u%28x%2C0%29%20%3D%200%20%5Cquad%20for%20%5Cquad%200%20%5Cleq%20x%20%5Cleq%202%20%5Cquad%20and%20%5Cquad%204%20%5Cleq%20x%20%5Cleq%2012%20%24)
