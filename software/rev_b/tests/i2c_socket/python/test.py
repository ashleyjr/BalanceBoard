# echo-client.py

import socket
import time

HOST = "192.168.1.153"  # The server's hostname or IP address
PORT = 3333  # The port used by the server

PKTS = 1000

# Latency
with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
    s.connect((HOST, PORT))
    for i in range(PKTS):
        s.sendall(bytes(f"1", encoding="ascii"))
        data = s.recv(1024)
        print(data)

