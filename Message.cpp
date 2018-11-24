//============================================================================
// Name        : Message.cpp
// Author      : sc
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "Message.h"


Node::Node( unsigned int id, std::string frag ){
	identifier = id;
	fragment = frag;
	p_next = nullptr;
}

Node *Node::get_next(){
	return p_next;
}

std::string Node::get_fragment(){
	return fragment;
}

Message::Message(){
	head = nullptr;
}

Message::~Message(){
	Node *p_node = head;
	while( p_node != nullptr) {
	    Node *tem = p_node->p_next;
	    delete p_node;
	    p_node = tem;
	}
	head = 0;
}

void Message::insert( unsigned int id, std::string fragment){
	if(head == nullptr){
	Node *p_new{new Node(id,fragment)};
	p_new->p_next = head;
	p_new->identifier =	id;
	head = p_new;
	}else if(id < head->identifier){
		       Node *p_new2{new Node(id,fragment)};
		       		 p_new2->p_next = head;
		       		 p_new2->identifier = id;
		       		 head = p_new2;
	}
	else{
		bool flag = true;
		Node *tem = head;
		while(tem != nullptr){
			if(id < tem->identifier){
				flag = false;
			}
			tem = tem->p_next;
		}
		if(flag){
			Node *tem2 = head;
			Node *pre = head;
			Node *p_new3{new Node(id,fragment)};
	        p_new3->p_next = nullptr;
	        p_new3->identifier = id;
	        while(tem2 != nullptr){
	        	pre=tem2;
	        	tem2 = tem2->p_next;
	        }
	        pre->p_next = p_new3;
		}else{
			Node *tem3 = head;
		while(tem3 != nullptr){
			Node *pre = tem3;
			tem3 = tem3->p_next;
			if(id < tem3->identifier){
				Node *p_new4{new Node(id,fragment)};
				p_new4->p_next = tem3;
				p_new4->identifier = id;
				pre->p_next = p_new4;
				break;
			}
		  }
		}
	}
}

void Message::print_message(){
    int flag=0;
    int end=0;
	for(Node *p_node{head}; p_node != nullptr; p_node  = p_node->p_next){
		if(p_node->fragment == "EOT"){
	       end = p_node->identifier;
	       flag=1;
	       break;
		}
	}
	if(flag == 1){
		for( int i=0;i<end;++i){
			bool exist = false;
			std::string tem;
			for(Node *p_node{head}; p_node != nullptr; p_node  = p_node->p_next){
            if(i == int(p_node->identifier)){
            	exist = true;
            	tem = p_node->fragment;
            	break;
               }
			 }
             if(exist){
            	 if(i != end-1){
            	 std::cout<<tem<<" ";
            	 }else{
            		 std::cout<<tem;
            	 }
             }else{
            	 if(i != end-1){
            	std::cout<<"..."<<" ";
            	 }else{
                std::cout<<"...";
            	 }
             }
			}
	}else{
		int max=-1;
		for(Node *p_node{head}; p_node != nullptr; p_node  = p_node->p_next){
			if(max < int(p_node->identifier)){
		       max = p_node->identifier;
			}
		}
			if(max != -1){
				for( int i=0;i<=max;++i){
					bool exist = false;
					std::string tem;
					for(Node *p_node{head}; p_node != nullptr; p_node  = p_node->p_next){
					    if(i == int(p_node->identifier)){
					       exist = true;
					       tem = p_node->fragment;
					       break;
					   }
					}
					if(exist){
					          std::cout<<tem<<" ";
					}else{
					      std::cout<<"..."<<" ";
					     }
				}
			}
			std::cout<<"???";
	}
}

int main() {
    int a=-3;
    Message message_1;
    while(a!=-2){
    	std::string fragment;
	std::cin>>a;
	if(a==-1){
		message_1.print_message();
		std::cout<<std::endl;
	}else{
		std::cin>>fragment;
		message_1.insert(a,fragment);
		 }
	  }
	return 0;
}
