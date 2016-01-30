#include <iostream>
using namespace std;

int main()
{
   					/* Tree 1 */
	
   /* The class for math operations*/
   Add A;
   Sub B;
   Mult C;
   Div D;
   Sqr E;

   /* The class operand for numbers 1-5*/
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
   double solution = E.evaluate();
   cout << "The solution is " << solution << endl;
   
   					/* Tree 2 */
  Add Y;
  Sqr Z;

  Z.child = &three; 
  Y.left_child = &Z; Y.right_child = &one;


  return 0;
}
