#include "BoostSerialize.h"
#include <boost/asio.hpp>
#include <boost/function.hpp>
#include <boost/bind.hpp>
#include <functional>
using namespace boost::asio;
using ip::tcp;
using std::cout;
using std::endl;

void on_send_completed(boost::system::error_code ec, size_t bytes_transferred) {
    if (ec)
        std::cout << "Send failed: " << ec.message() << "\n";
    else
        std::cout << "Send succesful (" << bytes_transferred << " bytes)\n";
}

int main() {
     boost::asio::io_service io_service;
     //socket creation
     tcp::socket socket(io_service);
     //connection
     socket.connect( tcp::endpoint( boost::asio::ip::address::from_string("127.0.0.1"), 1234 ));
     // request/message from client

     boost::asio::streambuf buf;
     EmployeeData emp("chandan", 34, "microsoft");

     std::ostream oss(&buf);

     //saving data in oss
     emp.save(oss);

     boost::system::error_code error;
     boost::asio::async_write( socket, buf, on_send_completed);

     return 0;
}
