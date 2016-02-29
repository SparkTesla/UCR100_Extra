#ifndef __B__CLASS__
#define __B__CLASS__
#include <composite.h>

class Iterator{

	protected: 
		Base * self_ptr;
		Base * current_ptr;

	public:
		Iterator (Base* ptr) { this->self_ptr = ptr;}

		/*Sets up the iterator to start at the beggining of traversal*/
		virtual void first() = 0;

		/*Move onto the next element*/
		virtual void next() = 0;

		/*Returns if you have finished iterating through all the elements*/
		virtual bool is_done() = 0;

		/*Return the element the iterator is currently at */
		virtual Base * current() = 0;

};
#endif

class OperatorIterator : public Iterator {
	public:
		OperatorIterator(Base * ptr);

		void first(){
			current_ptr = self_ptr->get_left();
		}
		void next(){
			if(current_ptr == self_ptr->get_left()){
				current_ptr = self_ptr->get_right();
			}
			else{
				current_ptr = NULL;
			}
		}
		bool is_done(){
			if(current_ptr == NULL){
				return true;
			}
			return false;
		}
		Base * current(){
			return current_ptr;
		}
};


class UnaryIterator : public Iterator {
	public:
		UnaryIterator(Base * ptr);

		void first(){
			current_ptr = self_ptr->get_left();		
		}
		void next(){
			current_ptr = NULL;
		}
		bool is_done(){
			if(current_ptr == NULL){
				return true;
			}
			return false;
		}
		Base * current(){
			return current_ptr;
		}

};
