#include "stringMain.h"
#include <iostream>

// DECLARING SOME BASIC STRING FUNCTIONS

int String::strlen(const char *str){
	const char *ptr = str;
	while(*ptr++){};
	return ptr-str;
};

void String::strcpy(char * l, const char *r){
	char *lstart = l;
	const char *rstart = r;
	while(*lstart++ = *rstart++);
};

void String::print(){
	std::cout << string << std::endl;
};

bool String::strcmp(const char *l, const char *r){
	while(*l && *l++ == *r++);
	return *l-*r;
};

// CORE FUNCTIONS AND CONSTRUCTORS

String::String(const char *str) : string{new char[String::strlen(str)+1]}{
	String::strcpy(string, str);
};

String::String(const String& n) : string{new char[String::strlen(n.string)+1]}{
	String::strcpy(string, n.string);
};

String::String(String&& n) : string{n.string}{
	n.string = nullptr;
};

String& String::operator= (const String& n){
	String tmp{n};
	delete [] string;
	char *temp = string;
	string = tmp.string;
	tmp.string = temp;
	return *this;
};

String& String::operator= (String && n){
	delete [] string;
	string = n.string;
	n.string = nullptr;
	return *this;
};

// OVERLOADED FUNCTIONS

String::operator const char*() const{
	return string;	
};

String operator+ (const String &l, const String &r){
	int len = String::strlen(l.string) + String::strlen(r.string);
	char *word{new char[len-1]};
	String::strcpy(word, l.string);
	String::strcpy((word + String::strlen(word) - 1), r.string);
	String newline{word};
	delete [] word;
	return newline;
};

String& String::operator+= (const String &n){
	String tmp = operator+(*this, n);
	string = tmp.string;
	tmp.string = nullptr;
	return *this;
};

bool operator== (const String &l, const String &r){
	if (String::strcmp(l.string, r.string)){
		return false;
	}
	return true;
};

char& String::operator[](int index){
	return string[index];
}

String String::operator()(int s, int e) const{
	char *subs = new char[e+1];
	for(s; s<e; s++){
		subs[s] = string[s];
	};
	subs[s] = '\0';
	String substring{subs};
	delete [] subs;
	return substring;
};

// DESTRUCTOR

String::~String(){delete [] string;};
