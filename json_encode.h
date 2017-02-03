#ifndef JSON_ENCODE_H
#define JSON_ENCODE_H
// adding comments for json_encode branch test, and building class skeleton
#include <string>
class json_encode {
	public:
	json_encode();
	json_encode(json_encode&);
	json_encode& operator=(json_encode&);
	
	~json_encode();

	template <typename JSON>
	auto encode(JSON& j) -> std::string;

};

#endif
