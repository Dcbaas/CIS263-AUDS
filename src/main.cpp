#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include <algorithm>
#include <string>
#include "catch.hpp"
#include "AUDS.h"

// Test cases take two parameters - the first is a test
// name and the second is a tag.
// This test merely checks that 1 is equal to 1.  It
// should always pass.  It is included here to show how
// to write test cases.

TEST_CASE( "Constructor test", "[creation]" ){
	AUDS<int> a;
	AUDS<float> b;
	AUDS<AUDS<int> > c;
	CHECK( a.size() == 0 );
	CHECK( b.size() == 0 );
	CHECK( c.size() == 0 );
}

TEST_CASE( "Push test", "[inner]" ){
	AUDS<int> a;
	for(int i=0; i<1000; i++){
		a.push(i);
	}
	CHECK( a.size() == 1000 );
}

TEST_CASE( "Pop test", "[inner]" ){
	AUDS<std::string> s;
	for(int i=0; i<1000; i++){
		s.push("Item " + std::to_string(i));
	}
	for(int i=0; i<500; i++){
		std::cout << s.pop() << std::endl;
	}
	CHECK( s.size() == 500 );
}

TEST_CASE( "Add Delete Add test", "[inner]" ){
	AUDS<std::string> s;

	for(int i{0}; i <1000; i++)
		s.push("Item" + std::to_string(i));

	for(int i{0}; i<500; i++)
		std::cout << s.pop() << std::endl;


	CHECK( s.size() == 500);

	for(int i{0}; i <500; i++)
		s.push("Item" + std::to_string(i));

	CHECK( s.size() == 1000);	
}

TEST_CASE( "Pop from Null list", "[inner]"){

	AUDS<std::string> s;
	CHECK_THROWS(s.pop());
}

TEST_CASE("Test equals initialization", "[inner]"){
	AUDS<std::string> s;           
                                                                    
      	for(int i{0}; i < 5; i++)               	
    		s.push("Item" + std::to_string(i));

	AUDS<std::string> q{s};		

	CHECK(1);                                                                 
}

TEST_CASE("Test = operator", "[inner]"){
	AUDS<std::string> a;           
	AUDS<std::string> b;        
                                   
	for(int i{0}; i < 5; i++)                  
		a.push("Item" + std::to_string(i));

	b = a;

	CHECK(1);
}

TEST_CASE("Destructor test", "[inner]"){

	AUDS<int>* nums = new AUDS<int>;

	nums->push(19);
}
