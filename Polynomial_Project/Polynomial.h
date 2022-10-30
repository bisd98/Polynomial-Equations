class Polynomial
{
	int power;
	float* values = new float[power +1] {};
public:
	Polynomial(){}
	Polynomial(int n) :power(n) {}
	~Polynomial() {}
	void enterPolynomial();
	void showPolynomial();
	friend Polynomial sumPolynomials(Polynomial fisrt, Polynomial second);
	friend Polynomial subPolynomials(Polynomial fisrt, Polynomial second);
	friend Polynomial prodPolynomials(Polynomial fisrt, Polynomial second);
	friend Polynomial quotPolynomials(Polynomial fisrt, Polynomial second);
};
