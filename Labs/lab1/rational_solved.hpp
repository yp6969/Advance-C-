class rational {
  int numerator, denominator;
public:

	struct DivideByZeroException { };
	
    // Constructors
    rational();          // Zero
    rational(int n);       // Equal to n/1
    rational(int n, int d) throw (DivideByZeroException);  // General case (n/d)
	rational(const string& s) throw (DivideByZeroException) {
      istringstream instr(s);
      char slash;
      instr >> numerator >> slash >> denominator;
	  if (denominator==0) throw DivideByZeroException();
    }
	
    rational& operator=(int n);

    rational& assign(int n, int d) throw (DivideByZeroException);

    // Representation
    int getNum() const;
    int getDenom() const;

    // Arithmetic operators
    rational& operator+= (const rational& r);
    rational& operator-= (const rational& r);
    rational& operator*= (const rational& r);
    rational& operator/= (const rational& r) throw (DivideByZeroException);


    // Comparison operators
    bool operator< (const rational& r) const;
    bool operator== (const rational& r) const;
	
	operator string() const {
      ostringstream outstr;
      outstr << numerator << '/' << denominator;
      return outstr.str();
    }

   struct Index {
     Index(double p) : _p(p) { }
     Index const& operator*() const { return *this; }
     double _p;
   };
   
   friend rational my_pow(const rational& x , const Index& i);
   friend rational operator*(const rational& a, const Index& b);

};

rational my_pow(const rational& x , const Index& i) {
   return rational(pow(x.numerator,i._p), pow(x.denominator,i._p)) ;
}

rational operator*(const rational& a, const Index& b) {
   return my_pow(a,b);
}
