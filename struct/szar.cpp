//============================================================================
// Name        : szar.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>

using namespace std;

int main() {

	typedef unsigned char U8;

	typedef struct _s1{
		unsigned int i;
		unsigned char c;
		unsigned long a;
		unsigned short e;
	} s1;

	cout<<  "s1 size is : " << sizeof(s1) ;

#pragma pack(push,1)
	typedef struct _s2{
		unsigned int i;
		unsigned char c;
		unsigned long a;
		unsigned short e;
	} s2;
#pragma pack(pop)

	cout<<  "\ns2 size is : " << sizeof(s2) ;
	cout<<  "\nsum of element is : "
			<<	"\n sizeof(unsigned int)"  <<   sizeof(unsigned int)
			<<	"\n sizeof(unsigned char)"  <<   sizeof(unsigned char)
			<<    "\n sizeof(unsigned long)  "  << sizeof(unsigned long)
			<<   "\n sizeof(unsigned short) "  <<  sizeof(unsigned short)
			;

	struct _s3{
		unsigned int i;
		unsigned char c;
		unsigned long a;
		unsigned short e;
		s1			s;
	}__attribute__((__packed__)) ;

	typedef struct _s3 s3;
	cout<<  "\ns3 size is : " << sizeof(s3) ;

	s3 packolt = {1,'A',2, 3};

	U8* buffer = (U8*) (&packolt);
	//U8* buffer = static_cast<int> (&packolt);
	cout<< "\n buffer[0] : " << *((unsigned long*) (buffer+5)) << endl ;

	//s1 sima = {11,'A',22, 33};
	s3 kibontot =  packolt ;
	cout<<  "kibontot.a : "  << kibontot.a   << endl ;

	return 0;
}
