# echo-client.py

import socket

HOST = "192.168.1.153"  # The server's hostname or IP address
PORT = 3333  # The port used by the server

with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
    s.connect((HOST, PORT))

    for i in range(1024):
        s.sendall(b"1024")
        data = s.recv(1024)

print(f"Received {data!r}")
