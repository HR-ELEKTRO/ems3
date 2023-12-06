#ontvang_temperaturen.py
import socket
import sys
import signal
import select

IP_temperatuur_logger = 'xxx.xxx.xxx.xxx'
PORT_temperatuur_logger = 1000

s = None

def handler(signum, frame):
    print("closing connection...")
    if (s is not None):
        s.close()
    sys.exit()

# use ctrl+c to close the program
signal.signal(signal.SIGINT, handler)

for res in socket.getaddrinfo(IP_temperatuur_logger, PORT_temperatuur_logger, socket.AF_UNSPEC, socket.SOCK_DGRAM):
    af, socktype, proto, canonname, sa = res
    try:
        s = socket.socket(af, socktype, proto)
    except socket.error as msg:
        s = None
        continue
    break
if s is None:
    print("could not open socket")
    sys.exit()

print("Starting ontvang_temperaturen")

request = "temp?\0";
while True:
    try:
        bytes_sent = s.sendto(request.encode(), sa)
    except socket.error as msg:
        print("Error: sendto returned " + str(bytes_sent))
        print(msg)
        s.close()
        sys.exit()
    if bytes_sent != len(request):
        print("Error: sendto returned " + str(bytes_sent))
        s.close()
        sys.exit()
    
    # Wait for UDP packet. Timeout after 1 second (assume UDP packet dropped)
    [rlist, wlist, xlist] = select.select([s], [], [], 1)
    if rlist != [s]:
        # UDP is lossy. Send another request
        continue

    try:
        [data, addr] = s.recvfrom(32)
    except socket.error as msg:
        print("Error: recv returned:" + msg)
        s.close()
        sys.exit()
    print('Temperature received: ' + data.decode().rstrip('\x00'))
