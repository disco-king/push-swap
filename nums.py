import random
lim = int(input())
randomlist = []

while len(randomlist) != lim:
	n = random.randint(1, lim)
	if n in randomlist:
		continue
	randomlist.append(n)

for id, val in enumerate(randomlist):
    if id != lim - 1:
        print (val, end = ' ')
    else:
        print (val, end = '')
