#ifndef PART1_H
#define PART1_H

using namespace std;

// Base class for reference pointer from Operation classes
class Base {
   public:
	/*Constructors*/
	   Base() {};

	/* Pure Virtual Functions*/
	   virtual double evaluate() = 0;
};

/* The operand class that handles leaf node numbers*/
class Operand : public Base
{
    public:
	Operand();
	Operand(double x) { leaf_num = x;}
	double evaluate() { return leaf_num;}	// Evaluate the number or operand
    private:
	double leaf_num;
};


/* The multiplication class that handles the multiplication between two child nodes*/
class Mult : public Base
{
    public:
	Base * right_child;
	Base * left_child;
	double evaluate()
	{
		double lefttemp = left_child -> evaluate();
		double righttemp = right_child -> evaluate();
		return lefttemp * righttemp;  
	};	// Evaluate the number or operand

};

/* The multiplication class that handles the multiplication between two child nodes*/
class Div : public Base
{
    public:	
	Base * right_child;
	Base * left_child;

        double evaluate()
	{
		double lefttemp = left_child -> evaluate();
		double righttemp = right_child -> evaluate();
		return (lefttemp / righttemp);  
	};	// Evaluate the number or operand


};

/* The addition class that handles the addition between two child nodes*/
 class Add : public Base 
{
   public:	
	Base * right_child;
	Base * left_child;

	double evaluate()
	{
		double lefttemp = left_child -> evaluate();
		double righttemp = right_child -> evaluate();
		return (lefttemp + righttemp);  
	};	// Evaluate the number or operand


};

/* The multiplication class that handles the multiplication between two child nodes*/
class Sub : public Base
{
   public:	
	Base * right_child;
	Base * left_child;

	double evaluate()
	{
		double lefttemp = left_child -> evaluate();
		double righttemp = right_child -> evaluate();
		return (lefttemp - righttemp);  
	};	// Evaluate the number or operand


};


class Sqr : public Base
{
   public:
	 Base * child;
	 double evaluate() 
	 { 
           double temp = child -> evaluate();
	   return (temp * temp);
	 };	// Evaluate the number or operand
};

#endif
