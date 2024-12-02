#include <algorithm>
#include <iostream>
#include <ostream>
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

		bool safe = false;

		for (size_t index = 0; index < integers.size(); ++index) {
			int removed;
			std::vector<int> vec = integers;
			if (index < vec.size()) {
				removed = vec[index];
				vec.erase(vec.begin() + index);
			} else {
				std::cout << "Index out of bounds." << std::endl;
			}

			std::vector<int> sorted = vec;
			std::sort(sorted.begin(), sorted.end());

			bool increasing = (vec == sorted);
			std::reverse(sorted.begin(), sorted.end());

			bool decreasing = (vec == sorted);
			bool gradual = true;

			for (size_t i = 1; i < vec.size(); ++i) {
				int diff = abs(vec[i] - vec[i-1]);
				if (diff < 1 || 3 < diff) {
					gradual = false;
				}
			}

			if ((increasing || decreasing) && gradual) {
				safe = true;
				std::cout << removed << " ";
			}
		}

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
