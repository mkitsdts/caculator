#ifndef CACULATOR_H 
#define CACULATOR_H 
#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <string>

class Caculator
{
public:
	std::stack <double> num;
	std::stack <char> opt;
	void CaculatePrograss();
	std::string CaculatePrograss(std::string s);
	void InPut();
	void StrToNum();
	void StrToNum(std::string s);
	void OutPut() const;
	Caculator() :sum(0) {};
private:
	double sum;
	std::string str;
};

#endif CACULATOR_H