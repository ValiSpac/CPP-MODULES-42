# include "PmergeMe.hpp"

int main(int argc, char **argv)
{
	PmergeMe vec(argc, argv);

	vec.mergeInsertSort_v(vec.getVec());
	vec.mergeInsertSort_d(vec.getDeq());
	return 0;
}
