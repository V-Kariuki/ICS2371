#include <stdio.h>

// Define a struct representing a point in 2D space
struct Point {
    int x;
    int y;
};

// Function to display the coordinates of a point
void displayPoint(struct Point p) {
    printf("Point coordinates: (%d, %d)\n", p.x, p.y);
}

// Function to calculate the distance between two points
double distance(struct Point p1, struct Point p2) {
    int dx = p2.x - p1.x;
    int dy = p2.y - p1.y;
    return sqrt(dx*dx + dy*dy);
}

int main() {
    // Declare and initialize struct variables
    struct Point p1 = {2, 3};
    struct Point p2 = {5, 7};

    // Display the coordinates of points
    printf("Coordinates of p1:\n");
    displayPoint(p1);
    printf("Coordinates of p2:\n");
    displayPoint(p2);

    // Calculate and display the distance between points
    double dist = distance(p1, p2);
    printf("Distance between p1 and p2: %.2f\n", dist);

    return 0;
}
