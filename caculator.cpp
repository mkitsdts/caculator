#include "caculator.h"

void Caculator::InPut()
{
	std::cin >> str;
}

void Caculator::StrToNum(std::string s)
{
	int times;
	double temp;
	for (auto iter = s.rbegin(); iter != s.rend(); ++iter)
	{
		bool is = false;
		temp = 0; times = 0;
		while ((*iter) >= '0' && (*iter) <= '9')
		{
			is = true;
			temp = temp + (*iter - '0') * pow(10, times);
			++times;
			if (iter != s.rend())
			{
				++iter;
			}
			if (iter == s.rend())
			{
				break;
			}
		}
		if (is)
		{
			num.push(temp);
		}
		if (iter == s.rend())
		{
			break;
		}
		opt.push(*iter);
	}
}

void Caculator::StrToNum()
{
	int times;
	double temp;
	std::string::iterator b= str.begin();
	std::string::iterator e= str.begin();
	for (auto iter = str.begin(); iter != str.end(); ++iter)
	{
		bool is = false;;
		temp = 0; 
		times = 0;
		if ((*iter) == '(')
		{
			b = iter;
			while (*iter != ')')
			{
				++iter;
				if (iter == str.end())
				{
					is = true;
					std::cout << "InPut Error" << std::endl;
					exit(-1);
				}
				if (*iter == ')')
				{
					
					e = iter;
					std::string s(b+1, e);
					std::string tmp;
					if(b != str.begin())
					{
						tmp = '+' + CaculatePrograss(s);
					}
					else
					{
						tmp = CaculatePrograss(s);
					}
					int t = (int)std::distance(str.begin(), b);
					str.erase(b, e + 1);
					str.insert(t,tmp); 
					if (str.size() != 0)
					{
						iter = str.begin();
						break;
					}
				}
				else if (*iter == '(')
				{
					b = iter;
				}
			}
		}
		if (is)
		{
			break;
		}
	}
	if(str.size() == 0)
	{
		CaculatePrograss();
	}
	else
	{
		StrToNum(str);
		CaculatePrograss();
	}
}


void Caculator::OutPut() const
{
	std::cout << sum << "\n";
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

std::string Caculator::CaculatePrograss(std::string s)
{
	double t=0;
	std::stack<double> _num;
	std::stack <char> _opt;
	StrToNum(s);
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
			t = t + temp;
			continue;
		}
		else if (opt.top() == '/')
		{
			double temp = num.top();
			num.pop();
			temp = temp / num.top();
			num.pop();
			opt.pop();
			t = t + temp;
			continue;
		}
	}
	while (!_opt.empty())
	{
		if (_opt.top() == '+')
		{
			t = t + _num.top();
			_num.pop();
			_opt.pop();
			continue;
		}
		else if (opt.top() == '-')
		{
			t = t - _num.top();
			_num.pop();
			_opt.pop();
			continue;
		}
	}
	if (!_num.empty())
	{
		t = t + _num.top();
	}
	return std::to_string((int)t);
}