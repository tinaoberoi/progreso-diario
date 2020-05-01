t = int(input(""))
while(t):
	s = input("")
	list_l = []
	list_r = []
	l = len(s);
	ans = 0
	if(l == 1 or l == 2):
		print("YES")
		break
	else:
		temp_l = s[1:] + s[0];
		temp_r =  s[l-1] + s[:l-1]
		flag = False
		for i in range(1, l):
			if(temp_l == temp_r and flag == False):
				flag = True
			temp_l = s[1:] + s[0];
			temp_r =  s[l-1] + s[:l-1]
			if(flag and temp_l == temp_r):
				ans = 1
				break
		if(ans):
			print("YES")
		else:
			print("NO")
	t-=1