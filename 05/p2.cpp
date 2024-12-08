#include <cstddef>
#include <iostream>
#include <ostream>
#include <string>
#include <vector>

int main() {
	std::vector<std::vector<char>> matrix;

	std::string input;
	while (std::getline(std::cin, input)) {
		matrix.emplace_back(input.begin(), input.end());
	}


	int count = 0;

	for (size_t i = 1; i < matrix.size() - 1; ++i) {
		for (size_t j = 1; j < matrix.size() - 1; ++j) {
			if (matrix[i][j] == 'A') {
				/*std::cout << '.';*/
				char nw = matrix[i-1][j-1];
				char ne = matrix[i-1][j+1];
				char sw = matrix[i+1][j+1];
				char se = matrix[i+1][j-1];
				std::string cross = std::string(1, nw) + ne + sw + se;

				std::cout << i << "," << j << "-" << cross << std::endl;
				if (cross == "MMSS" | cross == "MSSM" | cross == "SSMM" | cross == "SMMS") {
					/*std::cout << "[" << i << "," << j << "]" << std::endl;*/
					count++;
				}
			} else {
				/*std::cout << matrix[i][j];*/
			}
		}
	}
	std::cout << count << std::endl;

	return 0;
}
