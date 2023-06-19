#include <iostream>
#include <vector>

int count = 0;

std::vector<int>& bubble_sort(std::vector<int>& vec) {
	for (int i = 0; i < vec.size(); ++i) {
		for (int j = 0; j < vec.size() - i - 1; ++j) {
			if (vec[j + 1] < vec[j]) {
				int tmp = vec[j];
				vec[j] = vec[j + 1];
				vec[j + 1] = tmp;	
			}
			count++;
		}
	}
	return vec;
}

std::ostream& operator<<(std::ostream& out, std::vector<int> const& vec) {
	out << "[ ";
	for (int i = 0; i < vec.size(); ++i) {
		out << vec[i] << " ";
	}
	out << "]";
	return out;
}

int main() {

	std::vector<int> vec = { 0, 3, 2, 5, 6, 8, 1, 9, 4, 2, 1, 2, 9, 6, 4, 1, 7, -1, -5, 23, 6, 2, 35, 6, 3, 32 };

	std::cout << vec << '\n'; // [ 0 3 2 5 6 8 1 9 4 2 1 2 9 6 4 1 7 -1 -5 23 6 2 35 6 3 32 ]

	std::cout << bubble_sort(vec) << '\n'; // [-5 - 1 0 1 1 1 2 2 2 2 3 3 4 4 5 6 6 6 6 7 8 9 9 23 32 35]

	std::cout << count; //325
}