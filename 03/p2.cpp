#include <iostream>
#include <ostream>
#include <regex>
#include <string>
#include <vector>

int main() {
	std::string input;
	std::string line;
	std::vector<std::string> instructions;

	// Remove newlines from input
	while (std::getline(std::cin, line)) {
		input += line;
	}

	std::cout << input << std::endl;

	int index = 0;

	while (true) {
		int start = input.find("don't()", index);
		if (start == std::string::npos) {
			break;
		}
		int end = input.find("do()", start);
		if (end == std::string::npos) {
			std::fill(input.begin() + start, input.end(), '*');
			break;
		}

		for (size_t i = start; i < end; ++i) {
			input[i] = '*';
		}
		index = end + 1;
	}
	/*std::cout << input << std::endl;*/

	std::regex pattern(R"(mul\(\d{1,3},\d{1,3}\))");

	for (std::sregex_iterator it(input.begin(), input.end(), pattern), end_it; it != end_it; ++it) {
		instructions.push_back(it->str());
	}

	int sum = 0;

	for (size_t i = 0; i < instructions.size(); ++i) {
		std::string mul = instructions[i];

		int d1 = mul.find("(");
		int d2 = mul.find(",");
		int d3 = mul.find(")");

		int first = std::stoi(mul.substr(d1+1, d2-d1));
		int second = std::stoi(mul.substr(d2+1, d3-d2));

		std::cout << mul << " - " << first << " x " << second << "\t= " << first*second << "\n";
		sum += first * second;
	}
	std::cout << "Sum: " << sum << "\n";

	return 0;
}
