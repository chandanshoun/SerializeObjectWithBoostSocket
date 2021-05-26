#include "BoostSerialize.h"
#include <boost/asio.hpp>
using namespace boost::asio;
using ip::tcp;
using std::string;
using std::cout;
using std::endl;

string read_(tcp::socket & socket) 
{
       boost::system::error_code error;
       boost::asio::streambuf buf;
       auto bytes=boost::asio::read(socket, buf, boost::asio::transfer_all(),error);
       ostream oss(&buf);
       std::stringstream ss;
       ss<<oss.rdbuf();
       std::string str_data = ss.str();
       cout<<"received "<<bytes<<" bytes"<<endl;
       return str_data;
}

void send_(tcp::socket & socket, const string& message) 
{
       const string msg = message + "\n";
       boost::asio::write( socket, boost::asio::buffer(message) );
}

int main() {
      boost::asio::io_service io_service;

      //listen for new connection
      tcp::acceptor acceptor_(io_service, tcp::endpoint(tcp::v4(), 1234 ));

      //socket creation 
      tcp::socket socket_(io_service);

      //waiting for connection
      acceptor_.accept(socket_);

      //read operation
      boost::system::error_code error;
      string mssg=read_(socket_);

      EmployeeData newEmp;
      //loading data in newEmp with binary archive.
      newEmp.load(mssg);
      newEmp.showData();

      return 0;
}
