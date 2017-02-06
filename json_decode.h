#ifndef JSON_DECODE_H
#define JSON_DECODE_H


// adding comments to test multiple branches, along with some basic skeleton code, and basic
// includes
#include <string>
#include <vector>
#include <sstream>
#include <utility>
#include <tuple>
class json_decode {
	public:
		
	json_decode();
	~json_decode();

	json_decode(std::string&);
	
	template <typename ...Output, typename O1>
	auto decode(std::string&) -> decltype(std::declval<O1>());

	template <typename A, typename B>
	std::string makepair_tostring(std::pair<char, char> p1) {
		std::stringstream oss;
		oss << "\"" p1.first;
		oss << "\":";
		oss << "\"" << p1.second << "\"" << ",";
		return oss.str();
	}
};

#endif
