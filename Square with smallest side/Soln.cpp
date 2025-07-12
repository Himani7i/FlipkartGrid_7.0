#include <iostream>
using namespace std;

int globalNumberOfPoints;

bool pointExists(int x, int y, int x_coordinates[], int y_coordinates[]) {
    for (int i = 0; i < globalNumberOfPoints; i++) {
        if (x_coordinates[i] == x && y_coordinates[i] == y)
            return true;
    }
    return false;
}

void solveSquares(int x_coordinates[], int y_coordinates[]) {
    int minSide = 1e9;

    for (int i = 0; i < globalNumberOfPoints; i++) {
        for (int j = 0; j < globalNumberOfPoints; j++) {
            //(x1, y1) as bottom-left, (x2, y2) as top-right
            int x1 = x_coordinates[i], y1 = y_coordinates[i];
            int x2 = x_coordinates[j], y2 = y_coordinates[j];

            if (x1 == x2 || y1 == y2) continue; // skip if not diagonal corner
            if (abs(x1 - x2) != abs(y1 - y2)) continue; // not a square

            //Check if other 2 corners exist
            if (pointExists(x1, y2, x_coordinates, y_coordinates) &&
                pointExists(x2, y1, x_coordinates, y_coordinates)) {
                int side = abs(x1 - x2);
                if (side < minSide) {
                    minSide = side;//update minimum side length
                }
            }
        }
    }

    if (minSide == 1e9)
        cout << -1 << endl;
    else
        cout << minSide << endl;
}

int main() {
    int numberOfPoints;
    cin >> numberOfPoints;
    globalNumberOfPoints = numberOfPoints;

    int x_coordinates[numberOfPoints], y_coordinates[numberOfPoints];

    for (int i = 0; i < numberOfPoints; i++) {
        cin >> x_coordinates[i] >> y_coordinates[i];
    }

    solveSquares(x_coordinates, y_coordinates);
    return 0;
}