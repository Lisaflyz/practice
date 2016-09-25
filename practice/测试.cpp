#include<iostream>
#include<vector>
#include<string>
#include <sstream>
using namespace std;

vector<string> split(string str){
	stringstream ss;
	ss << str;
	string words;
	vector<string> result;
	while (ss >> words) {
		result.push_back(words);
	}
	return result;
}



int main12(){
	return 0;

}


