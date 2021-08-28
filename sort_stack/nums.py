import random
lim = 500
randomlist = []

while len(randomlist) != lim:
	n = random.randint(1, lim)
	if n in randomlist:
		continue
	randomlist.append(n)

for i in randomlist:
	print (i, end = ' ')
