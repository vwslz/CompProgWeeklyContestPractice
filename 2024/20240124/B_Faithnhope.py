n = int(input())
b = sorted(list(map(int,input().split())))

cnt1 = 0
for i in b:
	if i!=b[0]:
		break
	cnt1+=1
if cnt1 ==n:
	print(0,n*(n-1)//2)
else:
	cnt2 = 0
	for i in reversed(b):
		if i!=b[-1]:
			break
		cnt2+=1
	print(b[-1]-b[0],cnt1*cnt2)
