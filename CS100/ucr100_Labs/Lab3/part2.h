#ifndef PART2_H
#define PART2_H

#include "part1.h"
#include <vector>
#include <iostream>

class Container
{
	protected:
		Sort* sort_function;
	public:
		/*Constructors*/
		Container() : sort_function(NULL){};
		Container(Sort* function) : sort_function(function) {};

		/* Non Virtual Functions */
		void set_sort_function(Sort* sort_function);

		/* Pure Virtual Functions */
		virtual void add_element(Base* element) = 0;
		virtual void print() = 0;
		virtual void sort() = 0;
		virtual void swap(int i, int j) = 0;
		virtual Base* at(int i) = 0;
		virtual int size() = 0;
};

class Sort
{
	public:
		/* Constructors */
		Sort();

		/* Pure Virtual Functions */
		virtual void sort(Container* container) = 0;
};


/* Container derived classes */

class List : public Container
{
  public:
	  void add_element(Base* element);
	  void print();
	  void sort();
	  void swap(int i, int j);
	  Base* at(int i);
     	  int size();

};

class Vect : public Container
{
   public:
	Vect();
	void add_element(Base* element) 
	{
	   bin.push_back(element);
	};

	void print()
	{
	  for(int i = 0; i < bin.size(); i++)
	  {
		  cout << bin.at(i).evaluate() << " ";
	  } // COME BACK AND VERIFY LATER
	};
	void sort();
	void swap(int i, int j);
	Base* at(int i);
     	int size()
	{
	   return bin.size();
	};

  private:
	vector<Base*> bin;
};

class Bubble : public Sort
{
   public:
      void sort(Container* container);
};

class Select : public Sort
{ 
    public:
	void sort(Container* container);
};

#endif
