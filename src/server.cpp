#include <boost/asio.hpp>
#include <iostream>

using namespace boost::asio;
using namespace boost::asio::ip;

int main() {
    try {
        //io object for async io operations
        io_context io;

        //TCP acceptor for listening to incoming connections
        //tcp::v4 specifies IPv4, specifies 12345 port number
        tcp:: acceptor acceptor(io, tcp::endpoint(tcp::v4(), 12345));

        std::cout << "Server is listening on port 12345" << std::endl;

        //socket to communicate with the connected client
        tcp::socket socket(io);

        //wait then accept connection
        acceptor.accept(socket);

        std::string message = "Hello this is the server";

        //capture errors using boost error object
        boost::system::error_code error;

        //write message to client using the socket
        write(socket, buffer(message), error);

        if (!error){
            std::cout << "Message sent to client" << std::endl;
        }
        else {
            std:: cout << "Error sending message " << error.message() << std::endl;
        }

    }   catch(std::exception& e){
        // catch errors and display 
        std:: cerr << "Exception " << e.what() << std::endl;
    }


}