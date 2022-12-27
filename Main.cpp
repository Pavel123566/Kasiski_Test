#include "CodeWord.h"
#include "Vijener.h"
#include "Kasiski.h"
using namespace std;
int main() {
	CodeWord cw;
	string str, key;
	cout << "Enter string: ";
	cin >> str;
	cout << "Enter key: ";
	cin >> key;
	cout << endl;
	cout << "Result a cipher with code word: " << cw.cipher(str, key) << endl;
	cout << endl;
	
	Vijener v;
	cout << "Result a cipher by Vigener method: " << v.cipher(str, key) << endl;

	string str2;
	cout << "Enter encrypted string: ";
	cin >> str2;

	Kasiski ktest;
	ktest.kasiskiTest(str2);
	//для тестирования
	//PPQCAXQVEKGYBNKMAZUYBNGBALJONITSZMJYIMVRAGVOHTVRAUCTKSGDDWUOXITLAZUVAVVRAZCVKBQPIWPOU
	
	return 0;
}
