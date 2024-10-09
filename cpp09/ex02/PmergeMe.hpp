#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <algorithm>
#include <vector>
#include <list>
#include <iostream>
#include <string>
#include <ctime>
#include <stdio.h>
#include <deque>
template<typename Container, typename ContainPair>
class PmergeMe
{
    private:
        Container _container;
        ContainPair _containerPair;
        bool _haveOdd;
        int _aloneNum;
    public:
        PmergeMe();

        ~PmergeMe();

        PmergeMe(PmergeMe<Container, ContainPair> const &rhs);

        PmergeMe<Container, ContainPair> & operator=(PmergeMe<Container, ContainPair> const &rhs);

        void setData(Container &data);

        void insertContainerToContainerPair();

        void printContainerPair();


        void sortContainerInsidePair();


        void mergeSortContainerPair();

        void merge(ContainPair &vec, int left, int mid, int right);

        void mergeSort(ContainPair &container, int left, int right);

        void clearContainer();

        void insertContainerPairToContainer();

        void binarySearchContainer();

        void printBeforeSort();

        void printContainer();

        void printAfterSort();

        void run(bool print,std::string nameContainer);

};

#endif