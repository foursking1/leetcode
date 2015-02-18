#include <iostream>
#include <vector>
#include <list>

using namespace std;

struct data {
	int key;
	int value;
	int time;
};

class LRUCache{
public:

	list<data> li;
	int capacity;

    LRUCache(int capacity) {
    	this->capacity = capacity;
    }
    
    int get(int key) {
    	int returnValue = 0;

        for(list<data>::iterator it = this->li.begin(); it != this->li.end(); it++){
        	if(it->key == key){
        		returnValue = it->value;
        		it->time = 1;
        	} else {
        		it->time += 1;
        	}
        }
        return returnValue;
    }
    
    void set(int key, int value) {
    	int max = 0;
    	list<data>::iterator pos;
    	bool found = 0;
    	for(list<data>::iterator it = this->li.begin(); it != this->li.end(); it++)
    	{
        	if(it->key == key){
        		it->value = value;
        		it->time = 1;
        		found = 1;
        	} else {
        		it->time += 1;
        	}   	

        	if(it->time > max) {
        		max = it->time;
        		pos = it;
        	}	
    	}

    	if( !found && this->li.size() == this->capacity ){
    		pos->key = key;
    		pos->value = value;
    		pos->time = 1;
    	} else {
    		data *d = new data();
    		d->key = key;
    		d->value = value;
    		d->time = 1;
    		(this->li).push_back(*d);
    	}


    }
};

install_name_tool -change /usr/local/lib/libosxfuse_i64.2.dylib @executable_path/libosxfuse_i64.2.dylib "/usr/local/bin/sshfs"


int main(int argc, char const *argv[])
{
	LRUCache cache = LRUCache(2);
	cache.set(1,2);
	cache.set(2,3);
	cout<<cache.get(1);
	cache.set(3,1);
	cout<<cache.get(1);
	
	return 0;
}