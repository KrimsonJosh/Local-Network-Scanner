#include <boost/asio.hpp>
#include <iostream>

using namespace boost::asio;
using namespace boost::asio::ip;

int main() {
    try {
        //create io object
        io_context io;

        //create tcp socket for commms with the server
        tcp::socket socket(io);

        //servers endpoint
        //address::from_string in order to convert string into boost ip add.
        socket.connect(tcp::endpoint(address::from_string("127.0.0.1"), 12345));

        //buffer to store incoming data from server
        char data[1024];

        //use this to capture any errors in read operation
        boost::system::error_code error;

        //read data from server into buffer
        //reads up to the size of the buffer (1024) to get length
        size_t length = socket.read_some(buffer(data), error);

        if (!error) {
            std::cout << "Server message:" << std::string(data, length) << std::endl;
        }
        else {
            std::cout << "Error receiving message: " << error.message() << std::endl;
        }
    } catch (std::exception& e){
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    return 0;
}