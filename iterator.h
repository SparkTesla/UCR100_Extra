#ifndef ITERATOR_H
#define ITERATOR_H

#include "composite.h"
#include <stack>

class Iterator
{
	protected:
			Base* self_ptr;
			Base* current_ptr;

	public:
			Iterator (Base* ptr) { this->self_ptr = ptr;}

			/* Sets up the iterator to start at the beginning of traversal */
			virtual void first() = 0;

			/* Move onto the next element */
			virtual void next() = 0;

			/* Returns if you have finishes iterating through all elements */
			virtual bool is_done() = 0;

			/* Return the element the iterator is currently at */
			virtual Base* current() = 0;

};

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

// Stopping the Iterator at the leaf node
class NullIterator : public Iterator {
	public:
				NullIterator(Base* ptr);

				void first();
				void next();
				bool is_done() { return true; }
				Base* current() { return NULL; }
};


class PreOrderIterator : public Iterator {
		protected:
					stack<Iterator*> iterators;

		public:
				PreOrderIterator(Base* ptr);

				void first()
				{
					// Empty the stack (just in case we had something leftover from another run)
						 while( !iterators.empty() ) { iterators.pop(); }

					// Create an iterator for the Base* that we built the iterator for
						 Iterator* root = self_ptr->create_iterator();

					// Inititalize that iterator and push it onto the stack
						 root -> first();
						 iterators.push(root);
				}

				void next()
				{
					// Create an iterator for the item on the top of the stack
						 Iterator* child = iterators.top() -> current() -> create_iterator();
						 
					// Initialize the iterator and push it onto the stack
						 child -> first();
						 iterators.push(child);
					
					// As long as the top iterator on the stack is done, pop it off the
					// stack and then advance whatever iterator is now on top of the stack
						while ( !(iterators.empty()) && iterators.top()->is_done() )
						{
								iterators.pop();
								iterators.top() -> next();
								if( !(iterators.empty()) )
										break;
						}
				}

				bool is_done()
				{
					// Return true if there are no more elements on the stack to iterate
					if( iterators.empty() )
									return true;
					else
									return false;
				}

				Base* current()
				{
					// Return the current for the top iterator in the stack
					if( !iterators.empty() )
							return iterators.top() -> current();
				}
};

#endif
