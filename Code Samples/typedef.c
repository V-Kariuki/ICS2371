#include <stdio.h>
#include <math.h>

// Define a struct representing a point in 2D space
typedef struct Point{
    int x;
    int y;
}Point;

// Function to display the coordinates of a point
void displayPoint(struct Point p) {
    printf("Point coordinates: (%d, %d)\n", p.x, p.y);
}

// Function to calculate the distance between two points
double distance(struct Point p3, struct Point p4) {
    int dx = p3.x - p4.x;
    int dy = p4.y - p4.y;
    return sqrt(dx*dx + dy*dy);
}

int main() {
    // Declare and initialize struct variables
    Point p1 = {2, 3};
    Point p2 = {5, 7};
    Point p3 = {8,10};
    Point p4 = {12,14};

    // Display the coordinates of points
    printf("Coordinates of p1:\n");
    displayPoint(p3);
    printf("Coordinates of p2:\n");
    displayPoint(p4);

    // Calculate and display the distance between points
    double dist = distance(p3, p4);
    printf("Distance between p1 and p2: %.2f\n", dist);

    return 0;
}
