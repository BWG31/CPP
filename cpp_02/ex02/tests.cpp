#include "Fixed.hpp"

// 42 TESTS (as shown in PDF)
void run42Tests()
{
	std::cout << "=== PDF TESTS ===" << std::endl;
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	
	std::cout << b << std::endl;
	
	std::cout << Fixed::max( a, b ) << std::endl;
}

// CUSTOM TESTS (My own to demonstrate remaining features)
void runBgoldingTests()
{
	std::cout << "=== CUSTOM TESTS ===" << std::endl;

	Fixed c(5.1f);
	Fixed d(2);

	std::cout << "c: " << c << "\nd: " << d << std::endl;
	std::cout << "c > d : " << ((c > d) ? "true" : "false") << std::endl;
	std::cout << "c < d : " << ((c < d)  ? "true" : "false") << std::endl;
	std::cout << "c >= d : " << ((c >= d)  ? "true" : "false") << std::endl;
	std::cout << "c <= d : " << ((c <= d)  ? "true" : "false") << std::endl;
	std::cout << "c != d : " << ((c != d)  ? "true" : "false") << std::endl;
	std::cout << "c + d : " << (c + d) << std::endl;
	std::cout << "c - d : " << (c - d) << std::endl;
	std::cout << "c * d : " << (c * d) << std::endl;
	std::cout << "c / d : " << (c / d) << std::endl;

	std::cout << "(c + c) / (d + d) : " << ((c + c) / (d + d)) << std::endl;

	std::cout << "Fixed::min(c, d) + c : " << ((Fixed::min(c, d)) + c) << std::endl;
}
