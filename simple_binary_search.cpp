#include <iostream>
#include <array>

int count = 0;

int binary_search(const std::array<int, 16> arr, const int item) {
	int start = 0;
	int end = arr.size();
	int middle;

	bool found = false;
	int position = -1;

	while (found == false || start <= end) {
		count++;
		middle = std::round((start + end)/2);
		if (arr[middle] == item) {
			found = true;
			position = middle;
			return position;
		} 
		else if (item < arr[middle]) {
			end = middle - 1;
		}
		else {
			start = middle + 1;
		}
	}
	return position;
}

int main() {

	std::array <int, 16> a = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15 };

	std::cout << binary_search(a, 4) << std::endl;
	std::cout << count;
}