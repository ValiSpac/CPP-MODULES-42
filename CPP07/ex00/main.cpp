# include <iostream>
# include "inc/whatever.hpp"

int main( void ) {
int a = 2;
int b = 3;
std::cout << "a = " << a << ", b = " << b << std::endl;
::swap( a, b );
std::cout << "a = " << a << ", b = " << b << std::endl;
std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl << std::endl;
std::string c = "chaine1";
std::string d = "chaine2";
std::cout << "c = " << c << ", d = " << d << std::endl;
::swap(c, d);
std::cout << "c = " << c << ", d = " << d << std::endl;
std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl << std::endl;
float e = 0.05f;
float f = 1.25f;
std::cout << "e = " << e << ", f = " << f << std::endl;
::swap(e, f);
std::cout << "e = " << e << ", f = " << f << std::endl;
std::cout << "min( c, d ) = " << ::min( e, f) << std::endl;
std::cout << "max( c, d ) = " << ::max( e, f ) << std::endl;
return 0;
}
