var = input()
#print(var)

list1 = var.split("+")
#print(list1)

list1.sort()
ans = list1[0]

for i in range(1,len(list1)):
	ans+="+"
	ans+=list1[i]

print(ans)
