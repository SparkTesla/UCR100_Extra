#include <iostream>
#include "part1.h"
#include "part2.h"

using namespace std;

int main()
{
   					/* Tree 1 */
	
   /* The class objects for math operations*/
   Add A;
   Sub B;
   Mult C;
   Div D;
   Sqr E;

   /* The class objects of operand for numbers 1-5*/
   Operand one(1); 
   Operand two(2); 
   Operand three(3); 
   Operand four(4); 
   Operand five(5);

   /* Tree to evaluate the arithmetic expression*/
   B.left_child = &five; B.right_child = &one;
   D.left_child = &four; D.right_child = &two;
   A.left_child = &D; A.right_child = &B;
   C.left_child = &A; C.right_child = &three;
   E.child = &C;

   /* Solution to Tree1 */
   //double solution = E.evaluate();
   //cout << "The solution is " << solution << endl;
    					
  /* Tree 2*/
   Add Y;
   Sqr Z;

   Z.child = &three; 
   Y.left_child = &Z; Y.right_child = &one;

   //double solution1 = Y.evaluate();
   //cout << solution1 << endl;

   /* Tree 3 */
   Sqr W;
   W.child = &five;

   //double solution2 = W.evaluate();
   //cout << solution2 << endl;

   /* Tree 4 */
   Sqr F;
   F.child = &four;

   //double solution4 = F.evaluate();
   //cout << solution4 << endl;

  /*Vect */
  cout << "Testing Vector container" << endl;
  Vect test;
  Base * point = &E;
  test.add_element(point);
  point = &Y;
  test.add_element(point);
  point = &W;
  test.add_element(point);
  point = &F;
  test.add_element(point);
  //second vect
  Vect test2;
  Base * point2 = &E;
  test2.add_element(point2);
  point2 = &Y;
  test2.add_element(point2);
  point2 = &W;
  test2.add_element(point2);
  point2 = &F;
  test2.add_element(point2); 
  /*Bubble sort*/
  cout << "Using bubble sort" << endl;
  Sort * temp = new Bubble();
  test.set_sort_function(temp);
  test.print();
  cout << endl;
  test.sort();
  test.print();
  /*Select*/
  cout << endl<< "Using select sort" << endl;
  temp = new Select();
  test2.set_sort_function(temp);
  test2.print();
  cout << endl;
  test2.sort();
  test2.print();
  cout << endl;
  //////////////////////////////////////////
  /*List*/
  cout << endl <<  "Testing List container" << endl;
  List test3;
  Base * point3 = &E;
  test3.add_element(point3);
  point3 = &Y;
  test3.add_element(point3);
  point3 = &W;
  test3.add_element(point3);
  point3 = &F;
  test3.add_element(point3);
  //second vect
  List  test4;
  Base * point4 = &E;
  test4.add_element(point4);
  point4 = &Y;
  test4.add_element(point4);
  point4 = &W;
  test4.add_element(point4);
  point4 = &F;
  test4.add_element(point4); 
  /*Bubble sort*/
  cout << "Using bubble sort" << endl;
  Sort * temp2 = new Bubble();
  test3.set_sort_function(temp2);
  test3.print();
  cout << endl;
  test3.sort();
  test3.print();
  /*Select*/
  cout << endl<< "Using select sort" << endl;
  temp2 = new Select();
  test4.set_sort_function(temp2);
  test4.print();
  cout << endl;
  test4.sort();
  test4.print();
  cout << endl;


  return 0;
}
