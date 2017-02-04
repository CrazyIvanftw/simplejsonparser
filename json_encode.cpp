#include "json_encode.h"
#include "json.h"
#include <sstream>
json::json_encode::json_encode() {

}




template <typename JSON>
auto json::json_encode::encode(JSON& json) -> std::string {
	std::stringstream ss{"Bitch:makemeasandwich"};
	do_something(ss.str().c_str());
}


