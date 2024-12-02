#include <algorithm>
#include <iostream>
#include <vector>

int main() {
	std::string line;

	int noSafe = 0;

	while (std::getline(std::cin, line)) {

		std::vector<int> integers;
		size_t start = 0;
		size_t split;

		while ((split = line.find(' ', start)) != std::string::npos) {
			int num = std::stoi(line.substr(start, split - start));
			integers.push_back(num);
			start = split + 1;
		}

		// Add last integer
		if (start < line.size()) {
			integers.push_back(std::stoi(line.substr(start)));
		}

		std::vector<int> sorted = integers;
		std::sort(sorted.begin(), sorted.end());

		bool increasing = (integers == sorted);
		std::reverse(sorted.begin(), sorted.end());

		bool decreasing = (integers == sorted);
		bool gradual = true;

		for (size_t i = 1; i < integers.size(); ++i) {
			int diff = abs(integers[i] - integers[i-1]);
			if (diff < 1 || 3 < diff) {
				gradual = false;
			}
		}

		bool safe = (increasing || decreasing) && gradual;
		if (safe) {
			noSafe++;
		}
		std::cout << (safe ? "SAFE\t" : "UNSAFE\t");
		for (size_t i = 0; i < integers.size(); ++i) {
			std::cout << integers[i] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << noSafe << std::endl;

	return 0;
}
