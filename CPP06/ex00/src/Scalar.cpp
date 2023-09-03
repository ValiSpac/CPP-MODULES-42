# include "Scalar.hpp"
# include <string>
# include <cstring>
# include <cstdlib>
# include <climits>
# include <sstream>
#include <cctype>

bool isNumericString(const std::string& str)
{
	for (std::string::const_iterator it = str.begin(); it != str.end(); ++it)
	{
		if (!std::isdigit(*it))
		{
			return false;
		}
	}
	return true;
}

Scalar::Scalar()
{}

Scalar::~Scalar(){}

Scalar::Scalar(const Scalar& ref)
{
	*this = ref;
}

Scalar &Scalar::operator=(const Scalar& ref)
{
	if (this == &ref)
		return (*this);
	return (*this);
}

void Scalar::convert(const std::string& input)
{
	if (!isNumericString(input))
	{
		std::cout << "char: imposible" << std::endl;
		std::cout << "int: imposible" << std::endl;
		std::cout << "float: imposible" << std::endl;
		std::cout << "double: imposible" << std::endl;
		return;
	}
	std::string specialTypes[6] = {
		"-inff", "+inff", "nanf",
		"-inf", "+inf", "nan"
	};
	std::string toChar = "";
	int toInt = 0;
	float toFloat = 0;
	double toDouble = std::atof(input.c_str());
	if (input.size() == 1 && std::isprint(input[0]) && !std::isdigit(input[0]))
	{
		toChar = input[0];
		std::cout << "char: " << toChar << std::endl;
		std::cout << "int: " << static_cast<int>(toChar[0]) << std::endl;
		std::cout << "float: " << static_cast<float>(toChar[0]) << ".0f" << std::endl;
		std::cout << "double: " << static_cast<double>(toChar[0]) << ".0" << std::endl;
		return;
	}
	if (toDouble <= INT_MAX && toDouble >= INT_MIN)
		toInt = std::atoi(input.c_str());
	if (input[input.length() - 1] == 'f')
	{
		toFloat = std::atof(input.c_str());
		toDouble = static_cast<double>(toFloat);
	}
	else
	{
		toDouble = std::atof(input.c_str());
		toFloat = static_cast<float>(toDouble);
	}
	for (int i = 0; i < 6; ++i)
	{
		if (input == specialTypes[i]){
			toChar = "imposible"; break;
		}
	}
	if (toChar == "" && toInt > 32 && toInt < 127)
	{
			toChar = "'";
			toChar += static_cast<char>(toInt);
			toChar += "'";
	}
	if (toChar == "")
		toChar = "Non displayable";
	std::cout << "char: " << toChar << std::endl;
	if (toChar == "imposible")
	{
		std::cout << "int: imposible" << std::endl;
	}
	else
	{
		if (toInt != 0)
			std::cout << "int: " << toInt << std::endl;
		else
			std::cout << "int: imposible" << std::endl;
	}

	if (toChar == "imposible" && toInt == 0){
		std::cout << "float: imposible" << std::endl;
		std::cout << "double: imposible" << std::endl;
	}
	else
	{
		if (toChar != "imposible" && toFloat - static_cast<int>(toFloat) == 0)
		{
			std::cout << "float: " << toFloat << ".0f" << std::endl;
			std::cout << "double: " << toDouble << ".0" << std::endl;
		}
		else
		{
			std::cout << "float: " << toFloat << "f" << std::endl;
			std::cout << "double: " << toDouble << std::endl;
		}
	}
}
