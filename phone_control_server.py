# ====================================================
#  Author:        KanKunI
#  Date Created:  2020/08/23
#  Last Updated:  2020/08/24
#  Description:   create socket server that phone can
#                 control the car
# ====================================================

from socket import *
import sys
import time
import serial

ctrCmd = ['S','A','F','R','L','B']
HOST = ''
PORT = 21567

port = serial.Serial('/dev/ttyACM0', 9600, timeout = 3.0)

def main():
  s = socket(AF_INET, SOCK_STREAM) # create TCP service

  try:
    s.bind((HOST,PORT))   # bind addr (host,port) to socket，in AF_INET,
                          # use tuple (host,port) format represent addr
  except socket.error as err:
    print("Bind Failed, Error Code: "+ str(err[0])+", Message: "+err[1])
    sys.exit()

  print("Socket Bind Success!")

  s.listen(10)   # start TCP listen, setting maximum of connection
  print("Socket is now listening")


  while True:
    conn, addr = s.accept()
    print('connected from ',addr[0] + ":" + str(addr[1]))
    buf = conn.recv(64) # recive bytes
    print(buf)
    text = str(buf) # text[0] = IP, text[1] = PORT, text[2] = command
    if text[2] in ctrCmd: # if command is legal
      move(text[2])

  s.close()

def move(cmd):
  port.write(bytes(cmd, 'UTF-8'))
  time.sleep(0.1)

if __name__ == '__main__':
  main()
