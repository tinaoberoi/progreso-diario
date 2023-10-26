with open('file.txt', 'w+') as f:
	f.write("Hello World\n")
	f.close()

x = open('file.txt')
x.read() 