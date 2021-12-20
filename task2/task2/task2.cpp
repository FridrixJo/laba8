#include <iostream>
#include <fstream>

struct Work {
	std::string name;
	std::string n;
	std::string id;
};

std::string Alpha() {
	std::string s;
	std::cin >> s;
	bool status = true;
	std::string example = "qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM";
	while (status) {
		if (s.find_first_not_of(example) > s.size()) {
			return s;
		}
		else {
			std::cout << "!!!WRONG INPUT!!!\tTRY AGAIN\n";
			s = Alpha();
		}
	}
}

std::string Digit() {
	std::string s;
	std::cin >> s;
	bool status = true;
	std::string example = "-0123456789";
	while (status) {
		if (s.find_first_not_of(example) > s.size()) {
			return s;
		}
		else {
			std::cout << "!!!WRONG INPUT!!!\tTRY AGAIN\n";
			s = Digit();
		}
	}
}

void addStruct(Work*& arr, int& size, Work& item) {
	Work* newArr = new Work[size + 1];
	for (int i = 0; i < size; i++) {
		newArr[i].name = arr[i].name;
		newArr[i].n = arr[i].n;
		newArr[i].id = arr[i].id;
	}
	newArr[size].name = item.name;
	newArr[size].n = item.n;
	newArr[size].id = item.id;

	size++;
	delete[] arr;
	arr = newArr;
}

void showData(Work* arr, int& size) {
	for (int i = 0; i < size; i++) {
		std::cout << "\n";
		std::cout << "Name: " << arr[i].name << "\t";
		std::cout << "N: " << arr[i].n << "\t";
		std::cout << "ID: " << arr[i].id << "\t";
		std::cout << "\n\n";
	}
}

void showData(Work** arr, int& size, const int& start) {
	for (int i = start; i < size; i++) {
		std::cout << "\n";
		std::cout << "Name: " << arr[i]->name << "\t";
		std::cout << "N: " << arr[i]->n << "\t";
		std::cout << "ID: " << arr[i]->id << "\t";
		std::cout << "\n\n";
	}
}

Work createNewStruct() {
	Work item;
	std::cout << "Name\t";
	std::cin >> item.name;

	std::cout << "N\t";
	std::cin >> item.n;

	std::cout << "ID\t";
	std::cin >> item.id;

	return item;
}

std::string Str(int b) {
	int a = abs(b);
	std::string s = "";
	int arr[10];
	int n = 0;
	while (a) {
		int b = 0;
		b = a % 10;
		arr[n] = b;
		a /= 10;
		n++;
	}
	std::string s1 = "";
	if (b < 0) {
		s1.push_back('-');
	}
	for (int i = n - 1; i > -1; i--) {
		char var = static_cast<char>(arr[i] + 48);
		s1.push_back(var);
	}
	return s1;
}

int Num(std::string s) {
	int a = 0;
	int k = 0;
	if (s[0] == '-') {
		for (int i = s.size() - 1; i > 0; i--) {
			int b = static_cast<int>(s[i] - 48) * pow(10, k);
			a += b;
			k++;
		}
	}
	else {
		for (int i = s.size() - 1; i > -1; i--) {
			int b = static_cast<int>(s[i] - 48) * pow(10, k);
			a += b;
			k++;
		}
	}
	return a;
}

void Search(Work** arr, const int& size) {
	std::cout << "Write element of your structure\n";
	std::string element;
	std::cin >> element;
	bool status = false;
	for (int i = 0; i < size; i++) {
		if (arr[i]->name == element || arr[i]->n == element || arr[i]->id == element) {
			std::cout << "Name: " << arr[i]->name << "\t";
			std::cout << "N: " << arr[i]->n << "\t";
			std::cout << "ID: " << arr[i]->id << "\t";
			std::cout << "\n";
			status = true;
		}
	}
	if (status == false) {
		std::cout << "There is no such element\n";
	}
}

bool isThere(Work* arr, const int& size, std::string break_element) {
	for (int i = 0; i < size; i++) {
		if (arr[i].name == break_element || arr[i].n == break_element || arr[i].id == break_element) {
			return true;
		}
	}
	return false;
}

void removeItem(Work** arr, const int& size) {
	std::cout << "Write element of your structure you want to delete or change\n";
	std::string element;
	std::cin >> element;
	std::cout << "1. delete / 2. change\n";
	int choice;
	std::cin >> choice;
	std::string newStr = "";
	if (choice == 2) {
		std::cout << "Your new element\n";
		std::cin >> newStr;
	}
	bool status = false;
	for (int i = 0; i < size; i++) {
		bool isChanged = false;
		if (arr[i]->name == element) {
			if (choice == 2) {
				arr[i]->name = newStr;
				isChanged = true;
			}
			else {
				arr[i]->name = "---";
				isChanged = true;
			}
		}
		if (arr[i]->n == element) {
			if (choice == 2) {
				arr[i]->n = newStr;
				isChanged = true;
			}
			else {
				arr[i]->n = "-1";
				isChanged = true;
			}
		}
		if (arr[i]->id == element) {
			if (choice == 2) {
				arr[i]->id = newStr;
				isChanged = true;
			}
			else {
				arr[i]->id = "-1";
				isChanged = true;
			}
		}
	}
	if (status == false) {
		std::cout << "There is no such element\n";
	}
}


int main()
{
	std::ofstream fout;
	setlocale(LC_ALL, "ru");
	fout.open("File.txt");
	fout.close();

	std::cout << "Enter size\t";
	int size;
	std::cin >> size;
	std::cout << "Enter break element\t";
	std::string break_element;
	std::cin >> break_element;
	Work* arr = new Work[size]{};
	for (int i = 0; i < size; i++) {
		std::cout << "Name\t";
		std::cin >> arr[i].name;

		std::cout << "N\t";
		std::cin >> arr[i].n;

		std::cout << "ID\t";
		std::cin >> arr[i].id;

		std::cout << "Year\t";
		std::cin >> arr[i].year;

		std::cout << "Company\t";
		std::cin >> arr[i].company;

		std::cout << "Pages\t";
		std::cin >> arr[i].pages;
		if (isThere(arr, size, break_element)) {
			break;
		}
	}
	std::cout << "Do you want to add one more struct?\n1 (yes) / 2 (no)\n";
	int k;
	Book item;
	std::cin >> k;
	switch (k) {
	case 1:
		item = createNewStruct();
		addStruct(arr, size, item);
		showData(arr, size);
		std::cout << "One more?\n 1 (yes) / 2 (no)\n";
		int q;
		std::cin >> q;
		if (q == 1) {
			int n = 1;
			for (int i = 0; i < n; i++) {
				Book item;
				item = createNewStruct();
				addStruct(arr, size, item);
				showData(arr, size);
				std::cout << "One more?\n 1 (yes) / 2 (no)\n";
				int condition;
				std::cin >> condition;
				if (condition == 1) {
					n++;
				}
				else {
					break;
				}
			}
		}
		break;
	case 2:
		showData(arr, size);
		break;
	default:
		showData(arr, size);
		break;
	}

	Book** array = new Book * [size];
	for (int i = 0; i < size; i++) {
		array[i] = &arr[i];
	}

	Search(array, size);
	removeItem(array, size);
	showData(array, size, 0);
	std::cout << "Do you want to change or delete more elements\n";
	std::cout << "1. yes / 2. no\n";
	int answer;
	std::cin >> answer;
	if (answer == 1) {
		int t = 1;
		removeItem(array, size);
		showData(array, size, 0);
		for (int i = 0; i < t; i++) {
			std::cout << "more?\n";
			std::cout << "1. yes / 2. no\n";
			int l;
			std::cin >> l;
			if (l == 1) {
				removeItem(array, size);
				showData(array, size, 0);
				t++;
			}
			else {
				break;
			}
		}

	}
	int counter = 0;
	shell_sort_up(array, size, counter);
	showData(array, size, counter);
	delete[] arr;
	return 0;
	return  0;
}