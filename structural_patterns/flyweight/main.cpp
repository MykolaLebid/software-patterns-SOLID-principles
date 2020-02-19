#include <string>
#include <map>
#include <vector>
#include <iostream>

typedef uint32_t key;

struct User{
	User(const std::string& first_name, const std::string& second_name)
		: first{add(first_name)}, second{add(second_name)} {}
protected:
key first, second;		
static std::map<std::string, key> str_to_key_map;
static std::map<key, std::string> key_to_str_map;
static key gen;
static key add(const std::string & s){
	auto [it, b] = str_to_key_map.try_emplace(s, ++gen);	
	if (b) key_to_str_map.try_emplace(gen, s); 
	return it->second;
}
const std::string& get_first_name() const{ 
 return key_to_str_map[first];}	

const std::string& get_second_name() const{
 return key_to_str_map[second];}

friend std::ostream& operator<<(std::ostream & os, User& user){
	return os <<
		"first name:" << user.get_first_name() <<
		"second name" << user.get_second_name();

}
};

std::map<std::string,key> User::str_to_key_map;
std::map<key,std::string> User::key_to_str_map;
key User::gen = 0;

int main(){
	std::vector<User> users{ User("Semon", "Good"),
				 User("Mike", "Good"),
				 User("Swan","Mike")};
	std::cout<< users[0] << std::endl;	
	return 0;
};
