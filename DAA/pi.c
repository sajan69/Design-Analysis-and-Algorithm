#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main() {
  int inside = 0;  // number of points inside the circle
  int total = 0;   // total number of points

  // Seed the random number generator
  srand(time(NULL));

  // Generate 10,000,000 points
  for (int i = 0; i < 10000000; i++) {
    // Generate a random point (x, y)
    double x = (double)rand() / RAND_MAX;
    double y = (double)rand() / RAND_MAX;

    // If the point is inside the circle, increment inside
    if (x * x + y * y <= 1) {
      inside++;
    }

    // Increment total
    total++;
  }

  // Calculate pi from the points inside and outside the circle
  double pi = 4.0 * inside / total;

  // Print the result
  printf("Approximation of pi: %f\n", pi);

  return 0;
}
