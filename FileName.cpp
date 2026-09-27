#include <iostream>
#include <string>
#include <vector>
#include <cstring>
// Function templates

//1 F-T

template <typename T>
void printElement(T value) {
	std::cout << value << std::endl;
}
void test_printElement() {
	std::cout << "Testing number 1 F-T" << "\n";
	int a = 5;
	double b = 3.14;
	std::string c = "Hi!";
	printElement(a);
	printElement(b);
	printElement(c);
}

//2 F-T
template <typename A>
void mySwap(A& a, A& b) {
	A temp = a;
	a = b;
	b = temp;
}
void test_mySwap() {
	std::cout << "Testing number 2 F-T" << "\n";
	int a = 5;
	int b = 1;
	mySwap(a, b);
	std::cout << a << "\n" << b << "\n";
	double c = 3.14;
	double d = 6.28;
	mySwap(c, d);
	std::cout << c << "\n" << d << "\n";
	std::string e = "Jamal";
	std::string f = "Lewis";
	mySwap(e, f);
	std::cout << e << "\n" << f << "\n";
}
//3 F-T
template <typename B>
B sumArray(B* arr, int size) {
	B summ = B();
	for (int i = 0; i < size; i++) {
		summ += arr[i];
	}
	return summ;
}
void test_sumArray() {
	std::cout << "Testing number 3 F-T" << "\n";
	int a[5] = { 1, 2 ,3 ,4 , 5 };
	std::cout << sumArray(a, 5) << std::endl;
	double b[2] = { 2.5, 3.5 };
	std::cout << sumArray(b, 2) << std::endl;
	std::string c[2] = { "Jamal", "Lewis" };
	std::cout << sumArray(c, 2) << std::endl;
}
//5 F-T
template <typename C>
int linearSearch(std::vector<C>& arr, C element) {
	for (int i = 0; i < arr.size(); i++) {
		if (arr[i] == element) {
			return i;
		}
	}
	return -1;
}
void test_linearSearch() {
	std::cout << "Testing number 5 F-T" << "\n";
	std::vector<int> a = { 5, 2, 8, 2, 10 };
	std::cout << linearSearch(a, 2) << std::endl;
	std::vector<double> b = { 3.14, 2.71, 6.28 };
	std::cout << linearSearch(b, 6.28) << std::endl;
	std::vector<std::string> c = { "Jamal", "Lewis", "Madara" };
	std::cout << linearSearch(c, std::string("Lewis")) << std::endl;
}



//Class Templates

//1 C-T
template <typename T1, typename T2>
class Pair {
private:
	T1 first;
	T2 second;
public:
	Pair(T1 a, T2 b) : first(a), second(b) {}
	void printPair() {
		std::cout << first << " " << second << std::endl;
	}
};

void test_Pair() {
	std::cout << "Testing number 1 C-T" << "\n";
	Pair<int, double> p1(10, 3.14);
	p1.printPair();
}

//2 C-T
template <typename T, int N>
class FixedArray {
private:
	T arr[N];
public:
	void set(int index, T value) {
		arr[index] = value;
	}
	T get(int index) {
		return arr[index];
	}
	int size() {
		return N;
	}
};

void test_FixedArray() {
	std::cout << "Testing number 2 C-T" << "\n";
	FixedArray<int, 3> a;
	a.set(0, 10);
	a.set(1, 20);
	a.set(2, 30);
	std::cout<< a.size() << "\n";

	FixedArray<std::string, 3> b;
	b.set(0, "Jamal");
	b.set(1, "Lewis");
	b.set(2, "Madara");

	std::cout << b.get(0) << "\n";
	std::cout << b.get(1) << "\n";
	std::cout << b.get(2) << "\n";

}

//3 C-T
template <typename T, int N, int M>
class Matrix {
private:
	T arr[N][M];
public:
	void set(int row, int col, T value) {
		arr[row][col] = value;
	}
	T get(int row, int col) {
		return arr[row][col];
	}
	void print() {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				std::cout << arr[i][j] << " ";
			}
			std::cout << "\n";
		}
	}
	Matrix<T, N, M> operator+(const Matrix<T, N, M>& other) {
		Matrix<T, N, M> result;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				result.arr[i][j] = arr[i][j] + other.arr[i][j];
			}
		}
		return result;
	}
};

void test_Matrix() {
	std::cout << "Testing number 3 C-T" << "\n";
	Matrix<int, 2, 2> a;

	a.set(0, 0, 1);
	a.set(0, 1, 2);
	a.set(1, 0, 3);
	a.set(1, 1, 4);
	a.print();

	Matrix<std::string, 2, 2> b;

	b.set(0, 0, "Hello");
	b.set(0, 1, "World");
	b.set(1, 0, "Jamal");
	b.set(1, 1, "Madara");
	b.print();
}


//4 C-T
template <typename T>
class Range {
private:
	T start;
	T end;
public:
	Range(T _start, T _end) : start(_start), end(_end){}
	bool contains(const T& value) {
		if (value <= end && value >= start) {
			return true;
		}
		else {
			return false;
		}
	}
	int length() {
		return end - start;
	}
	void print() {
		std::cout << start << " " << end << std::endl;
	}
};

void test_Range() {
	std::cout << "Testing number 4 C-T" << "\n";
	Range<int> a(3, 10);
	a.print();
	std::cout << a.length() << "\n";
	std::cout << a.contains(5) << "\n";
	Range<double> b(2.5, 7.5);
	b.print();
	std::cout << b.length() << "\n";
	std::cout << b.contains(10) << "\n";
	Range<char> c('a', 'f');
	c.print();
	std::cout << c.length() << "\n";
	std::cout << c.contains('z') << "\n";

}

//Template specialization
//1
template <typename T>
void printValue(const T& value) {
	std::cout << value << std::endl;
}
template <>
void printValue(const bool& value) {
	if (value == true) {
		std::cout << true << std::endl;
	}
	else {
		std::cout << false << std::endl;
	}
}
void printValue(const char& value) {
	std::cout << "[" << value << "]" << std::endl;
}

void test_printValue() {
	std::cout << "Testing number 1 T-S" << "\n";
	printValue(12.5);
	bool a = true;
	printValue(a);
	char c[] = "Hello World";
	printValue(c);
}

//2

template <typename T>
bool isEqual(const T a, const T b) {
	if (a == b) {
		return true;
	}
	return false;
}
template <>
bool isEqual(const char* a, const char* b) {
	if (strcmp(a, b) == 0) {
		return true;
	}
	return false;
}

void test_isEqual() {
	std::cout << "Testing number 2 T-S" << "\n";
	std::cout << isEqual(5, 10) << std::endl;
	const char* a = "Hello";
	const char* b = "Hello";
	const char* c = "World";
	std::cout << isEqual(a, b) << std::endl;
	std::cout << isEqual(a, c) << std::endl;

}
int main() {
	//1 F-T
	test_printElement();
	//2 F-T
	test_mySwap();
	//3 F-T
	test_sumArray();
	//5 F-T
	test_linearSearch();
	//1 C-T
	test_Pair();
	//2 C-T
	test_FixedArray();
	//3 C-T
	test_Matrix();
	//4 C-T
	test_Range();
	//1 T-S
	test_printValue();
	//2 T-S
	test_isEqual();
	return 0;
}