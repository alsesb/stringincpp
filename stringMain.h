#ifndef STRING
#define STRING

class String{
	char *string;
public:
	String(const char * = "");
	~String();
	String(const String&);
	String(String&&);
	String& operator= (const String&);
	String& operator= (String&&);
	operator const char*() const;
	friend String operator+ (const String &l, const String &r);
	String& operator+= (const String &r);
	friend bool operator== (const String &l, const String &r);
	char& operator[](int);
	String operator()(int, int) const;
	static int strlen(const char *str);
	static void strcpy(char *, const char*);
	static void strcat(char *, const char*);
	static bool strcmp(const char*, const char*);
	void print();
};

#endif
