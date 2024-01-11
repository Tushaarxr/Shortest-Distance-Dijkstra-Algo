#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Structure to represent a point with x and y coordinates
typedef struct Point {
    double x;
    double y;
} Point;

// Function to calculate the Euclidean distance between two points
double calculateDistance(Point p1, Point p2) {
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

// Function to find the minimum distance in the set of vertices not yet included in the shortest path tree
int minDistance(double dist[], int visited[], int n) {
    double min = INFINITY;
    int min_index;

    for (int v = 0; v < n; v++) {
        if (!visited[v] && dist[v] < min) {
            min = dist[v];
            min_index = v;
        }
    }

    return min_index;
}

// Function to implement Dijkstra's algorithm to find the shortest path
void dijkstra(Point points[], int n, int start, int end) {
    double dist[n];
    int visited[n];

    for (int i = 0; i < n; i++) {
        dist[i] = INFINITY;
        visited[i] = 0;
    }

    dist[start] = 0;

    for (int count = 0; count < n - 1; count++) {
        int u = minDistance(dist, visited, n);
        visited[u] = 1;

        for (int v = 0; v < n; v++) {
            if (!visited[v] && dist[u] + calculateDistance(points[u], points[v]) < dist[v]) {
                dist[v] = dist[u] + calculateDistance(points[u], points[v]);
            }
        }
    }

    printf("Shortest path distance from city %d to city %d: %.2lf\n", start, end, dist[end]);
}

int main() {
    int n;
    printf("Enter the number of cities: ");
    scanf("%d", &n);

    Point points[n];

    printf("Enter the coordinates of the cities:\n");
    for (int i = 0; i < n; i++) {
        printf("City %d (x y): ", i);
        scanf("%lf %lf", &points[i].x, &points[i].y);
    }

    int start, end;
    printf("Enter the starting city: ");
    scanf("%d", &start);
    printf("Enter the ending city: ");
    scanf("%d", &end);

    dijkstra(points, n, start, end);


    return 0;
}
