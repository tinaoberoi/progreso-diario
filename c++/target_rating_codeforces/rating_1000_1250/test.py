n = input()
#print(n)
s = str(n)
l = len(s)

ans = 1

if(s.count("4") + s.count("7") != l):
	if(int(n)%4!=0):
		if(int(n)%7 != 0):
			if(int(n)%47 != 0):
				ans = 0

if(ans):
	print("YES")
else:
	print("NO")