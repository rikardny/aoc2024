#include <iostream>
#include <vector>

void updateLocation(int &x, int &y, char &dir, std::vector<std::vector<char>> matrix) {
	for (size_t i = 0; i < matrix.size(); ++i) {
		for (size_t j = 0; j < matrix.size(); ++j) {
			char c = matrix[i][j];
			if (c == '^' || c == '>' || c == 'v' || c == '<') {
				dir = c;
				x = i;
				y = j;
				std::cout << "Updated location with: " << i << "," << j << std::endl;
			}
		}
	}
}



int main() {
	std::vector<std::vector<char>> matrix;

	std::string input;
	while (std::getline(std::cin, input)) {
		matrix.emplace_back(input.begin(), input.end());
	}

	int x, y;
	char dir;

	updateLocation(x, y, dir, matrix);

	return 0;
}
