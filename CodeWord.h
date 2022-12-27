#include "CodeWord.h"

string CodeWord::cipher(string str, string key)
{
    //формируем шифрующий алфавит
    string alphabet = "abcdefjhijklmnopqrstuvwxyz";
	string alphabet2 = key; //алфавит для шифрования
    for (int i = 0; i < key.size(); i++) {
        for (int q = 0; q < alphabet.size(); q++) {
            if (alphabet[q] != key[i]) {
                alphabet2 += alphabet[q];
            }
            else {
                continue;
            }
            if (alphabet2.size() == 26) {
                break;
            }
        }
        if (alphabet2.size() == 26) {
            break;
        }
    }

	//шифруем
	string str2 = str;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == ' ') {
			str2[i] = ' ';
		}
		else {
            for (int q = 0; q < alphabet.size(); q++) {
                if (str[i] == alphabet[q]) {
                    str2[i] = alphabet2[q];
                    break;
                }
            }
		}
	}   
    return str2;
}


