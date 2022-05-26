#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>

#include <rational/rational.h>

TEST_CASE("[rational] - Rational ctor") {
	CHECK((Rational() == Rational(0, 1)));
	CHECK((Rational(3) == Rational(3, 1)));
	Rational N = Rational(4, 6);
	CHECK(N.nom == 2);
	CHECK(N.denom == 3);
	Rational M = Rational(-4, 6);
	CHECK(M.nom == -2);
	CHECK(M.denom == 3);
	Rational P = Rational(4, -6);
	CHECK(P.nom == -2);
	CHECK(P.denom == 3);
	Rational X = Rational();
	CHECK(X.nom == 0);
	CHECK(X.denom == 1);
	Rational Y = X;
	CHECK(X.nom == 0);
	CHECK(X.denom == 1);
	CHECK_THROWS(Rational(1, 0));
}

TEST_CASE("[rational] - ariphmetic") {
	CHECK(((Rational(1, 2) += Rational(1, 4)) == Rational(3, 4)));
	CHECK((Rational(1, 2) + 1) == Rational(3, 2));
	CHECK((Rational(5, 2) - 1) == Rational(3, 2));
	CHECK((Rational(1, 2) * 5) == Rational(5, 2));
	CHECK((Rational(1, 2) / 4) == Rational(1, 8));
	CHECK(Rational(2, 4) == Rational(1, 2));
	CHECK(Rational(0, 7) == Rational(0, 1));
	CHECK(Rational(-2, -4) == Rational(1, 2));
	CHECK(Rational(2, 7) == (Rational(1, 7) += Rational(1, 7)));
	CHECK(Rational(1, 7) == (Rational(3, 7) -= Rational(2, 7)));
	CHECK(Rational(1, 8) == (Rational(1, 4) *= Rational(1, 2)));
	CHECK(Rational(2, 1) == (Rational(2, 4) /= Rational(2, 8)));
	CHECK(Rational(5, 4) == (Rational(9, 4) - 1));
	CHECK(Rational(1, 2) == (Rational(1, 4) * 2));
	CHECK(Rational(7, 8) == (Rational(7, 4) / 2));
	CHECK(Rational(5, 4) == (Rational(1, 4) + 1));
	CHECK(Rational(8, 5) == (1 + Rational(3, 5)));
	CHECK(Rational(3, 4) == (3 - Rational(9, 4)));
	CHECK(Rational(1, 2) == (2 * Rational(1, 4)));
	CHECK(Rational(12, 7) == (3 / Rational(7, 4)));
	CHECK((Rational(2, 1) < Rational(3, 1)));
	CHECK(!(Rational(2, 1) > Rational(3, 1)));
	CHECK((Rational(2, 1) <= Rational(3, 1)));
	CHECK(!(Rational(2, 1) >= Rational(3, 1)));
	CHECK((Rational(5, 3) > Rational(7, 4)));
	CHECK(!(Rational(5, 3) < Rational(7, 4)));
	CHECK((Rational(5, 3) >= Rational(7, 4)));
	CHECK(!(Rational(5, 3) <= Rational(7, 4)));
	CHECK(Rational(-3, 4) == -Rational(3, 4));
	CHECK(-Rational(2, 3) == Rational(-2, 3));
	CHECK_THROWS(Rational(2, 3) /= Rational());
	CHECK_THROWS(Rational(2, 3) / Rational());
};
TEST_CASE("[rational] - exceptions") {
	CHECK_THROWS(Rational(5, 0));
	CHECK_THROWS(Rational(5, 7) / Rational(0, 8));
};
TEST_CASE("[rational] - input") {
	std::stringstream stream;
	std::vector<std::string> strs = {
		"7/13",
		"-5/6",
		"3/9",
		"0/1",
		"0/10",
	};
	std::vector<std::pair<int, int>> corrects = {
		std::make_pair(7, 13),
		std::make_pair(-5, 6),
		std::make_pair(1,  3),
		std::make_pair(0,  1),
		std::make_pair(0,  1),
	};
	auto testsCount = strs.size();
	CHECK(testsCount == corrects.size());
	for (decltype(testsCount) i = 0; i < testsCount; ++i) {
		CAPTURE(strs[i]);
		stream << strs[i];
		Rational q;
		stream >> q;
		CHECK_FALSE(stream.fail());
		CHECK(q == Rational(corrects[i].first, corrects[i].second));
		stream.clear();
	}
}

TEST_CASE("[rational] - incorrect input") {
	std::stringstream stream;
	std::vector<std::string> strs = {
		"7\\13",
		"-5/-6",
		"rgk",
		"9",
		"9 / 3",
		"5/ 4",
		"5/-3",
		"5 /3",
	};
	for (const auto& str : strs) {
		CAPTURE(str);
		stream << str;
		Rational q;
		stream >> q;
		CHECK(stream.fail());
		stream.clear();
	}
}

TEST_CASE("[rational] output") {
	std::stringstream stream;
	Rational q = Rational(-7, 13);
	stream << q;
	std::string str;
	stream >> str;
	CHECK(str == "-7/13");
}