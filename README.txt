This is a take-home project to be completed on a linux or darwin machine. Feel
free to add includes, typedefs, and/or variables to any of the .CC files marked
with a TODO.

This project's purpose is to test your technical ability and problem-solving
skills. It is allowed and possibly necessary to use online resources to
complete; however, working with another person is prohibited and on your honor.
You may be asked questions about your solutions and the code that is already
there; therefore emphasis should placed on both completing AND understanding the
project.

Note: The tasks can be easily found by performing 'grep -ir TODO *' from the top
project directory.

********************************************************************************
Here are the tasks to be completed :

1) Determine if the utils library should be used as a static or shared library.
      Both targets are available in the utils Makefile as "static" and "shared"
      respectively. Be prepared to justify your answer.

2) Modify the accept function for the TcpServer class to print both the
      remote IP and port of the connecting client in the following format:
         Accepting new remote connection from <ip_address>:<port>

3) Complete dataFunction declared in utils/CommonUtils.hh, the problem is
      defined in the header.

4) Complete dataProducer declared in utils/CommonUtils.hh, the problem is
      defined in the header.

5) Modify the RequestQueue class to be thread-safe by using its mutex;

6) Trace the server program (server_main.cc). How does it work? What's the
      structure of it? How could it be improved? Expect other questions, so
      study it thoroughly.

To run either the Client or Server, cd to bin/ where there are two run scripts,
Run_Client and Run_Server, that take care of linking if it wasn't done at
compile time. You may pass a parameter to either to be used as the port number
to connect/listen to, the default port is 18999.
