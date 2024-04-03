#include <iostream>
#include <vector>

using namespace std;

class PlanetSnowflake {
private:
    int N;
    vector<vector<int>> matrix;

public:
    PlanetSnowflake(int n) : N(n) {
        matrix.resize(N, vector<int>(N, 0));
    }

    void readInput() {
        cout << "Enter the number of cities (N): ";
        cin >> N;
        matrix.resize(N, vector<int>(N, 0));
        cout << "Enter the connectivity matrix (1 for connected, 0 for not connected):\n";
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                cin >> matrix[i][j];
            }
        }
    }

    int countRoads() {
        int num_roads = 0;
        for (int i = 0; i < N; ++i) {
            for (int j = i + 1; j < N; ++j) {
                num_roads += matrix[i][j];
            }
        }
        return num_roads;
    }
};

int main() {
    int num_cities;
    cout << "Enter the number of cities on the planet Snowflake: ";
    cin >> num_cities;
    PlanetSnowflake planet(num_cities);
    planet.readInput();
    int num_roads = planet.countRoads();
    cout << "Number of roads on the planet Snowflake: " << num_roads << endl;
    return 0;
}