# pragma once

# include <iostream>

class Scalar
{
	private:
		Scalar();
		Scalar(const Scalar& ref);
		Scalar &operator=(const Scalar& ref);

	public:
		~Scalar();
		static void convert(const std::string& input);
};
