#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color) {
        int color_a_remplazar = image[sr][sc];
        std::queue<std::pair<int, int>> celdas_pendientes;
        celdas_pendientes.push(std::make_pair(sr, sc));

        while (!celdas_pendientes.empty()) {
            std::pair<int, int> celda_act = celdas_pendientes.front();
            celdas_pendientes.pop();

            if ((celda_act.first < 0 || celda_act.first >= image.size()) ||
                (celda_act.second < 0 || celda_act.second >= image[0].size()) ||
                image[celda_act.first][celda_act.second] == color ||
                image[celda_act.first][celda_act.second] != color_a_remplazar)
                continue;

            celdas_pendientes.push(std::make_pair(celda_act.first + 1, celda_act.second));
            celdas_pendientes.push(std::make_pair(celda_act.first - 1, celda_act.second));
            celdas_pendientes.push(std::make_pair(celda_act.first, celda_act.second + 1));
            celdas_pendientes.push(std::make_pair(celda_act.first, celda_act.second - 1));
            image[celda_act.first][celda_act.second] = color;
        }

        return image;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> image = {{1, 1, 1},
                                  {1, 1, 0},
                                  {1, 0, 1}};
    int sr = 1, sc = 1, newColor = 2;
    vector<vector<int>> result = sol.floodFill(image, sr, sc, newColor);

    for (const auto &row : result) {
        for (const auto &cell : row)
            cout << cell << " ";
        cout << endl;
    }

    return 0;
}
