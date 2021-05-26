#include "BoostSerialize.h"

template<class Archive>

void EmployeeData::serialize(Archive& archive, const unsigned int version)
{

              archive & name;

              archive & age;

 
              if(version>0)

              archive& company;

}

void EmployeeData::showData()
{

              cout << name << "," << age <<","<<company<< endl;
}

void EmployeeData::save(ostream &oss)
{
              boost::archive::binary_oarchive oa(oss);
              oa & *(this);
}

void EmployeeData::load(string str_data)
{
              std::istringstream iss(str_data);
              boost::archive::binary_iarchive ia(iss);
              ia & *(this);
}

BOOST_CLASS_VERSION(EmployeeData, 1)

 

 

	
	
	

