# pragma once

# include <iostream>
# include <stdint.h>

struct Data{
		int n;
};

class Serializer
{
	private:
		~Serializer();
	public:
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
		Serializer();
		Serializer(const Serializer& ref);
		Serializer &operator=(const Serializer& ref);
};
