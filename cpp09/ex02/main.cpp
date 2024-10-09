#include <cstdlib>
#include <iostream>
#include "PmergeMe.hpp"
#include <vector>
#include <deque>
#include <utility>
#include <string>
#include <ctime>
#include <limits>

int main(int argc,char **argv)
{
    (void)argc;
    (void)argv;

    int i = 0;
    std::vector<int> vec;
    std::deque<int> deq;
    for(i = 1; i < argc; i++)
    {
        std::string arg = argv[i];
		if (arg.empty()) {
			throw (std::invalid_argument("Wrong Argument has no digit"));
		}
		for (size_t j = 0; j < arg.length(); j++) {
			if (!std::isdigit(arg[j])) {
				throw (std::invalid_argument("Wrong Argument has no digit"));	
			}
		}
		long n = std::atol(argv[i]);
		if (n > std::numeric_limits<int>::max()) {
			throw (std::invalid_argument("Wrong Argument found overflow"));
		}
        vec.push_back(n);
        deq.push_back(n);
    }
    // std::string mocArgv[argc] = argv;
    // return 0;
    // std::string mocArgv[100] = {"9", "8", "2", "1", "3", "5", "4", "10", "12","6","1"};
    // // std::vector<int> vec;
    // // std::deque<int> deque;
    // // int mockArgc = 100;
    // int count = 0;
    // while (mocArgv[count] != "") {
    //     count++;
    // }

    // // std::cout << count << std::endl;
    // for (int i = 0; i < count; i++){
    //     // std::cout << mocArgv[i] << std::endl;
    //     vec.push_back(std::atoi(mocArgv[i].c_str()));
    //     deque.push_back(std::atoi(mocArgv[i].c_str()));
    // }

    // PmergeMe<std::vector<int>, std::vector<std::pair<int,int> > > test2;

    // PmergeMe<std::deque<int>, std::deque<std::pair<int,int> > > test;
    
    // test.setData(deque);
    // std::clock_t start = std::clock();
    // test.insertContainerToContainerPair();
    // test.sortContainerInsidePair();
    // // test.printContainerPair();
    // // std::cout << "-----------------------------" << std::endl;
    // test.mergeSortContainerPair();
    // test.clearContainer();
    // test.insertContainerPairToContainer();
    // test.printContainer();
    // std::cout << "-----------------------------" << std::endl;
    // test.binarySearchContainer();
    // std::clock_t end = std::clock();
    // std::cout << 1000.0 * (end - start) / CLOCKS_PER_SEC << std::endl;
    // std::cout << "-----------------------------" << std::endl;
    // test.printContainer();
    // std::cout << "-----------------------------" << std::endl;
    // // test2.setData(list);
    // std::cout << "--------------test2---------------" << std::endl;
    // test2.setData(vec);
    // start = std::clock();
    // test2.insertContainerToContainerPair();
    // test2.sortContainerInsidePair();
    // // test.printContainerPair();
    // // std::cout << "-----------------------------" << std::endl;
    // test2.mergeSortContainerPair();
    // // test.printContainerPair();
    // // std::cout << "-----------------------------" << std::endl;
    // test2.clearContainer();
    // test2.insertContainerPairToContainer();
    // test2.printContainer();
    // std::cout << "-----------------------------" << std::endl;
    // test2.binarySearchContainer();
    // end = std::clock();
    // std::cout << 1000.0 * (end - start) / CLOCKS_PER_SEC << std::endl;
    // std::cout << "-----------------------------" << std::endl;
    // test2.printContainer();
    // std::cout << "-----------------------------" << std::endl;

    PmergeMe<std::vector<int>,std::vector<std::pair<int,int> > > pmergeMeVector;

    PmergeMe<std::deque<int>, std::deque<std::pair<int,int> > > pmergeMeDeque;

    pmergeMeVector.setData(vec);
    pmergeMeVector.printBeforeSort();
    pmergeMeVector.run(true, "vector");
    pmergeMeDeque.setData(deq);
    pmergeMeDeque.run(false, "deque");


    // test.sortContainer();
    // test.printOutput();
}