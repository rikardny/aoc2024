#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

int main() {
	std::vector<int> list1;
	std::vector<int> list2;

	std::string line;
	int num1 = 0, num2 = 0;

	while (std::getline(std::cin, line)) {

		size_t split = line.find(' ');

		num1 = std::stoi(line.substr(0, split));
		num2 = std::stoi(line.substr(split + 1));

		list1.push_back(num1);
		list2.push_back(num2);
	}

	std::sort(list2.begin(), list2.end());

	int sum = 0;
	int target = 0;

	for (size_t i = 0; i < list1.size(); ++i) {
		target = list1[i];
		auto it = std::find(list2.begin(), list2.end(), target);

		int count = 0;
		if (it != list2.end()) {
			int index = std::distance(list2.begin(), it);
			while (list2[index] == target) {
				count++;
				index++;
			}
		}
		std::cout << list1[i] << " - " << list2[i] << " = " << count * list1[i] << std::endl;
		sum += count * list1[i];
	}
	std::cout << sum << std::endl;

	return 0;
}
