#include <iostream>
#include <array>

int count = 0;

int linear_search(const std::array<int, 11>& arr, int item) {
	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); ++i) {
		count++;
		if (arr[i] == item) {
			return i;
		}
	}
	return NULL;
}

int main() {

	const std::array <int, 11> a = { 1, 4, 5, 8, 5, 1, 2, 7, 5, 2, 11 };

	std::cout << linear_search(a, 111) << '\n'; // 0
	std::cout << count; // 11

}