#pragma once

#ifndef _MYSTRING_
#define _MYSTRING_

#include <iostream>
#include "Iterator.h"
using namespace std;

#define MAX_SIZE 100000000
#define CAPACITY 15

class MyString
{
private:
	char* _str;
	int _len;
	int _capacity;
public:
	MyString();	
	MyString(const MyString&);
	MyString(const MyString&, int, int);
	MyString(const char*);
	MyString(const char*, int);	
	MyString(int, char);		
	~MyString();

	MyString& operator= (const MyString&);	
	MyString& operator= (const char*);		
	MyString& operator= (char);				

	friend istream& operator>> (istream&, MyString&);
	friend ostream& operator<< (ostream&, const MyString&);


	/*************************CAPACITY*************************/
	int size() const;
	int length() const;
	int max_size() const;
	void resize(int);		
	void resize(int, char);	
	int capacity() const;
	void reserve(int);					
	void clear();						
	bool empty() const;					


	/*************************ELEMENT ACCESS*************************/
	char& operator[] (int);		
	char& at(int);				
	char& back();				
	char& front();				

	/*************************MODIFIERS*************************/
	void push_back(char);
	MyString& operator+= (const MyString&);	
	MyString& operator+= (const char*);		
	MyString& operator+= (const char);		

	MyString& append(const MyString&);				
	MyString& append(const MyString&, int, int);	
	MyString& append(const char*);					
	MyString& append(const char*, int);				
	MyString& append(int, char);					

	MyString& assign(const MyString&);				
	MyString& assign(const MyString&, int, int);	
	MyString& assign(const char*);				
	MyString& assign(const char*, int);			
	MyString& assign(int, char);				

	MyString& insert(int, const MyString&);			
	MyString& insert(int, const MyString&, int, int);
	MyString& insert(int, const char*);					
	MyString& insert(int, const char*, int);			
	MyString& insert(int, int, char);				

	MyString& erase(int, int);		

	MyString& replace(int, int, const MyString&);			
	MyString& replace(int, int, const MyString&, int, int);	
	MyString& replace(int, int, const char*);				
	MyString& replace(int, int, const char*, int);			
	MyString& replace(int, int, int, char);				

	void swap(MyString&);	

	void pop_back();		


	/*************************STRING OPERATIONS*************************/
	const char* c_str() const;						
	
	const char* data() const;					

	int copy(char*, int, int) const;			

	int find(const MyString&, int) const;		
	int find(const char*, int) const;			
	int find(const char*, int, int) const;		
	int find(char, int) const;					

	void swap(char&, char&);			//swap 2 char
	MyString& reverse(MyString&);		//dao chuoi
	int rfind(const MyString&, int) const;			
	int rfind(const char*, int) const;				
	int rfind(const char*, int, int) const;		
	int rfind(char, int) const;					

	int find_first_of(const MyString&, int) const;	
	int find_first_of(const char*, int) const;		
	int find_first_of(const char*, int, int) const;	
	int find_first_of(char, int) const;				

	int find_last_of(const MyString&, int) const;	
	int find_last_of(const char*, int) const;		
	int find_last_of(const char*, int, int) const;	
	int find_last_of(char, int) const;				

	int find_first_not_of(const MyString&, int) const;	
	int find_first_not_of(const char*, int) const;			
	int find_first_not_of(const char*, int, int) const;		
	int find_first_not_of(char, int) const;					

	int find_last_not_of(const MyString&, int) const;		
	int find_last_not_of(const char*, int) const;		
	int find_last_not_of(const char*, int, int) const;		
	int find_last_not_of(char, int) const;				

	MyString substr(int, int) const;			

	int compare(const MyString&) const;					
	int compare(int, int, const MyString&) const;			
	int compare(int, int, const MyString&, int, int) const;	
	int compare(const char*) const;							
	int compare(int, int, const char*) const;				
	int compare(int, int, const char*, int) const;			


	/*************************MEMBER CONSTANTS*************************/
	static const int npos = MAX_SIZE;					

	/*************************NON-MEMBER FUNCTION OVERLOADS*************************/
	friend MyString operator+ (const MyString&, const MyString&);		
	friend MyString operator+ (const MyString&, const char*);		
	friend MyString operator+ (const char*, const MyString);		
	friend MyString operator+ (const MyString&, char);					
	friend MyString operator+ (char, const MyString&);					

	friend bool operator== (const MyString&, const MyString&);			
	friend bool operator== (const char*, const MyString&);				
	friend bool operator== (const MyString&, const char*);				

	friend bool operator!= (const MyString&, const MyString&);		
	friend bool operator!= (const char*, const MyString&);				
	friend bool operator!= (const MyString&, const char*);				

	friend bool operator< (const MyString&, const MyString&);		
	friend bool operator< (const char*, const MyString&);			
	friend bool operator< (const MyString&, const char*);				

	friend bool operator<= (const MyString&, const MyString&);		
	friend bool operator<= (const char*, const MyString&);				
	friend bool operator<= (const MyString&, const char*);				

	friend bool operator> (const MyString&, const MyString&);			
	friend bool operator> (const char*, const MyString&);				
	friend bool operator> (const MyString&, const char*);				

	void swap(MyString&, MyString&);								

	friend istream& getline(istream&, MyString&, char);		
	friend istream& getline(istream&, MyString&);			
};

#endif
