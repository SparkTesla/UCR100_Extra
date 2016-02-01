#ifndef PART2_H
#define PART2_H

#include "part1.h"
#include <vector>
#include <list>
#include <iostream>

class Sort
{
	public:
		/* Constructors */
		Sort();

		/* Pure Virtual Functions */
		virtual void sort(Container* container) = 0;
};


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

/* Container derived classes */

class List : public Container
{
  public:
	  List();
	  // Adding elements to a list by using Base pointer 
	  void add_element(Base* element)
	  {
            bin.push_back(element);
	  };
	  // Prints the entire 
	  void print()
	  {
	    list<Base *>::iterator it = bin.begin();
	    for(; it != bin.end(); it++)
	    {
		cout << *it << " ";
	    }
	  };

	  void sort()
	  {	  
	    sort_function -> sort(this);
	  };

	  void swap(int i, int j)
	  { 
	    list<Base *>::iterator it1 = bin.begin();
	    list<Base *>::iterator it2 = bin.begin();
	    //list<Base *>::iterator it3 = bin.begin();
	    Base * temp;

	    for(int x = 0; x < i; x++)
	    {
		it1++;	
	    };

	    for(int x = 0; x < j; x++)
	    {
		it2++;	
	    };

	    temp = *it1;
	    *it1 = *it2;
	    *it2 = temp;
	  };

	  Base* at(int i)
	  {
	    list<Base *>::iterator it = bin.begin();

	    for(int x = 0; x < i; x++)
	    {
		it++;	
	    };

	    return *it;
	  };
     	  
	  int size()
	  {
		  return bin.size();
	  };
  private:
	  list<Base *> bin;
};

// Vector class
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

	void sort()
	{
	  sort_function -> sort(this);
	};
	
	void swap(int i, int j)
	{
	  Base * temp1 = bin.at(i);
	  bin.at(i) = bin.at(j);
	  bin.at(j) = temp1;
	};

	Base* at(int i)
	{
	  return bin.at(i);	
	};

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
      void sort(Container* container)
      {	
	  int flag = 1;

	  for(int i = 1; (i <= *container.size()) && flag; i++)
	  {	
		flag = 0;	
	    for(int j = 0; j < *container.size()- 1; j++)
	    {
		    if( *container.at(j) > *container.at(j + 1) )
		    {
			*container.swap(j,j + 1);
			flag = 1;
		    }
	    }
	  }
      };
};

class Select : public Sort
{ 
    public:
	void sort(Container* container)
	{
	  for(int i = 0; i < *container.size(); i++)
	  {
	    for(int j = i; j < *container.size(); j++)
	    {
		    if( *container.at(j) < *container.at(i) )
		    {
			*container.swap(i,j);
		    }
	    }
	  }
	 }
};

#endif
