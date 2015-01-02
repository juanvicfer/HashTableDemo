#include <iostream>
#include "MyHashTable.h"


class StringHash {
public:
    int operator()(const std::string & s){
        int result = 0;
        for( int i = 0; i < s.size(); i++){
            result = (result + s[i]) % 5381;
        }
        return result;
    }

};

int main() {

    std::cout << "MyHasTableDemo!" << std::endl;

    MyHashTable<std::string,StringHash> stringHashTable(100);

    stringHashTable.add("Foo");
    stringHashTable.add("Bar");

    std::cout << "Size : " << stringHashTable.size() << std::endl;

    if( stringHashTable.isPresent("Baz") ){
        std::cout << "Error. Baz shouldn't be present!" << std::endl;
        return -1;
    }

    if( !stringHashTable.isPresent("Bar") ){
        std::cout << "Error. Bar should be present!" << std::endl;
        return -1;
    }

    stringHashTable.remove("Bar");

    std::cout << "Size : " << stringHashTable.size() << std::endl;

    if( stringHashTable.isPresent("Bar") ){
        std::cout << "Error. Bar shouldn't be present!" << std::endl;
        return -1;
    }

    stringHashTable.remove("Foo");
    std::cout << "Size : " << stringHashTable.size() << std::endl;

    return 0;
}