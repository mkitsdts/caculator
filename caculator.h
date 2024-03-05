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
	//存储最小范围的括号数据
	std::stack <double> num;
	std::stack <char> opt;
	//other data
	std::vector <std::stack <double>> tem_num;
	std::vector <std::stack <char>> tem_opt;
	//caculate process
	void CaculatePrograss();
	void CaculatePrograss(std::vector <std::stack <double>>::reverse_iterator start0, std::vector <std::stack <char>>::reverse_iterator start1);
	//input formula
	void InPut();
	//change string into number and push them into stack
	void StrToNum();
	void StrToNum(std::string::reverse_iterator start, std::string::reverse_iterator end);
	//output
	void OutPut() const;
	Caculator() :sum(0) {};
private:
	//结果
	double sum;
	std::string str;
};

#endif CACULATOR_H