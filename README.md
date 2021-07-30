# iqpuzzle
This is a small program to solve the triangle puzzle with the golf tees.

When you go into a place like Cracker Barrel, and you see the game on the table, now you'll know how to solve it.

To use this project, just compile all these files into one executable and launch it on the command line.  It's all done with standard C++, so it should work on most systems.  The output will tell you the moves in (x,y) form, starting with (0,0) in the corner.

I wrote the first version in 2004, so it's using the coding style from that period.

Here are a couple of generated solutions.  The coordinates are x, y.  You can think of x as index into a row.


	From: 0, 2	to	0, 4
	From: 2, 2	to	0, 2
	From: 0, 4	to	2, 2
	From: 0, 1	to	0, 3
	From: 2, 1	to	0, 1
	From: 3, 1	to	1, 3
	From: 0, 0	to	0, 2
	From: 0, 3	to	0, 1
	From: 2, 0	to	0, 0
	From: 0, 0	to	0, 2
	From: 4, 0	to	2, 0
	From: 1, 2	to	1, 0
	From: 3, 1	to	1, 1


	From: 0, 2	to	0, 4
	From: 2, 2	to	0, 2
	From: 0, 4	to	2, 2
	From: 0, 1	to	0, 3
	From: 3, 0	to	1, 2
	From: 2, 2	to	0, 2
	From: 0, 2	to	0, 4
	From: 0, 0	to	2, 2
	From: 3, 1	to	1, 3
	From: 0, 4	to	2, 2
	From: 1, 0	to	3, 0
	From: 4, 0	to	2, 0
	From: 2, 0	to	0, 0

