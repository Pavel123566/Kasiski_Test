#include "Vijener.h"

string Vijener::cipher(string str, string key)
{
	vector<string> alphabets;
	string alphabet = "abcdefjhijklmnopqrstuvwxyz";
	string alphabetRed = "abcdefghijklmnopqrstuvwxyz";
	for (int i = 0; i < key.size(); i++) {
		for (int q = 0; q < alphabet.size(); q++) {
			if (key[i] == alphabet[q])
				alphabets.push_back(alphabetRed.substr(q, alphabetRed.size() - q) + alphabetRed.substr(0, q));
		}
	}
	
	vector<string> blocks;
	int bl = str.size() / key.size();
	for (int i = 0; i < str.size(); i++) {
		if (i % bl == 0) {
			blocks.push_back(str.substr(i, bl));
		}
	}
	
	
	for (int i = 0; i < str.size(); i++) {
		for (int q = 0; q < alphabet.size(); q++) {
			if (str[i] == alphabet[q]) {
				str[i] = alphabets[i % key.size()][q];
				break;
			}
		}
	}
	
	return str;
}
