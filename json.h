#ifndef JSON_H
#define JSON_H
#include <string>
#include <fstream>
#include "json_decode.h"
#include "json_encode.h"
// { 
// 	"type":"value",
// 	"array": ["a", "b", "c", "d", "e"] 
// }

class json {
	std::string object;
	const char* filename;
	json(std::string obj, const char* fname) : object(obj), filename(fname) {
		
	}
	~json() {
	
	}
	
	void read() {
	}
	void write() {
	}
};


#endif
