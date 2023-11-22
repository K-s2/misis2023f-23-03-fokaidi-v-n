
#include <sstream>

class Rational {
private:
	int64_t num_ = 0;
	int64_t den_ = 1;
public:
	//конструктор по умолчанию
	Rational() : num_(0), den_(1) {}
	//конструктор по умолчанию с одним аргументом
	Rational(const int64_t numerator) : num_(numerator), den_(1) {}
	//конструктор с двумя аргументами
	Rational(const int64_t numerator, const int64_t denumerator) : num_(numerator), den_(denumerator) {}
	
	std::ostream& writeTo(std::ostream& ostrm) const;
	std::istream& ReadFrom(std::istream& istrm);
	int64_t
};

void test1() {
	r1 = Rational(5 / 3);
}


