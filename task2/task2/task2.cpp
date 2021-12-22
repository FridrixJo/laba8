#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

std::ifstream fin("input.txt");
std::ofstream fout("output.txt");


struct Work {
	std::string name;
	std::string n;
	std::string id;
};

std::string line() {
	return "======================================\n";
}

void getData(Work* arr, const int& size) {
	for (int i = 0; i < size; i++) {
		std::getline(fin, arr[i].name);
		std::getline(fin, arr[i].n);
		std::getline(fin, arr[i].id);
	}
}

void outputData(Work* arr, const int& size) {
	for (int i = 0; i < size; i++) {
		fout << "\n";
		fout << line();
		fout << "Name: " << arr[i].name << "\t";
		fout << "N: " << arr[i].n << "\t";
		fout << "ID: " << arr[i].id << "\t";
		fout << "\n";
		fout << line();
	}
}

void outputData(Work** arr, const int& size) {
	for (int i = 0; i < size; i++) {
		fout << "\n";
		fout << line();
		fout << "Name: " << arr[i]->name << "\t";
		fout << "N: " << arr[i]->n << "\t";
		fout << "ID: " << arr[i]->id << "\t";
		fout << "\n";
		fout << line();
	}
}

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

int CurrentInput() {
	int a;
	while (!(std::cin >> a) || a < 0) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits < std::streamsize > ::max(), '\n');
		std::cout << "!!!WRONG INPUT!!!\tTRY AGAIN\n";
	}
	return a;
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

void showData(Work** arr, int& size) {
	for (int i = 0; i < size; i++) {
		std::cout << "\n";
		std::cout << "Name: " << arr[i]->name << "\t";
		std::cout << "N: " << arr[i]->n << "\t";
		std::cout << "ID: " << arr[i]->id << "\t";
		std::cout << "\n\n";
	}
}

Work createNewStruct() {
	Work item;
	std::cout << "\n";
	std::cout << "Name\t";
	item.name = Alpha();

	std::cout << "N\t";
	item.n = Digit();

	std::cout << "ID\t";
	item.id = Digit();
	std::cout << "\n";

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
	fout << "Write element of your structure\n";
	std::string element;
	std::cin >> element;
	fout << element << "\n";
	bool status = false;
	for (int i = 0; i < size; i++) {
		if (arr[i]->name == element || arr[i]->n == element || arr[i]->id == element) {
			std::cout << "\n";
			std::cout << "Name: " << arr[i]->name << "\t";
			std::cout << "N: " << arr[i]->n << "\t";
			std::cout << "ID: " << arr[i]->id << "\t";
			std::cout << "\n\n";
			fout << "\n";
			fout << line();
			fout << "Name: " << arr[i]->name << "\t";
			fout << "N: " << arr[i]->n << "\t";
			fout << "ID: " << arr[i]->id << "\t";
			fout << "\n";
			fout << line();
			status = true;
		}
	}
	if (status == false) {
		std::cout << "There is no such element\n";
		fout << "There is no such element\n";
	}
}

bool isThere(Work* arr, const int& size, std::string& break_element) {
	for (int i = 0; i < size; i++) {
		if (arr[i].name == break_element || arr[i].n == break_element || arr[i].id == break_element) {
			return true;
		}
	}
	return false;
}

void removeItem(Work** arr, const int& size) {
	std::cout << "Write element of your structure you want to delete or change\n";
	fout << "Write element of your structure you want to delete or change\n";
	std::string element;
	std::cin >> element;
	fout << element << "\n";
	std::cout << "1. delete / 2. change\n";
	fout << "1. delete / 2. change\n";
	int choice = CurrentInput();
	fout << choice << "\n";
	std::string newStr = "";

	bool status = false;
	for (int i = 0; i < size; i++) {
		bool isChanged = false;
		if (arr[i]->name == element) {
			if (choice == 2) {
				std::cout << "Your new Name element\n";
				fout << "Your new Name element\n";
				newStr = Alpha();
				fout << newStr << "\n";
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
				std::cout << "Your new N element\n";
				fout << "Your new N element\n";
				newStr = Digit();
				fout << newStr << "\n";
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
				std::cout << "Your new ID element\n";
				fout << "Your new ID element\n";
				newStr = Digit();
				fout << newStr << "\n";
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
		fout << "There is no such element\n";
	}
}

void shell_sort_down(Work** arr, const int& size) {
	int i, j, temp;
	for (int step = size / 2; step > 0; step /= 2) {
		for (i = step; i < size; i++) {
			Work* temp = arr[i];
			int tmp = Num(arr[i]->n);
			for (j = i; j >= step; j -= step) {
				if (tmp <= Num(arr[j - step]->n)) {
					break;
				}
				arr[j] = arr[j - step];
			}
			arr[j] = temp;
		}
	}
}

void sort(Work** arr, const int& size) {
	std::cout << "Enter workspace ID\n";
	fout << "Enter workspace ID\n";
	std::string id = "";
	id = Digit();
	fout << id << "\n";
	std::cout << "ID of the workspace: " << id << "\n";
	fout << "ID of the workspace: " << id << "\n";
	for (int i = 0; i < size; i++) {
		if (arr[i]->id == id) {
			std::cout << std::setw(10) << arr[i]->name << "   =   " << arr[i]->n << "\n";
			fout << std::setw(10) << arr[i]->name << "   =   " << arr[i]->n << "\n";

		}
	}
}


int main()
{
	std::string file_var = "";
	bool status = false;

	if (!fin.is_open()) {
		std::cout << "Error\n";
	}
	else {
		std::cout << "File was opened\n";
		status = true;
		std::getline(fin, file_var);
	}

	std::cout << "Size: \t";

	int size = Num(file_var);
	std::cout << size << "\n";
	std::cout << "Enter break element\t";
	std::string break_element;
	std::getline(fin, break_element);
	std::cout << break_element << "\n";
	Work* arr = new Work[size];
	getData(arr, size);
	showData(arr, size);
	outputData(arr, size);


	for (int i = 0; i < size; i++) {
		getline(fin, arr[i].name);
		getline(fin, arr[i].n);
		getline(fin, arr[i].id);
	}

	std::cout << "Do you want to add one more struct?\n1 (yes) / 2 (no)\n";
	fout<< "Do you want to add one more struct?\n1 (yes) / 2 (no)\n";
	int k = CurrentInput();
	fout << k << "\n";
	Work item;
	switch (k) {
	case 1:
		item = createNewStruct();
		addStruct(arr, size, item);
		showData(arr, size);
		outputData(arr, size);
		std::cout << "One more?\n 1 (yes) / 2 (no)\n";
		fout << "One more?\n 1 (yes) / 2 (no)\n";
		int q;
		std::cin >> q;
		fout << q << "\n";
		if (q == 1) {
			int n = 1;
			for (int i = 0; i < n; i++) {
				Work item;
				item = createNewStruct();
				addStruct(arr, size, item);
				showData(arr, size);
				outputData(arr,size);
				std::cout << "One more?\n 1 (yes) / 2 (no)\n";
				fout << "One more?\n 1 (yes) / 2 (no)\n";
				int condition = CurrentInput();
				fout << condition << "\n";
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
		outputData(arr, size);
		break;
	default:
		showData(arr, size);
		outputData(arr, size);
		break;
	}

	Work** array = new Work * [size];
	for (int i = 0; i < size; i++) {
		array[i] = &arr[i];
	}

	Search(array, size);
	removeItem(array, size);
	showData(array, size);
	outputData(arr, size);

	std::cout << "Do you want to change or delete more elements\n";
	fout << "Do you want to change or delete more elements\n";
	std::cout << "1. yes / 2. no\n";
	fout << "1. yes / 2. no\n";
	int answer;
	std::cin >> answer;
	fout << answer << "\n";
	if (answer == 1) {
		int t = 1;
		removeItem(array, size);
		showData(array, size);
		outputData(arr, size);
		for (int i = 0; i < t; i++) {
			std::cout << "more?\n";
			fout << "more?\n";
			std::cout << "1. yes / 2. no\n";
			fout<< "1. yes / 2. no\n";
			int l;
			std::cin >> l;
			fout << l << "\n";
			if (l == 1) {
				removeItem(array, size);
				showData(array, size);
				outputData(arr, size);
				t++;
			}
			else {
				break;
			}
		}

	}
	shell_sort_down(array, size);
	sort(array, size);
	delete[] arr;
	delete[] array;
	return 0;
}