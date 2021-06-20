#include <iostream>
#include <string>

using namespace std;

template<typename T>
class myVector {

public:
	T* mainArr = new T; // 값이 본격적으로 움직이는 곳
	T* subArr = new T; // 메인 배열을 움직이기 위해 조절하는 곳
	int index = 0;
	
	void push(T value) { // 값을 집어넣는다.
		subArr = new int[index];
		for (int i = 0; i < index; i++)
			subArr[i] = mainArr[i];
		index++;
		mainArr = new int[index];
		if (index != 1) {
			for (int i = 0; i < index - 1; i++)
				mainArr[i] = subArr[i];
		}
		mainArr[index - 1] = value;
	}

	void pop() { // 값을 빼낸다.
		for (int i = 0; i < index; i++)
			subArr[i] = mainArr[i];
		index--;
		mainArr = new int[index];

		for (int i = 0; i < index; i++)
			mainArr[i] = subArr[i];
	}

	void print() { // vector의 값을 출력한다. [Debug]
		for (int i = 0; i < size(); i++)
			cout << mainArr[i] << " ";
		cout << endl;
	}

	void fix(int index, T value) {
		if (index < 0 || index >= this->index)
			cout << "ERROR" << endl;
		else mainArr[index] = value;
	}

	int size() {
		return index;
	}
};

int main() {

	myVector<int> v;
	v.push(2);
	v.push(3);
	v.print();
	v.pop();
	v.print();
	return 0;
}