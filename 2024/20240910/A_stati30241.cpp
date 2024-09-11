#include <algorithm>
#include <iostream>
#include <string>
#include <vector>


int main() {
	using namespace std::string_literals;
	std::vector<std::string> vec;

	int n; std::cin >> n;
	for (size_t i = 0; i < n; ++i) {
		std::string str = "";
		std::cin >> str;
		vec.push_back(str);
	}

	for (auto& str : vec) {
		for (char ch : str) if (!isalpha(ch)) break;
		std::sort(str.begin(), str.end());
		if ("abcdefghijklmnopqrstuvwxyz"s.find(str) != std::string::npos) std::cout << "YES\n";
		else std::cout << "NO\n";
	}

	return 0;
}
