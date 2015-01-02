
#ifndef MYHASHTABLE_H
#define MYHASHTABLE_H


#include <vector>
#include <list>
#include <algorithm>

/**
* Easy implementation of a Generic hash table, for education purposes.
* It uses lists to solve collisions and receives the size ( number of hash buckets ).
* The Hash function should be a functor, specified as a template parameter.
*/
template <typename T, class HashFunction>
class MyHashTable {
private:

    typedef typename std::list<T>::iterator CollisionListIterator;
    typedef typename std::list<T> CollisionList;

    std::vector< std::list<T> > elementLists_;
    HashFunction hashFunction_;

public:

    MyHashTable(int buckets){
        elementLists_.resize(buckets);
    }

    void add(const T& element){
        int bucket = hashFunction_(element) % elementLists_.size();
        elementLists_[bucket].push_back(element);
    };

    bool isPresent(const T& element){
        int bucket = hashFunction_(element) % elementLists_.size();
        CollisionListIterator it = std::find(elementLists_[bucket].begin(),elementLists_[bucket].end(),element);
        return it != elementLists_[bucket].end();
    }

    void remove(const T& element){
        int bucket = hashFunction_(element) % elementLists_.size();
        elementLists_[bucket].remove(element);
    }

    int size(){

        class ListSizeReturner {
        public:
            int operator()(int prevSize, const CollisionList & l){
                return prevSize + l.size();
            }
        };

        return std::accumulate(elementLists_.begin(), elementLists_.end(), 0, ListSizeReturner());
    }

};

#endif