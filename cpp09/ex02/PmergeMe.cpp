#include "PmergeMe.hpp"
template<typename Container, typename ContainPair>
PmergeMe<Container, ContainPair>::PmergeMe(){
    _haveOdd = false;
};

template<typename Container, typename ContainPair>
PmergeMe<Container, ContainPair>::~PmergeMe(){

};

template<typename Container, typename ContainPair>
void PmergeMe<Container,ContainPair>::setData(Container &data){
    _container = data;
}

template<typename Container, typename ContainPair>
PmergeMe<Container, ContainPair>::PmergeMe(PmergeMe<Container, ContainPair> const &rhs)
{
	*this = rhs;
}

template<typename Container, typename ContainerPair>
PmergeMe<Container, ContainerPair> & PmergeMe<Container, ContainerPair>::operator=(PmergeMe<Container, ContainerPair> const &rhs)
{
	if (this != &rhs) {
		_container.clear();
        _containerPair.clear();
        _container = rhs._container;
        _containerPair = rhs._containerPair;
        _haveOdd = rhs._haveOdd;
        _aloneNum = rhs._aloneNum;
	}
	return (*this);
}

template<typename Container, typename ContainPair>
void PmergeMe<Container,ContainPair>::insertContainerToContainerPair(){
    // Iterator it;
    std::pair<int, int> pairValue;
    typename Container::iterator it;
    // std::cout << _container.size() << std::endl;
    if(_container.size() % 2 == 1)
        _haveOdd = true;

    for(it = _container.begin(); it != _container.end(); it++){
        pairValue.first = *it;
        if(it++ + 1 == _container.end())
        {
            _aloneNum = pairValue.first;
            break;
        }        
        pairValue.second = *it;
        _containerPair.push_back(pairValue);
    }
    // _containerPair.push_back(pairValue);
}

template<typename Container, typename ContainPair>
void PmergeMe<Container,ContainPair>::printContainerPair(){
    typename ContainPair::iterator it = _containerPair.begin();
    while(it != _containerPair.end())
    {
        std::cout << it->first << std::endl;
        std::cout << it->second << std::endl;
        it++;
    }
}

template<typename Container, typename ContainPair>
void PmergeMe<Container,ContainPair>::sortContainerInsidePair(){
    typename ContainPair::iterator it = _containerPair.begin();
    std::pair<int, int> pairValue;
    while(it != _containerPair.end())
    {
        if(it->first > it->second)
        {
            int tmp = it->second;
            it->second = it->first;
            it->first = tmp;
        }
        it++;
    }
}

template<typename Container, typename ContainPair>
void PmergeMe<Container,ContainPair>::mergeSortContainerPair(){

    mergeSort(_containerPair, 0, _containerPair.size() - 1);
    
}

template<typename Container, typename ContainPair>
void PmergeMe<Container,ContainPair>::merge(ContainPair &vec, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    ContainPair leftVec(n1);
    ContainPair rightVec(n2);

    for (int i = 0; i < n1; ++i) {
        leftVec[i] = vec[left + i];
    }
    for (int i = 0; i < n2; ++i) {
        rightVec[i] = vec[mid + 1 + i];
    }

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (leftVec[i].first <= rightVec[j].first) {
            vec[k] = leftVec[i];
            ++i;
        } else {
            vec[k] = rightVec[j];
            ++j;
        }
        ++k;
    }

    while (i < n1) {
        vec[k] = leftVec[i];
        ++i;
        ++k;
    }

    while (j < n2) {
        vec[k] = rightVec[j];
        ++j;
        ++k;
    }
}

template<typename Container, typename ContainPair>
void PmergeMe<Container,ContainPair>::mergeSort(ContainPair &container, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(container, left, mid);
        mergeSort(container, mid + 1, right);
        merge(container, left, mid, right);
    }
}

template<typename Container, typename ContainPair>
void PmergeMe<Container,ContainPair>::clearContainer(){
    _container.clear();
}

template<typename Container, typename ContainPair>
void PmergeMe<Container,ContainPair>::insertContainerPairToContainer(){
    typename ContainPair::iterator it = _containerPair.begin();
    while(it != _containerPair.end())
    {
        _container.push_back(it->first);
        it++;
    }    
}

template<typename Container, typename ContainPair>
void PmergeMe<Container,ContainPair>::binarySearchContainer(){
    typename ContainPair::iterator it = _containerPair.begin();
    
    while(it != _containerPair.end())
    {
        typename Container::iterator position = std::lower_bound(_container.begin(), _container.end(), it->second);
        _container.insert(position, it->second);
        it++;
    }

    if(_haveOdd)
    {
        typename Container::iterator position = std::lower_bound(_container.begin(), _container.end(), _aloneNum);
        _container.insert(position, _aloneNum);
    }
}

template<typename Container, typename ContainPair>
void PmergeMe<Container,ContainPair>::printBeforeSort(){
    std::cout << "Before:  ";
    printContainer();
}

template<typename Container, typename ContainPair>
void PmergeMe<Container,ContainPair>::printContainer(){
    typename Container::iterator it = _container.begin();
    while(it != _container.end())
    {
        std::cout << *it << " " ;
        it++;
    }
    std::cout << std::endl;
}

template<typename Container, typename ContainPair>
void PmergeMe<Container,ContainPair>::printAfterSort(){
    std::cout << "After:   ";
    printContainer();
}

template<typename Container, typename ContainPair>
void PmergeMe<Container,ContainPair>::run(bool print,std::string nameContainer){
    std::clock_t start = std::clock();
    insertContainerToContainerPair();
    sortContainerInsidePair();
    mergeSortContainerPair();
    clearContainer();
    insertContainerPairToContainer();
    binarySearchContainer();
    std::clock_t end = std::clock();
    if(print)
        printAfterSort();
    std::cout << "Time to process a range of "<< _container.size() <<" elements with std::<<"<< nameContainer <<" : ";
    std::cout << 1000.0 * (end - start) / CLOCKS_PER_SEC  << " ms"<< std::endl;

}


template class PmergeMe<std::deque<int>, std::deque<std::pair<int,int> > > ;
template class PmergeMe<std::vector<int>,std::vector<std::pair<int,int> > > ;