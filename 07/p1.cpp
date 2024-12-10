#include <iostream>
#include <ostream>
#include <sstream>
#include <string>
#include <vector>

int main() {
	std::vector<int> answers;
	std::vector<std::vector<int>> values;

	std::string line;
	while (std::getline(std::cin, line)) {

		int firstInt;
		std::vector<int> numbers;

		std::istringstream stream(line);
		std::string part;
		if (std::getline(stream, part, ':')) {
			answers.push_back(std::stol(part));
		}

		if (std::getline(stream, part)) {
			std::istringstream numStream(part);
			int num;
			while (numStream >> num) {
				numbers.push_back(num);
			}
		}
		values.push_back(numbers);
	}

	for (size_t i = 0; i < answers.size(); ++i) {




		
		std::cout << answers[i] << ": ";
		for (size_t j = 0; j < values[i].size(); ++j) {
			std::cout << values[i][j] << " ";
		}
		std::cout << std::endl;
	}


	return 0;
}
