import serial
import string
import os
import sys
import argparse
import logging
import threading
import time

def main():

    with serial.Serial('/dev/ttyUSB0', 115200, timeout=0.1) as ser:
        ser.flush()
        ser.flushInput()
        ser.flushOutput()
        ser.reset_input_buffer()
        while True:
            if ser.inWaiting() > 0:
                print(ser.read(ser.inWaiting()).decode("utf-8"))
            time.sleep(1)


if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument('--test', action='store_true')
    args = vars(parser.parse_args())

    main()



