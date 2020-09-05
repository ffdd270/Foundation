#define CATCH_CONFIG_MAIN
#include <catch.hpp>
#include "LinkedList.h"

template <typename T >
inline void easy_search_test(  LinkedList<T> & ref_list, T find_data )
{
	auto * data = ref_list.search( find_data );
	REQUIRE( data != nullptr );
	REQUIRE( data->data == find_data );
}


template <typename T >
inline void easy_search_failed_test(  LinkedList<T> & ref_list, T find_data )
{
	auto * data = ref_list.search( find_data );
	REQUIRE( data == nullptr );
}


template <typename T>
inline void easy_remove_test( LinkedList<T> & ref_list, T remove_data )
{
	auto * data = ref_list.search( remove_data );
	REQUIRE( data != nullptr );

	ref_list.remove( data );
	REQUIRE( data == nullptr );
}

TEST_CASE( "Linked List", "[data structure]" )
{

	SECTION("insert")
	{
		SECTION("test insert")
		{
			LinkedList<int> list;

			list.push_back( 2 );
			list.push_back( 3 );

			easy_search_test( list, 2 );
			easy_search_test( list, 3 );
		}
	}


	SECTION("search")
	{
		SECTION("test basic search")
		{
			LinkedList<int> list;

			for( int i = 0; i < 10000; i++ )
			{
				list.push_back( i );
			}

			easy_search_failed_test( list, 10000 );
			easy_search_test( list, 1000 );
		}

		SECTION("string search")
		{
			LinkedList<std::string> string_list;

			string_list.push_back("Helo, World!");
			string_list.push_back("World!");
			string_list.push_back("Hero~!");

			Node<std::string> * data = string_list.search( "World!" );
			REQUIRE( data != nullptr  );
			REQUIRE( data->data == "World!" );

			data = string_list.search( "Hello, World!" );
			REQUIRE( data == nullptr );

		}
	}

	SECTION("remove")
	{
		SECTION("basic remove")
		{
			LinkedList<int> list;


			list.push_back( 30 );
			list.push_back( 50 );
			list.push_back( 60 );

			easy_remove_test( list, 50 );

			int * a = new int(30);
			REQUIRE( a == nullptr );
		}
	}


	SECTION("size")
	{
		SECTION("size")
		{
			LinkedList<int> list;

			REQUIRE( list.size() == 0 );

			list.push_back( 30 );
			list.push_back( 50 );
			list.push_back( 60 );

			REQUIRE( list.size() == 3 );
		}
	}

	SECTION("show")
	{
		LinkedList<int> list;

		std::cout << list << std::endl;

		list.push_back( 30 );
		list.push_back( 50 );

		std::cout << list << std::endl;
	}

	SECTION("add")
	{
		LinkedList<int> list = { 1, 2, 3 };
		LinkedList<int> list2 = { 4, 5, 6 };

		list += list2;

		for ( int i = 1; i <= 6; i++ )
		{
			easy_search_test( list, i );
		}
	}
	}
}