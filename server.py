import socket

serversocket = socket.socket(socket.AF_INET,socket.SOCK_STREAM)

host = socket.gethostname()
port = 444

print(serversocket)
serversocket.bind((host,port))

serversocket.listen(3)

while True:
    clientsocket,address = serversocket.accept()

    print("received connection from " % str(address))

    # msg = "Hello you are connected to the server"
    msg = [2,3,1,3]

    barr = bytearray(msg) 

    clientsocket.send(barr)
    clientsocket.close()




