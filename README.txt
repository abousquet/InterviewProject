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
project directory. All tasks, with the exception of task 6, will be shown.

********************************************************************************
Here are the tasks to be completed :

1) Complete dataFunction declared in utils/CommonUtils.hh, the problem is
      defined in the header.

2) Complete dataProducer declared in utils/CommonUtils.hh, the problem is
      define in the header.

3) Write the connect function for the TcpClient class, the description is
      defined in the class's declaration.

4) Modify the accept function for the TcpServer class to print both the
      remote IP and port of the connecting client in the following format:
         Accepting new remote connection from <ip_address>:<port>

5) Modify the RequestQueue class to be thread-safe by using its mutex (it may
      be beneficial to look into RIIA locks in c++, make sure you understand
      how they work)

6) Determine if the utils library should be used as a static or shared library.
      Both targets are available in the utils Makefile as "static" and "clean"
      respectively. Be prepared to justify your answer.

7) Spin three threads with default attributes from within the server's main
      function. The start_routines should be main_read_t, main_write_t, and
      main_data_t.
