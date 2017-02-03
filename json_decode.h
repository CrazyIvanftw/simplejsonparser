#ifndef JSON_DECODE_H
#define JSON_DECODE_H


// adding comments to test multiple branches, along with some basic skeleton code, and basic
// includes
#include <string>
#include <vector>
#include <utility>
class json_decode {
	public:
		
	json_decode();
	~json_decode();

	json_decode(std::string&);
	
	template <typename ...Output, typename O1>
	auto decode(std::string&) -> decltype(std::declval<O1>());

};

#endif
