#pragma once
#include<sstream>
#include<string>
#include <vector>
#include<iostream>
#include <map>
#include <fstream>
#include <algorithm>

/*olvassón be egy több dimenziós json objektumot és annak tartalmát mentse el egy N x 4 dimenziós vektorként*/
class JSON {

	std::vector<std::vector<int>>steps;
public:
	JSON(){}
	~JSON(){}
//	std::vector<std::vector<int>>readSteps(std::string);
	static std::vector<std::map<std::string, int>> readSteps(std::string);
//	std::vector<std::map<std::string, int>> readSteps(std::string);
	static std::vector<std::map<std::string, int>> parseJson(std::string fname);
};