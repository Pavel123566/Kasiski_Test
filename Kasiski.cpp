#include "Kasiski.h"

void Kasiski::kasiskiTest(string str2)
{
	vector<int> index;
	//нахождение одинаковых подстрок длиной не менее 3 символов
	for (int i = 0; i < str2.size(); i++) {
		for (int q = 3; q < str2.size(); q++) {
			string str3 = str2.substr(i, q);
			for (int w = i + 1; w < str2.size(); w++) {
				if (str3 == str2.substr(w, q)) {
					cout << "The same substring: " << str3 << endl;
					cout << "The distance between the same substring: " << w - i << endl;
					index.push_back(w - i);
					cout << endl;
				}
			}
		}
	}
	//формируем вектор из делителей расстояний между одинаковыми подстроками
	vector<int> dividers;
	for (int i = 0; i < index.size(); i++) {
		for (int q = 2; q < index[i]; q++) { //берем i от 2, потому что деление на 1 не считается 
			if (index[i] % q == 0) {
				dividers.push_back(q);
			}
		}
	}

	//сортировка вектора делителей по возрастанию
	for (int i = 0; i < dividers.size(); i++) {
		for (int q = 0; q < dividers.size(); q++) {
			if (dividers[i] < dividers[q]) {
				int temp = dividers[i];
				dividers[i] = dividers[q];
				dividers[q] = temp;
			}
		}
	}
	//выводим на экран один или несколько делителей, которые встречаются чаще всего
	//это уже более точный массив делителей, которые могут быть длинами ключей
	int max = 0;
	int count = 0;
	for (int i = 0; i < dividers.size(); i++) {
		for (int q = 0; q < dividers.size(); q++) {
			if (dividers[i] == dividers[q]) {
				count++;
			}
		}
		if (count > max) {
			max = count;
		}
		count = 0;
	}
	
	vector<int> keySizes;
	for (int i = 0; i < dividers.size(); i++) {
		for (int q = 0; q < dividers.size(); q++) {
			if (dividers[i] == dividers[q]) {
				count++;
			}
		}
		if (count == max) {
			//cout << "The most common divider: " << dividers[i] << endl;
			keySizes.push_back(dividers[i]);
		}
		count = 0;
		}
	int maxSize = 0;
	for (int i = 0; i < keySizes.size(); i++) {
		if (keySizes[i] > maxSize) {
			maxSize = keySizes[i];
		}
	}
	//мы получили размер ключа, теперь можно записать все комбинации исходной строки 
	//(каждая буква находится на расстоянии maxSize от следующей)
	//количество комбинаций будет равно maxSize

	vector<string> combinations;
	for (int i = 0; i < maxSize; i++) {
		string combination = "";
		for (int q = i; q < str2.size(); q+= maxSize) {
			combination += str2[q];
		}
		combinations.push_back(combination);
	}
	cout << endl;
	cout << "Size of key " << maxSize << " sumbols" << endl;
}
