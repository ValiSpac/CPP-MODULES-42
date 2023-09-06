# pragma once

# include <iostream>
# include <algorithm>
# include <vector>
# include <deque>
# include <sys/time.h>

class PmergeMe
{
	private:
		std::vector<int> vec_;
		std::deque<int> deq_;
		double vec_t;
		double deq_t;
	public:
		PmergeMe();
		PmergeMe(int argc, char **argv);
		PmergeMe(const PmergeMe& ref);
		PmergeMe &operator=(const PmergeMe& ref);
		~PmergeMe();
		template <typename T>
		void display(const T& cont);
		void mergeInsertSort_v(std::vector<int>& cont);
		void insertSort_v(std::vector<int>& cont);
		void merge_v(std::vector<int>& left, std::vector<int>& right, std::vector<int>& cont);
		std::vector<int>& getVec();
		void mergeInsertSort_d(std::deque<int>& cont);
		void insertSort_d(std::deque<int>& cont);
		void merge_d(std::deque<int>& left, std::deque<int>& right, std::deque<int>& cont);
		std::deque<int>& getDeq();
};
