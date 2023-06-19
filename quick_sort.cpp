#include <iostream>
#include <vector>

int count = 0;

std::vector<int> quick_sort(std::vector<int>& vec) {
	if (vec.size() <= 1) {
		return vec;
	}
	int pivotIndex = std::round(vec.size() / 2);
	int pivot = vec[pivotIndex];
	std::vector<int> less = {};
	std::vector<int> greater = {};
	for (int i = 0; i < vec.size(); ++i) {
		count++;
		if (i == pivotIndex) {
			continue;
		}
		if (vec[i] < pivot) {
			less.push_back(vec[i]);
		} else {
			greater.push_back(vec[i]);
		}
	}
	less = quick_sort(less);
	greater = quick_sort(greater);
	std::vector<int> sortedVec;
	sortedVec.insert(sortedVec.end(), less.begin(), less.end());
	sortedVec.push_back(pivot);
	sortedVec.insert(sortedVec.end(), greater.begin(), greater.end());
	return sortedVec;
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

	std::cout << vec << '\n'; // [ 0, 3, 2, 5, 6, 8, 1, 9, 4, 2, 1, 2, 9, 6, 4, 1, 7, -1, -5, 23, 6, 2, 35, 6, 3, 32 ]

	std::cout << quick_sort(vec) << '\n'; // [ -5 -1 0 1 1 1 2 2 2 2 3 3 4 4 5 6 6 6 6 7 8 9 9 23 32 35 ]

	std::cout << count; // 112
}