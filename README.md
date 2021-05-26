# SerializeObjectWithBoostSocket

This code Serialize object of class EmployeeData and serialize it to a buffer and send over a server socket with Boost Library. Later Server read this buffer and deserialize it back to it class Object Employee data.
This example only show how we can Serialize an object and send it to network and Desrialize at server side.


#compile server with

g++ server.cpp BoostSerialize.cpp -o server -lboost_serialization -lboost_system

#compile client with

g++ client.cpp BoostSerialize.cpp -o client -lboost_serialization -lboost_system

./server

./client
