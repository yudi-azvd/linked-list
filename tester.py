#python3
# -*- coding: utf-8 -*-

import os
import sys
from time import time

N = 17 # number of test cases

def create_w_file(filename, w):
	f = open(filename, 'w')
	f.write(w)
	f.close()

def generate_tests():
	"""
	just count how many files there are and assume half 
	are/is the tests and the other half are/is the answers 
	"""

	# tests should have files in sorted order
	# .txt, a
	# in the end, tests should have a even number of items

	# tests = []
	# argv = sys.argv[1:]
	# isolated_tests = [arg for arg in argv]

	# if len(argv) > 0:
	# 	if "-" in argv:
	# 		for i in range(int(argv[0], int(argv[2])+1)):
	# 			tests.append(str(i))
	# 	else:
	# 		tests = [test for test in isolated_tests]
	# else:
	# 	abs_path = os.path.abspath("")
	# 	tests = os.listdir(abs_path+"/tests")

	# if "gen.py" in tests:
	# 	tests.remove("gen.py")
	
	# N = len(tests)

	# return tests

	########################################

	abs_path = os.path.abspath("")
	all_tests = os.listdir(abs_path+"/tests")

	print(abs_path)
	print(all_tests)

	argv = sys.argv[1:]
	isolated_tests = [arg for arg in argv]

	if len(isolated_tests) > 0:
		if "-" in isolated_tests:
			tests = range(int(argv[0]), int(argv[2]))  # gen tests from a - b
		else:
			tests =  [test for test in isolated_tests] # isolated tests (34, 21, 3)
	else:
		tests = [str(test) for test in range(1, N+1)]  # all tests

	# return [] 
	return tests

def get_number_from_str(string):
	# assumes just one number in string
	number = ""
	for char in string:
		if char.isdigit():
			number += char
		else:
			break
	return int(number)

def main():
	score_filename = "score.txt"
	name = "calculator"
	run_progr = "./" + name
	compile_progr = "gcc -Wall -ansi -std=c99 " + name + ".c" + " -o " + name + " -lm"
	tests = generate_tests()

	create_w_file(score_filename, "0")

	os.system(compile_progr)

	for test in tests:
		print("TEST CASE #", test)
		test_filename = "tests/"
		answ_filename = "tests/"

		test_filename += test + ".txt"
		answ_filename += test + "a"

		print('‾'*15)
		# start = time()
		os.system(run_progr + " " + test_filename + " " + answ_filename)
		# end = time()
		# print(end-start)
		print('_'*15)

	f = open(score_filename, 'r')
	score = int(f.read())
	print("\n\nSCORE: %d/%d | %.2lf%%\n\n" % (score, N, score*100.0/N))
	os.system(compile_progr)

	print(sorted(tests, key=get_number_from_str))

if __name__ == '__main__':
	main()