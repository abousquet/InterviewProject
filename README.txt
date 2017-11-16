This is a take-home project to be completed on a linux or darwin machine. Feel
free to add includes, typedefs, and/or variables to any of the .CC files marked
with a TODO.

This project's purpose is to test your technical ability and problem-solving
skills. It is allowed and possibly necessary to use online resources to
complete; however, working with another person is prohibited and on your honor.
You may be asked questions about your solutions and the code that is already
there; therefore emphasis should placed on both completing AND understanding the
project.

Each of the tasks are designed to be modularized, meaning that you may complete
them in any order you'd like and the project will still compile. If you decide
to skip task 1, you may use either shared or static libraries to compile and run
the project.

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
      You can check that the correct port is being printed by using
      "netstat | grep <listenport>" on Linux or
      "lsof | grep <listen port>" on Darwin where listen port is the port the
      server is listening on. (hint: use inet_ntoa() and ntohs())

3) Complete dataFunction declared in utils/CommonUtils.hh, the problem is
      defined in the header.

4) Complete dataProducer declared in utils/CommonUtils.hh, the problem is
      defined in the header.

5) Modify the RequestQueue class to be thread-safe by using its mutex;

6) Trace the server program (server_main.cc). How does it work? What's the
      structure of it? How could it be improved? How is I/O performed? Expect
      other questions.

** See the bin/README.txt for information on running the code.
