#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>

#include <complex/complex.h>

TEST_CASE("[complex] - Complex ctor")
{
	CHECK(Complex() == Complex(0, 0));
	CHECK(Complex(1, 5) == Complex(1.5, 0));
}
TEST_CASE("[complex] - ariphmetic") {
	CHECK(Complex(8, 7) == (Complex(3, 4) += Complex(5, 3)));
	CHECK(Complex(5, 6) == (Complex(7, 10) -= Complex(2, 4)));
	CHECK(Complex(-8, 27) == (Complex(2, 3) *= Complex(5, 6)));
	CHECK(Complex(0.459016393442623, 0.0491803278688525) == (Complex(2, 3) /= Complex(5, 6)));
	CHECK_THROWS(Complex(1, 2) /= Complex());
	CHECK(Complex(25.3, 7) == (Complex(12.1, 7) + 13.2));
	CHECK(Complex(25.3, 7) == (Complex(27.8, 7) - 2.5));
	CHECK(Complex(41.34,54.6) == (Complex(5.3, 7) * 7.8));
	CHECK(Complex(0.6794871794871795,0.8974358974358975) == (Complex(5.3, 7) / 7.8));
	CHECK(Complex(-7, -3) == -Complex(7, 3));
	CHECK(Complex(2.6, 3.5) == (0.3 + Complex(2.3, 3.5)));
	CHECK(Complex(2.6, 3.5) == (1.7 - Complex(2.3, 3.5)));
	CHECK(Complex(0.152155936113358, 0.198346131135818) == (2.3 / Complex(5.6, 7.3)));
	CHECK(Complex(12.88, 16.7899999997489) == (2.3 * Complex(5.6, 7.3)));
	CHECK(Complex(2.6, 3.5) == (Complex(2.3, 3.5) + 0.3));
	CHECK(Complex(0.6, 3.5) == (Complex(2.3, 3.5)-1.7));
	CHECK(Complex(2.43478260869565,3.17391304347826) == (Complex(5.6, 7.3)/2.3));
	CHECK(Complex(12.88, 16.7899999997489) == (Complex(5.6, 7.3)*2.3));

}
TEST_CASE("{complex] Input/Output") {
	std::vector<std::stringstream*> correct_inputs{ new std::stringstream("{2.6,5.8}"),
													 new std::stringstream("{-9.7, 4}") };
	std::vector<Complex> inputs_complex{ Complex(2.6,5.8),
										 Complex(-9.7, 4)};

	for (int i = 0; i < correct_inputs.size(); i++) {
		Complex input{ 1, 1 };
		*(correct_inputs[i]) >> input;
		CHECK(input == inputs_complex[i]);
	}

}