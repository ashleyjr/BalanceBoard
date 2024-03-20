# echo-client.py

import socket
import time

HOST = "192.168.1.153"  # The server's hostname or IP address
PORT = 3333  # The port used by the server

PKTS = 1024
SIZE = 1024

print(f"Sending {PKTS} packets of {SIZE} bytes")

# Latency
with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
    s.connect((HOST, PORT))
    latency_ms = []
    for i in range(PKTS):
        start = time.time()
        s.sendall(bytes(f"1", encoding="ascii"))
        data = s.recv(1024)
        end = time.time()
        latency_ms.append((end - start)*1000)

mini = min(latency_ms)
maxi = max(latency_ms)
mean = sum(latency_ms) / PKTS
print(f"Latency:")
print(f"\tMin  = {mini:.2f}ms")
print(f"\tMax  = {maxi:.2f}ms")
print(f"\tMean = {mean:.2f}ms")

# Bandwidth
with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
    s.connect((HOST, PORT))
    start = time.time()
    for i in range(PKTS):
        s.sendall(bytes(f"{SIZE}", encoding="ascii"))
        data = s.recv(1024)
    end = time.time()

print(f"Bandwidth:")
bytes_sent = PKTS*SIZE
elapsed = end - start
bytes_per_second = bytes_sent / elapsed
kb_per_second = bytes_per_second / 1024
mb_per_second = kb_per_second / 1024
print(f"\tRaw              = {mb_per_second:.2f}MB/s")
bytes_sent = PKTS*SIZE
elapsed = (end - start) - (PKTS * (mean/1000))
bytes_per_second = bytes_sent / elapsed
kb_per_second = bytes_per_second / 1024
mb_per_second = kb_per_second / 1024
print(f"\tSubtract latency = {mb_per_second:.2f}MB/s")

