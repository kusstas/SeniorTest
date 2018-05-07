#include "catch/catch.hpp" 
#include "Add.h"

namespace AyxCppTest
{
	/**
	* Add two arbitrarily long numbers encoded as strings and return the result
	* as a number encoded as a string.  Each character in the input and output
	* strings is a single digit in the range of [0,9] inclusive.
	*
	* Sample test cases are provided as a starting point.
	*
	* Tasks:
	*   -Complete the Add function.
	*   -Add and repair test cases as appropriate.
	*/

	std::string Add(std::string lhs, std::string rhs)
	{
		std::string const& smax = (lhs.size() >  rhs.size()) ? lhs : rhs;
		std::string const& smin = (lhs.size() <= rhs.size()) ? lhs : rhs;
		std::string retval;; 

		int overflow = 0;
		for (int i = 1; i <= smax.size(); i++) {
			int sum;
			int result;
			int a1 = smax[smax.size() - i] - 48;
			if (i <= smin.size()) {
				int a2 = smin[smin.size() - i] - 48;
				sum = (overflow + a1 + a2);
			}
			else {
				sum = overflow + a1;
			}
			overflow = sum / 10;
			result = sum % 10;
			retval = std::to_string(result) + retval;
		}
		if (overflow > 0) {
			retval = std::to_string(overflow) + retval;
		}
		
		return retval;
	}

	TEST_CASE("exercise5")
	{
		// enable to run exercise 6 tests
#if 1
		REQUIRE(Add("1", "2") == "3");

		std::string                     BigNum("1000000000000000000000000000000000000000000000000000000000000");
		REQUIRE(Add(BigNum, "1")   == "1000000000000000000000000000000000000000000000000000000000001");
		REQUIRE(Add(BigNum, "10")   == "1000000000000000000000000000000000000000000000000000000000010");
		REQUIRE(Add(BigNum, "100")  == "1000000000000000000000000000000000000000000000000000000000100");
#endif
	}
}
