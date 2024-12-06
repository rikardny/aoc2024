#include <algorithm>
#include <cstddef>
#include <iostream>
#include <ostream>
#include <string>
#include <vector>

void rotateClockwise(std::vector<std::vector<char>>& matrix) {
    size_t rows = matrix.size();
    size_t cols = matrix[0].size();
    std::vector<std::vector<char>> rotated(cols, std::vector<char>(rows));

    // Rotate elements
    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < cols; ++j) {
            rotated[j][rows - 1 - i] = matrix[i][j];
        }
    }
    matrix = rotated; // Update the original matrix
}

std::vector<std::vector<char>> getDiagonals(const std::vector<std::vector<char>>& matrix) {
	std::vector<std::vector<char>> diagonals;
	
	int rows = matrix.size();
	int cols = matrix[0].size();

	std::vector<char> mainDiagonal;
	for (int i = 0; i < rows; i++) {
		mainDiagonal.push_back(matrix[i][i]);
	}
	diagonals.push_back(mainDiagonal);

	for (int i = 1; i < rows; ++i) {
		std::vector<char> diagonalAbove;
		std::vector<char> diagonalBelow;
		int r = i, c = 0;
		while (r < rows) {
			diagonalAbove.push_back(matrix[r][c]);
			diagonalBelow.push_back(matrix[c][r]);
			r++;
			c++;
		}
		diagonals.push_back(diagonalAbove);
		diagonals.push_back(diagonalBelow);
	}

	return diagonals;
}

void printMatrix(const std::vector<std::vector<char>>& matrix) {
	for (const auto& row : matrix) {
		for (char c: row) {
			std::cout << c;
		}
		std::cout << "\n";
	}
}

int countWords(std::string line, std::string word) {
	int index = 0;
	int count = 0;
	while (line.find(word, index) != std::string::npos) {
		index = line.find(word, index) + 1;
		count++;
	}
	return count;
}

int main() {
	const size_t NUM_LINES = 140;
	const size_t LINE_LENGTH = 140;
	std::vector<std::vector<char>> data;
	std::vector<std::vector<char>> diagonals;

	for (size_t i = 0; i < NUM_LINES; ++i) {
		std::string line;
		std::getline(std::cin, line);
		/*std::cout << line << std::endl;*/
		data.emplace_back(line.begin(), line.end());
	}
	diagonals = getDiagonals(data);

	std::vector<std::string> lines;

	for (const auto& row : data) {
		std::string str(row.begin(), row.end());
		lines.push_back(str);
	}
	for (const auto& row : diagonals) {
		std::string str(row.begin(), row.end());
		lines.push_back(str);
	}

	rotateClockwise(data);
	diagonals = getDiagonals(data);
	for (const auto& row : data) {
		std::string str(row.begin(), row.end());
		lines.push_back(str);
	}
	for (const auto& row : diagonals) {
		std::string str(row.begin(), row.end());
		lines.push_back(str);
	}

	rotateClockwise(data);
	diagonals = getDiagonals(data);
	for (const auto& row : data) {
		std::string str(row.begin(), row.end());
		lines.push_back(str);
	}
	for (const auto& row : diagonals) {
		std::string str(row.begin(), row.end());
		lines.push_back(str);
	}

	rotateClockwise(data);
	diagonals = getDiagonals(data);
	for (const auto& row : data) {
		std::string str(row.begin(), row.end());
		lines.push_back(str);
	}
	for (const auto& row : diagonals) {
		std::string str(row.begin(), row.end());
		lines.push_back(str);
	}

	int count = 0;
	for (size_t i = 0; i < lines.size(); ++i) {
		count += countWords(lines[i], "XMAS");
	}
	std::cout << count << std::endl;

	return 0;
}
