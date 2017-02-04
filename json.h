#ifndef JSON_H
#define JSON_H
#include <string>
#include <fstream>
#include <cstddef>
#include <utility>
#include <memory>
#include <type_traits>
#include <typeinfo>
// { 
// 	"type":"value",
// 	"array": ["a", "b", "c", "d", "e"] 
// }
namespace json {

#define offsetof_impl(type,member) ((std::size_t) &(((type*)0)->member))

enum json_type {
	OBJECT,
	ARRAY,
	STRING
};

const char json_element_typetable[] = {
	
};


// json_element("hello", 10) 
// => call constructor
// json_element(const char* name, Value v) => json_element("hello", 10)
// A for anonymous object 
// element A1: 
// {
//	"hello" : 10
// }
//
// json_element(json_element(null))

template <typename ...Value>
struct json_element {
	json_type type;
	const char* name;
	// compile time checker-magic?
	Value value;
	json_element(const char* n, Value v) : name(n), value{v} {
		if(n == nullptr) // object is of type array
		{

		}	
	}
	

	~json_element( ) {
		// cleanup
		if(name != nullptr) delete name;
			if(std::is_pointer<Value>::value && value != nullptr) {
				if(std::is_array<Value>::value) delete[] value;
				else delete value;
			}
	}


};




class json {
	std::string object;
	const char* filename;
	json(std::string obj, const char* fname) : object(obj), filename(fname) {
		
	}
	~json() {
	
	}
	
	void read(const char* fromfile) {
		std::ifstream{fromfile};
		json_decode{}
	}
	void write() {
	}
};

void do_something(const char* some_param) {
		printf("Well this is awkward.. %d", static_cast<int>(sizeof(some_param)));
	}
}

#endif
