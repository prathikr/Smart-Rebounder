from time import sleep
sys.path.append('/Library/Frameworks/Python.framework/Versions/2.7/lib/python2.7/site-packages')
from serial import Serial

def read(port):
	print("reading from port")
	while True:
		line = port.read()
		print(line)

def connect():
	try:
		conn = Serial('/dev/tty.usbmodem14201', baudrate=9600, dsrdtr=0, rtscts=0, timeout=1) #cu.usbmodemFA131
	except IOError:
		print("Error opening serial port.", file=sys.stderr)
		sys.exit(2)

	return conn


def main():
	print("Connecting...")
	conn = connect()
	print("Connected!")

	print("Running code...")
	t1 = threading.Thread(target=test, args=(conn,))
	t2 = threading.Thread(target=read, args=(conn,))
	
	t1.start()
	t2.start()

if __name__ == "__main__":
	main()
