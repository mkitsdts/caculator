#include "caculator.h"

void Caculator::InPut()
{
	std::cin >> str;
}

void Caculator::StrToNum()
{
	int times;
	double temp;
	int i = 0;
	for (auto iter = str.rbegin(); iter != str.rend(); ++iter)
	{
		temp = 0; times = 0;
		if ((*iter) == ')')
		{
			StrToNum(iter, str.rend());
		}
		while ((*iter) >= '0' && (*iter) <= '9')
		{
			temp = temp + (*iter -'0') * pow(10, times);
			++times;
			if (iter != str.rend())
			{
				++iter;
			}
			if (iter == str.rend())
			{
				//temp += (*iter - '0') * pow(10, times);
				break;
			}
		}
		num.push(temp);
		if (iter == str.rend())
		{
			break;
		}
		opt.push(*iter);
	}
	CaculatePrograss();
}


void Caculator::StrToNum(std::string::reverse_iterator start, std::string::reverse_iterator end)
{
	std::stack<double> n;
	std::stack<char> o;
	tem_num.push_back(n);
	tem_opt.push_back(o);
	for (std::string::reverse_iterator iter = start; iter != end; ++iter)
	{
		int times = 0;
		double temp = 0; 
		if (*iter == ')')
		{
			StrToNum(iter, str.rend());
		}
		else if (*iter == '(')
		{
			CaculatePrograss(tem_num.rbegin(),tem_opt.rbegin());
			tem_num.pop_back();
			tem_opt.pop_back();
			return;
		}
		while (*iter >= '0' || *iter <= '9')
		{
			temp += (*iter - '0') * pow(10, times);
			--iter;
			if (iter == str.rbegin())
			{
				temp += (*iter - '0') * pow(10, times);
				break;
			}
		}
		
		if (iter == str.rend())
			break;
		o.push(*iter);
	}
}


void Caculator::OutPut() const
{
	std::cout << sum << "\n";
}


//²»´øÀ¨ºÅµÄ
void Caculator::CaculatePrograss(std::vector <std::stack <double>>::reverse_iterator start0, std::vector <std::stack <char>>::reverse_iterator start1)
{
	std::stack<double>& __num=*start0;
	std::stack <char>& __opt=*start1;
	std::stack<double> _num;
	std::stack <char> _opt;
	while (!__num.empty()&&!__opt.empty())
	{
		if (__opt.top() == '+' || __opt.top() == '-')
		{
			_opt.push(__opt.top());
			_num.push(__num.top());
			__opt.pop();
			__num.pop();
			continue;
		}
		else if (__opt.top() == '*')
		{
			double temp = __num.top();
			__num.pop();
			temp = temp * __num.top();
			_num.push(temp);
			_opt.push('+');
			__num.pop();
			continue;
		}
		else if (__opt.top() == '/')
		{
			double temp = __num.top();
			__num.pop();
			temp = temp / __num.top();
			_num.push(temp);
			_opt.push('+');
			__num.pop();
			continue;
		}
	}
	while (!_num.empty() && !_opt.empty())
	{
		if (__opt.top() == '+')
		{
			double temp = _num.top();
			_num.pop();
			temp = temp + _num.top();
			sum = sum + temp;
			_num.pop();
			_opt.pop();
			continue;
		}
		else if (opt.top() == '-')
		{
			double temp = _num.top();
			_num.pop();
			temp = temp - _num.top();
			sum = sum + temp;
			_num.pop();
			_opt.pop();
			continue;
		}
	}
}

void Caculator::CaculatePrograss()
{
	std::stack<double> _num;
	std::stack <char> _opt;
	while (!num.empty())
	{
		if (opt.top() == '+' || opt.top() == '-')
		{
			_opt.push(opt.top());
			_num.push(num.top());
			opt.pop();
			num.pop();
			if (!opt.empty())
			{
				continue;
			}
			else
			{
				_num.push(num.top()); 
				num.pop();
				break;
			}
		}
		else if (opt.top() == '*')
		{
			double temp = num.top();
			num.pop();
			temp = temp * num.top();
			num.pop();
			opt.pop();
			sum = sum + temp;
			continue;
		}
		else if (opt.top() == '/')
		{
			double temp = num.top();
			num.pop();
			temp = temp / num.top();
			num.pop();
			opt.pop();
			sum = sum + temp;
			continue;
		}
	}
	while (!_opt.empty())
	{
		if (_opt.top() == '+')
		{
			sum = sum + _num.top();
			_num.pop();
			_opt.pop();
			continue;
		}
		else if (opt.top() == '-')
		{
			sum = sum - _num.top();
			_num.pop();
			_opt.pop();
			continue;
		}
	}
	if (!_num.empty())
	{
		sum = sum + _num.top();
	}
}
