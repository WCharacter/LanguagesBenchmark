import time

tests_amount = 10

def test():
	beg = time.time()
	vals = [(i, str(i)) for i in range(0, 10000000)]
	sm = sum(i for i, _ in vals)
	print(sm)
	end = time.time()
	elapsed = int((end - beg) * 1000)
	print(f"Elapsed {elapsed} ms.")
	return elapsed

total = 0	
for i in range(0, tests_amount):
	total += test()
	
mean = total / tests_amount
print(f"Mean: {mean} ms.")