#include <iostream>
#include <string>

using namespace std;

template<typename T>
class myVector {

public:
	T* mainArr = new T; // ���� ���������� �����̴� ��
	T* subArr = new T; // ���� �迭�� �����̱� ���� �����ϴ� ��
	int index = 0;
	
	void push(T value) { // ���� ����ִ´�.
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

	void pop() { // ���� ������.
		for (int i = 0; i < index; i++)
			subArr[i] = mainArr[i];
		index--;
		mainArr = new int[index];

		for (int i = 0; i < index; i++)
			mainArr[i] = subArr[i];
	}

	void print() { // vector�� ���� ����Ѵ�. [Debug]
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