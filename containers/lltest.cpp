#include "LinkedList.h"
#include <string>

#include <iostream>

class ListNode{

	int id;
	std::string str;

  public:
	ListNode(){}
	ListNode(int id_, std::string str_):id(id_), str(str_){

	}

	std::string getString(){
		return str;
	}
	

};





int main(){

	LinkedList<ListNode> ll;
	
	std::string str = "first _node";
	ListNode l(0,str);

	std::cout<<l.getString() << std::endl;

	ll.insert_tail(l);
	

	Node<ListNode> *a = ll.gethead();


	ListNode mynode = a->getData();
	std::string mystring = mynode.getString();

}
