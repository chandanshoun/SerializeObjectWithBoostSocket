#ifndef __BOOST_SERIALIZE_H
#define __BOOST_SERIALIZE_H
#include<iostream>
#include<sstream>
#include<string>
using namespace std;

#include<boost/archive/binary_iarchive.hpp>
#include <boost/archive/binary_oarchive.hpp>

class EmployeeData

{

private:

       friend class boost::serialization::access;

       string name;

       int age;

       string company;

       template<class Archive>

       void serialize(Archive& , const unsigned int);

public:

       EmployeeData()
       {

       }

       EmployeeData(string n, int a, string c) :name(n), age(a), company(c)
       {

             

       }

       void showData();
       void save(ostream &);
       void load(string);

       ~EmployeeData()
       {
       
       }

};

#endif 

	
	
	

