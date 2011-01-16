//============================================================================
// Name        : szar.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>

using namespace std;

typedef unsigned char U8;
typedef unsigned short U16;
typedef unsigned int  U32;

typedef struct _s1{
	U8 ch;
	U16 si;
	U32 ii;
} s1;


#pragma pack(push,1)
typedef struct _s2{
	U8 ch;
	U16 si;
	U32 ii;
} s2;
#pragma pack(pop)


typedef struct __attribute__((__packed__)) _s3{
	U8 ch;
	U16 si;
	U32 ii;
	s1	s[1];
}s3;


//__attribute__((__packed__)) ;

int main() {


	cout<<  "s1 size is : " << sizeof(s1) ;
	cout<<  "\ns2 size is : " << sizeof(s2) ;



	//typedef struct _s3 s3;
	cout<<  "\ns3 size is : " << sizeof(s3) ;

	s1 extra={'C',6,7};
	s3 packolt = {'A',2, 3,{{'B',4,5}}};

	U8* buffer = (U8*) (&packolt);
	//U8* buffer = static_cast<int> (&packolt);
	cout<< "\n buffer[0] : " << *((unsigned long*) (buffer+5)) << endl ;


	s3 kibontot =  packolt ;
	cout<<  "kibontot. : "  << kibontot.si   << endl ;



	return 0;
}



void junk(){

	/*	cout<<  "\nsum of element is : "
				<<	"\n sizeof(U8 ) : "  <<     sizeof(U8 )
				<<	"\n sizeof(U16) : "  <<     sizeof(U16)
				<<  "\n sizeof(U32) : "  <<     sizeof(U32)
				;*/

	/*********/

	/*	#pragma bitfield_packing on
	struct {
		U8 id : 8;
		U16 chan : 16;
		U32 freq : 32;
	} tx;

	cout<<  "tx size : "  << sizeof(tx)  << endl ;*/
}
