/*
 * boost_test.cpp
 * Estate agency test using Boost library
 *
 * PROI, project 3
 * Tutor: Wiktor Kusmirek
 * Version: 06.06.2018, Kamil Zacharczuk
 */
 #define BOOST_TEST_MODULE PROI__PROJECT_3_TEST
#include <boost/test/included/unit_test.hpp>

#include <iostream>
#include <sstream>
#include "Estate.hpp"

#define VALIDTEL 500111222

#include <sstream>
std::stringstream  silent;

using namespace boost::unit_test;

BOOST_AUTO_TEST_SUITE(Estate_Test_Suite)

	BOOST_AUTO_TEST_CASE(MustFail)
	{
		BOOST_CHECK (2<0);
	}

	BOOST_AUTO_TEST_CASE(Adding_Stuff_Test_Case)
	{
		Estate est;

		Owner* own = est.add_owner(VALIDTEL, "imie");

		BOOST_CHECK_EQUAL (own->show_telephone(), VALIDTEL);

		Flat* validflat = est.add_flat(500, 25000, "jakasulica", 24, 8, "fajnemieszkanie", own);

		BOOST_CHECK_EQUAL (validflat->show_address(), "ul. jakasulica 24 m. 8");
	}

	BOOST_AUTO_TEST_CASE(Invalid_Tel_Test_Case)
	{
		Estate est;

		Owner* own = est.add_owner(VALIDTEL, "imie");

		BOOST_CHECK_NO_THROW(silent << est);
	}

	BOOST_AUTO_TEST_CASE(Comparing_Case)
	{
		BOOST_CHECK ( *(new Estate("Bbb")) < *(new Estate("Aaaaa")));
	}

BOOST_AUTO_TEST_SUITE_END()

//eof
