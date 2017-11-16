Running the server:
    To run the server, make the utils into a library and then make the server
    into an executable that is then copied here. It is suggested that you use
    the Run_* scripts to execute either side. You can pass a parameter to the
    run script that will be the listening port for the server. Once running the
    server will print "Listening for connection on <port>...", and won't print
    anything else without modification.

Running the client:
    To run the client, make the utils into a library and then make the client
    into an executable that is then copied here. It is suggested that you use
    the Run_* scripts to execute either side. You can pass a parameter to the
    run script that will be the port to connect to. The client is mostly
    complete out of the box. On startup, the client will print "Client connected
    successfully" or "Failed to connect to <port>:<error message>". Once
    connected, the client accepts data from stdin which will be processed by
    the dataFunction and returned. If you hit return on the client, it will send
    whatever data is produced by dataProducer. However, if dataProducer isn't
    implemented it will ignore the return. After the data is received from the
    server, it will print "Password strength is: <strength>". If the
    dataFunction is not implemented, the server will return whatever you sent it
    originally.
