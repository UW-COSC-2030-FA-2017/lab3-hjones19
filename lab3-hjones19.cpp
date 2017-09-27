/*
 * Hunter Jones
 * COSC 2030, Fall 2017
 * Lab 3
 */
 
#include <iostream>
#include <iomanip>

template <typename T>
T parts1to3(T n) {
	T sum = 0;
	for (T i = 1; i <= n; i++) {
		sum += i;
	}
	return sum;
}

template <typename T>
T parts4and5(long n) {
	T product = 1;
	for (long i = 1; i <= n; i++) {
		product *= i;
	}
	return product;
}

template <typename T>
T part6(int n) {
	T sum = 0;
	for (auto i = 1; i <= n; i++) {
		sum += (1.0 / i);
	}
	return sum - 1.0;
}

template <typename T>
void part7() {
	for (T i = 3.4; i < 4.4; i += 0.2) {
		std::cout << "i = " << i << std::endl;
	}
}

int main(int argc, char *argv[]) {
	
	/* Part 1 */
	std::cout << "Part 1: Sum is " << parts1to3<short>(16) << std::endl;
	// This does not overflow. Correct result: 136, actual result: 136
	
	/* Part 2 */
	std::cout << "Part 2: Sum is " << parts1to3<short>(260) << std::endl;
	// For signed binary integer types, overflow is detected when the result changes signs incorrectly.
	// This overflows. Correct result: 33930, actual result: -31606
	
	/* Part 3 */
	std::cout << "Part 3: Sum is " << parts1to3<long>(70000) << std::endl;
	// This overflows. Correct result: 2450035000, actual result: -1844932296
	
	/* Part 4 */
	std::cout << "Part 4: Product is " << parts4and5<float>(35) << std::endl;
	// For floating-point types, overflow is detected when the result becomes infinity.
	// This overflows. Correct result: (appx.) 1.033e40, actual result: infinity
	
	/* Part 5 */
	std::cout << "Part 5: Product is " << parts4and5<double>(171) << std::endl;
	// This overflows. Correct result: (appx.) 1.241e309, actual result: infinity
	
	/* Part 6 */
	std::cout << std::fixed << std::setprecision(10);
	std::cout << "Part 6.1: Sum is " << part6<float>(50) << std::endl;
	// Floating point precision is limited and errors can accumulate.
	// Correct result: 3.499205338, actual result: 3.4992055893
	std::cout << "Part 6.2: Sum is " << part6<float>(75) << std::endl;
	// Correct result: 3.901355631, actual result: 3.9013562202
	std::cout << "Part 6.3: Sum is " << part6<double>(500) << std::endl;
	// This principle is the same for double, which only offers twice the accuracy.
	// Correct result: 5.792823429, actual result: 5.7928234300
	std::cout << "Part 6.3: Sum is " << part6<double>(750) << std::endl;
	// Correct result: 6.197955389, actual result: 6.1979553900
	
	/* Part 7 */
	std::cout << "Part 7.1:" << std::endl;
	part7<float>();
	// Here we see the errors begin immediately. Since float's precision is
	// limited, the value accumulated is always slightly off, which leads to
	// the final iteration of the loop evaluating to 4.3999 rather than 4.2,
	// which should have been the last iteration of the loop.
	std::cout << "Part 7.2:" << std::endl;
	part7<double>();
	// Because double is a more precise type, the loop behaves as predicted.
	// With more iterations of the loop, however, it too would fail.
	
	return 0;
}
