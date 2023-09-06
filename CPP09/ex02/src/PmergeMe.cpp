# include "PmergeMe.hpp"

using std::cout;
using std::endl;

PmergeMe::PmergeMe(){}

PmergeMe::~PmergeMe()
{
	if (vec_.size() < 2)
		return ;
	if (vec_.size() > 18)
		deq_t = deq_t - vec_t;
	cout << "After:";
	for (std::deque<int>::iterator i = deq_.begin(); i != deq_.end(); i++)
		cout << " " << *i;
	cout << endl << "Time to process a range of " << vec_.size() << " elements with std::vector[] : " << vec_t << " ms"<< endl;
	cout << "Time to process a range of " << deq_.size() << " elements with std::deque[] : " << deq_t << " ms" << endl;
}

PmergeMe::PmergeMe(const PmergeMe& ref) : vec_(ref.vec_) , deq_(ref.deq_),
										 vec_t(ref.vec_t) ,deq_t(ref.deq_t){}

PmergeMe &PmergeMe::operator=(const PmergeMe& ref)
{
	if (this != &ref)
	{
		vec_ = ref.vec_;
		deq_ = ref.deq_;
		vec_t = ref.vec_t;
		deq_t = ref.deq_t;
	}
	return *this;
}

PmergeMe::PmergeMe(int argc, char **argv)
{
	if (argc < 3)
	{
		cout << "Error!" << endl;
		exit (1);
	}
	for (int i = 1; i < argc; i++)
	{
		int val = std::atoi(argv[i]);
		if (val < 0)
		{
			cout << "Error: negative numbers not allowed" << endl;
			exit (1);
		}
		vec_.push_back(val);
		deq_.push_back(val);
	}
	cout << "Before:";
	for (int i = 1; i < argc; i++)
		cout << " " << argv[i];
	cout << endl;
}

template <typename T>
void PmergeMe::display(const T& cont)
{
	for (typename T::const_iterator i = cont.begin(); i != cont.end(); i++)
		cout << " " <<*i;
	cout << endl;
}

void PmergeMe::mergeInsertSort_v(std::vector<int>& cont)
{
	int size = cont.size();
	if (size < 2)
		return ;
	clock_t start1 = clock();
	std::vector<int>::iterator mid = cont.begin() + size / 2;
	std::vector<int> left;
	left.reserve(std::distance(cont.begin(), mid));
	std::vector<int> right;
	right.reserve(std::distance(mid, cont.end()));
	left.assign(cont.begin(), mid);
	right.assign(mid, cont.end());
	insertSort_v(left);
	insertSort_v(right);
	merge_v(left, right, cont);

	clock_t end1 = clock();
	vec_t = static_cast<double>(end1 - start1) / CLOCKS_PER_SEC * 1000;
}

void PmergeMe::insertSort_v(std::vector<int>& cont)
{
	for (std::vector<int>::iterator it = cont.begin(); it != cont.end(); it++)
	{
		std::vector<int>::iterator j = it;
		while (j != cont.begin() && *(j - 1) > *j)
		{
			std::swap(*j, *(j - 1));
			j--;
		}
	}
}

void PmergeMe::merge_v(std::vector<int>& left, std::vector<int>& right, std::vector<int>& cont)
{
	std::vector<int>::iterator i = left.begin();
	std::vector<int>::iterator j = right.begin();
	std::vector<int>::iterator p = cont.begin();
	while (i != left.end() || j != right.end())
	{
		if (i == left.end())
			*p++ = *j++;
		else if(j == right.end())
			*p++ = *i++;
		else if (*i < *j)
			*p++ = *i++;
		else
			*p++ = *j++;
	}
}

std::vector<int>& PmergeMe::getVec()
{
	return this->vec_;
}

std::deque<int>& PmergeMe::getDeq()
{
	return this->deq_;
}

void PmergeMe::mergeInsertSort_d(std::deque<int>& cont)
{
	int size = cont.size();
	if (size < 2)
		return ;
	clock_t start = clock();
	std::deque<int>::iterator mid = cont.begin() + size / 2;
	std::deque<int> left(cont.begin(), mid);
	std::deque<int> right(mid, cont.end());
	insertSort_d(left);
	insertSort_d(right);
	merge_d(left, right, cont);

	clock_t end = clock();
	deq_t = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000;
}

void PmergeMe::insertSort_d(std::deque<int>& cont)
{
	for (std::deque<int>::iterator i = cont.begin(); i != cont.end(); i++)
	{
		std::deque<int>::iterator j = i;
		while (j != cont.begin() && *(j - 1) > *j)
		{
			std::swap(*j, *(j - 1));
			j--;
		}
	}
}

void PmergeMe::merge_d(std::deque<int>& left, std::deque<int>& right, std::deque<int>& cont)
{
	std::deque<int>::iterator i = left.begin();
	std::deque<int>::iterator j = right.begin();
	std::deque<int>::iterator p = cont.begin();
	while (i != left.end() || j != right.end())
	{
		if (i == left.end())
			*p++ = *j++;
		else if(j == right.end())
			*p++ = *i++;
		else if (*i < *j)
			*p++ = *i++;
		else
			*p++ = *j++;
	}
}
