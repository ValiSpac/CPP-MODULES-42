
#pragma once

template< typename T>
class Array
{
	private:
		T				*_array;
		unsigned int	_size;

	public:
		Array(): _size(0)
		{
			this->_array = new T[this->_size];
		}
		Array(unsigned int size): _size(size)
		{
			this->_array = new T[this->_size];
		}
		Array(const Array &src): _size(src.size())
		{
			this->_array = NULL;
			*this = src;
		}
		~Array()
		{
			if (this->_array != NULL)
				delete [] this->_array;
		}
		Array &operator=(const Array &src)
		{
			if (this->_array != NULL)
				delete [] this->_array;
			if (src.size() != 0)
			{
				this->_size = src.size();
				this->_array = new T[this->_size];
				for (unsigned int i = 0; i < this->size(); i++)
					this->_array[i] = src._array[i];
			}
			return (*this);
		}
		T &operator[](int index )
		{
			if (index >= static_cast<int>(this->_size) || this->_array == NULL || index < 0)
			{
				std::cout << "index: " << index << std::endl;
				throw Array<T>::InvalidIndexException();
			}
			return (this->_array[index]);
		}
		class	InvalidIndexException : public std::exception
		{
		public:
			virtual const char	*what() const throw();
		};
		unsigned int size() const
		{
			return (this->_size);
		}
};

template< typename T >
const char	*Array<T>::InvalidIndexException::what() const throw()
{
	return ("Error: Invalid index");
}
