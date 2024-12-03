#include <iostream>
#include <regex>
#include <string>
#include <vector>

int main() {
	std::string input;
	std::vector<std::string> instructions;

	while (std::getline(std::cin, input)) {
		std::regex pattern(R"(mul\(\d{1,3},\d{1,3}\))");
		std::smatch matches;
		std::string::const_iterator searchStart(input.cbegin());

		while (std::regex_search(searchStart, input.cend(), matches, pattern)) {
			instructions.push_back(matches[0]);
			searchStart = matches.suffix().first;
		}
	}

	int sum = 0;

	for (size_t i = 0; i < instructions.size(); ++i) {
		std::string mul = instructions[i];

		int d1 = mul.find("(");
		int d2 = mul.find(",");
		int d3 = mul.find(")");

		int first = std::stoi(mul.substr(d1+1, d2-d1));
		int second = std::stoi(mul.substr(d2+1, d3-d2));

		sum += first * second;

		std::cout << first << " x " << second << "\t= " << first*second << "\n";
	}
	std::cout << sum;

	return 0;
}
