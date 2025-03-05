#include <iostream>
#include <vector>

void solve() {
	int n;
	std::cin >> n;

	std::vector<int> arr(n);
	for (int i = 0; i < n; ++i) {
		std::cin >> arr[i];
	}

	int res_l = 0;
	int res_r = 0;
	int res_sum = arr[0];
	int r = 1;
	int sum = arr[0];
	for (int l = 0; l < n; ++l) {
		sum = arr[l];
		while (r < n && arr[r - 1] < arr[r]) {
			sum += arr[r];
			if (sum > res_sum) {
				res_sum = sum;
				res_l = l;
				res_r = r;
			}
			++r;
		}

		l = r - 1;
		++r;
	}

	std::cout << "Left index=" << res_l << "; Right index=" << res_r << std::endl;
	std::cout << "Sum: " << res_sum << std::endl;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	solve();

	return 0;
}

