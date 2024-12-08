#include <iostream>
#include <ostream>
#include <vector>

class Guard {
private:
	int x;
	int y;
	char d;

public:
	Guard(int x, int y, char d)
		: x(x), y(y), d(d) {}

	int getX() const { return x; } 
	int getY() const { return y; } 
	char getD() const { return d; }

	void setX(int i) { x = i; }
	void setY(int i) { y = i; }
	void setD(char c) { d = c; }

	int nextX() {
		switch (d) {
			case '^':
				return x;
				break;
			case '>':
				return x + 1;
			case 'v':
				return x;
			case '<':
				return x - 1;
			default:
				std::cout << "Invalid direction!" << std::endl;
				return -1;
		}
	}

	int nextY() {
		switch (d) {
			case '^':
				return y - 1;
				break;
			case '>':
				return y;
			case 'v':
				return y + 1;
			case '<':
				return y;
			default:
				std::cout << "Invalid direction!" << std::endl;
				return -1;
		}
	}

	void move() {
		switch (d) {
			case '^':
				y--;
				break;
			case '>':
				x++;
				break;
			case 'v':
				y++;
				break;
			case '<':
				x--;
				break;
			default:
				std::cout << "Invalid direction!" << std::endl;
		}
	}

	void turn() {
		switch (d) {
			case '^':
				d = '>';
				break;
			case '>':
				d = 'v';
				break;
			case 'v':
				d = '<';
				break;
			case '<':
				d = '^';
				break;
			default:
				std::cout << "Invalid direction!" << std::endl;
		}
	}

	void print() const {
		std::cout << "Guard position: (" << x << ", " << y << "), Direction: " << d << std::endl;
	}
};


void findLocation(Guard& guard, std::vector<std::vector<char>> matrix) {
	for (size_t i = 0; i < matrix.size(); ++i) {
		for (size_t j = 0; j < matrix.size(); ++j) {
			char c = matrix[j][i];
			if (c == '^' || c == '>' || c == 'v' || c == '<') {
				guard.setD(c);
				guard.setX(i);
				guard.setY(j);
				std::cout << "Starting location and direction: " << guard.getX() << "," << guard.getY() << "," << c << std::endl;
			}
		}
	}
}

void printMatrix(const std::vector<std::vector<char>>& matrix) {
    for (const auto& row : matrix) {
        for (const auto& elem : row) {
            std::cout << elem << ' ';
        }
        std::cout << std::endl;
    }
}

int countElements(const std::vector<std::vector<char>>& matrix) {
	int count = 0;
    for (const auto& row : matrix) {
        for (const auto& elem : row) {
			if (elem == 'X') {
				count++;
			}
        }
    }
	return count;
}

int main() {
	std::vector<std::vector<char>> matrix;

	std::string input;
	while (std::getline(std::cin, input)) {
		matrix.emplace_back(input.begin(), input.end());
	}
	printMatrix(matrix);

	Guard guard(0, 0, '^');
	findLocation(guard, matrix);

	int m = matrix.size();

	while (true) {
		if (
			guard.nextX() == -1 || 
			guard.nextX() == m || 
			guard.nextY() == -1 || 
			guard.nextY() == m) 
		{ break; }

		if (matrix[guard.nextY()][guard.nextX()] == '#') {
			guard.turn();
		} else {
			guard.move();
		}
		matrix[guard.getY()][guard.getX()] = 'X';
	}

	printMatrix(matrix);
	std::cout << "Total number of 'X': " << countElements(matrix) << std::endl;

	return 0;
}
