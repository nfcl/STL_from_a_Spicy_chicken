#include<iostream>
#include"string.h"

int main() {

	Mystd::string s1 = Mystd::string();
	Mystd::string s2 = Mystd::string();
	//构造方法测试
	std::cout << "构造方法测试" << std::endl;
	s1 = Mystd::string(10, '1');
	std::cout << s1 << std::endl;	//1111111111
	s1 = Mystd::string("123");
	s2 = Mystd::string(s1);
	std::cout << s2 << std::endl;	//123
	s2 = Mystd::string(s1, 2, 1);
	std::cout << s2 << std::endl;	//3
	s2 = Mystd::string(s1, 1);
	std::cout << s2 << std::endl;	//23
	s2 = Mystd::string("123",2);
	std::cout << s2 << std::endl;	//12
	//operator=
	std::cout << "operator=" << std::endl;
	s1 = "123";
	std::cout << s1 << std::endl;	//123
	s1 = 'a';
	std::cout << s1 << std::endl;	//a
	//at
	std::cout << "at" << std::endl;
	s1 = "12345";
	std::cout << s1.at(0) << std::endl;	//1
	std::cout << s1.at(1) << std::endl;	//2
	std::cout << s1.at(2) << std::endl;	//3
	//operator[]
	std::cout << "operator[]" << std::endl;
	s1 = "12345";
	std::cout << s1[0] << std::endl;	//1
	std::cout << s1[1] << std::endl;	//2
	std::cout << s1[2] << std::endl;	//3
	s1[0] = 'a';
	s1[1] = 'b';
	s1[2] = 'c';
	std::cout << s1<< std::endl;		//abc45
	//front
	std::cout << "front" << std::endl;
	s1 = "12345";
	std::cout << s1.front() << std::endl;	//1
	s1.front() = 'a';
	std::cout << s1.front() << std::endl;	//a
	//back
	std::cout << "back" << std::endl;
	s1 = "12345";
	std::cout << s1.back() << std::endl;	//5
	s1.back() = 'e';
	std::cout << s1.back() << std::endl;	//e
	//c_str
	std::cout << "c_str" << std::endl;
	s1 = "123";
	std::cout << s1.c_str() << std::endl;	//123
	//empty
	std::cout << "empty" << std::endl;
	s1 = "1234";
	std::cout << s1.empty() << std::endl;	//0
	s1 = "";
	std::cout << s1.empty() << std::endl;	//1
	//size|length
	std::cout << "size|length" << std::endl;
	s1 = { "123abc" };
	std::cout << s1.size() << std::endl;	//6
	std::cout << s1.length() << std::endl;	//6
	s1[3] = '\0';	
	std::cout << s1.size() << std::endl;	//3
	std::cout << s1.length() << std::endl;	//3
	s1[0] = '\0';
	std::cout << s1.size() << std::endl;	//0
	std::cout << s1.length() << std::endl;	//0
	//capacity
	std::cout << "capacity" << std::endl;
	s1 = "123";
	std::cout << s1.capacity() << std::endl;	//3
	s1 += "111111111111111111111111111";
	std::cout << s1.capacity() << std::endl;	//48
	//reserve
	std::cout << "reserve" << std::endl;
	s1 = "123";
	std::cout << s1.capacity() << std::endl;	//3
	s1.reserve(100);
	std::cout << s1.capacity() << std::endl;	//100
	s1.reserve(1);
	std::cout << s1.capacity() << std::endl;	//3
	s1.reserve(5);
	std::cout << s1.capacity() << std::endl;	//5
	//shrink_to_fit
	std::cout << "shrink_to_fit" << std::endl;
	s1 = "123";
	std::cout << s1.capacity() << std::endl;	//3
	s1.reserve(100);
	std::cout << s1.capacity() << std::endl;	//100
	s1.shrink_to_fit();
	std::cout << s1.capacity() << std::endl;	//3
	//clear
	std::cout << "clear" << std::endl;
	s1 = "123";
	std::cout << s1 << std::endl;				//123
	s1.clear();
	std::cout << s1 << std::endl;				//
	std::cout << s1.size() << std::endl;		//0
	std::cout << s1.capacity() << std::endl;	//3
	//insert
	std::cout << "insert" << std::endl;
	s1 = "123";
	std::cout << s1 << std::endl;				//123
	s1.insert(0, 5, 'a');
	std::cout << s1 << std::endl;				//aaaaa123
	s1.insert(3, "123");	
	std::cout << s1 << std::endl;				//aaa123aa123
	s1.insert(3, "abc\0abc", 5);
	std::cout << s1 << std::endl;				//aaaabc\0a123aa123
	s1[6] = 'e';
	std::cout << s1 << std::endl;				//aaaabcea123aa123
	s1 = "123";
	s2 = "456";
	s1.insert(1, s2, 1);						
	std::cout << s1 << std::endl;				//14523
	//erase
	std::cout << "erase" << std::endl;
	s1 = "123456789";
	std::cout << s1 << std::endl;				//123456789
	s1.erase(2, 5);
	std::cout << s1 << std::endl;				//1289
	s1.erase(2);
	std::cout << s1 << std::endl;				//129
	//push_back
	std::cout << "push_back" << std::endl;
	s1 = "123456";
	std::cout << s1 << std::endl;				//123456
	s1.push_back('a');
	std::cout << s1 << std::endl;				//123456a
	s1.push_back('b');
	std::cout << s1 << std::endl;				//123456ab
	s1.push_back('c');
	std::cout << s1 << std::endl;				//123456abc
	//pop_back
	std::cout << "pop_back" << std::endl;
	s1 = "123456";
	std::cout << s1 << std::endl;				//123456
	s1.pop_back();
	std::cout << s1 << std::endl;				//12345
	s1.pop_back();
	std::cout << s1 << std::endl;				//1234
	s1.pop_back();
	std::cout << s1 << std::endl;				//123
	//append
	std::cout << "append" << std::endl;
	s1 = "1";
	std::cout << s1 << std::endl;				//1
	s1.append(5, 'a');
	std::cout << s1 << std::endl;				//1aaaaa
	s2 = "321";
	s1.append(s2);
	std::cout << s1 << std::endl;				//1aaaaa321
	s1.append("1\0ba", 3);
	std::cout << s1 << std::endl;				//1aaaaa3211
	s1[10] = 'c';
	std::cout << s1 << std::endl;				//1aaaaa3211cb
	s1.append("123");
	std::cout << s1 << std::endl;				//1aaaaa3211cb123
	//operator+=
	std::cout << "operator+=" << std::endl;
	s1 = "123";
	std::cout << s1 << std::endl;				//123
	s2 = "456";
	std::cout << s2 << std::endl;				//456
	s1 += s2;
	std::cout << s1 << std::endl;				//123456
	s2 += s2;
	std::cout << s2 << std::endl;				//456456
	s1 += "abc";
	std::cout << s1 << std::endl;				//123456abc
	s1 += '#';
	std::cout << s1 << std::endl;				//123456abc#
	//compare
	std::cout << "compare" << std::endl;
	s1 = "123";
	s2 = "012";
	std::cout << s1.compare(s2) << std::endl;	//1
	s1 = "123";
	s2 = "1234";
	std::cout << s1.compare(s2) << std::endl;	//-1
	s1 = "123";
	s2 = "123";
	std::cout << s1.compare(s2) << std::endl;	//0
	s1 = "3123";
	s2 = "123";
	std::cout << s1.compare(1, 3, s2) << std::endl;	//0
	s1 = "3123";
	s2 = "321123";
	std::cout << s1.compare(1, 3, s2, 3, 3) << std::endl;	//0
	s1 = "123";
	std::cout << s1.compare("321") << std::endl;	//-1
	s1 = "3123";
	std::cout << s1.compare(1, 3, "123") << std::endl;	//0
	s1 = "3123";
	std::cout << s1.compare(1, 3, "123\0a", 4) << std::endl;	//-1
	//replace
	std::cout << "replace" << std::endl;
	s1 = "123";
	s2 = "456";
	s1.replace(1, 1, s2);
	std::cout << s1 << std::endl;	//14563
	s1 = "123";
	s2 = "456";
	s1.replace(1, 1, s2, 1, 2);
	std::cout << s1 << std::endl;	//1563
	s1 = "123";
	s1.replace(1, 1, "456", 2);
	std::cout << s1 << std::endl;	//1453
	s1 = "123";
	s1.replace(1, 1, "45\0ab", 5);
	std::cout << s1 << std::endl;	//145
	s1[3] = 'e';
	std::cout << s1 << std::endl;	//145eab3
	s1 = "123";
	s1.replace(1, 1, "45ab");
	std::cout << s1 << std::endl;	//145ab3
	s1 = "123";
	s1.replace(1, 1, 5, 'a');
	std::cout << s1 << std::endl;	//1aaaaa3
	//substr
	std::cout << "substr" << std::endl;
	s1 = "123456789";
	s2 = s1.substr(1, 2);
	std::cout << s2 << std::endl;	//23
	s2 = s1.substr(3);
	std::cout << s2 << std::endl;	//456789
	//copy
	std::cout << "copy" << std::endl;
	s1 = "123456789";
	char buf[4] = { '\0' };
	s1.copy(buf, 0, 3);
	std::cout << buf << std::endl;	//123
	s1.copy(buf, 3, 3);
	std::cout << buf << std::endl;	//456
	//resize
	std::cout << "resize" << std::endl;
	s1 = "123";
	s1.resize(10, '1');
	std::cout << s1 << std::endl;				//1111111111
	std::cout << s1.size() << std::endl;		//10
	std::cout << s1.capacity() << std::endl;	//12
	s1.resize(5, 'a');
	std::cout << s1 << std::endl;				//aaaaa
	std::cout << s1.size() << std::endl;		//5
	std::cout << s1.capacity() << std::endl;	//12
	//swap
	std::cout << "swap" << std::endl;
	s1 = "123";
	s2 = "456";
	s1.swap(s2);
	std::cout << s1 << std::endl;	//456
	std::cout << s2 << std::endl;	//123
	s1 = "123";
	s2 = "";
	s1.swap(s2);
	std::cout << s1 << std::endl;	//
	std::cout << s2 << std::endl;	//123
	s1 = "123";
	s2 = "4567";
	s1.swap(s2);
	std::cout << s1 << std::endl;	//4567
	std::cout << s2 << std::endl;	//123
	s1 = "";
	s2 = "";
	s1.swap(s2);
	std::cout << s1 << std::endl;	//
	std::cout << s2 << std::endl;	//

	std::swap(s1, s2);
	//operator<<  operator>>
	//std::cout << "operator<<  operator>>" << std::endl;
	//std::cout << "请输入s1 : ";
	//std::cin >> s1;
	//std::cout << "s1 : " << s1 << std::endl;
}