# CATLAB
CATLAB (meow) written in C++
# How to use
CATLAB is used in the same way as MATLAB: when you turn it on (with ./catlab) there is a terminal that is gonna be running until you press CTRL+C, enter ex command or destroy the program :) I dare you
## How to work with CATLAB
Super basic concept in CATLAB is of course defining variables. Variable can contain only small and big characters of english alphabet and numbers (not in the beginning tho). Declaration can be like this:
A = 120
B = 100
This is a scalar number definition
How to declare vector:
V = [ 1 2 3 4 5]
W = [5 4 3 2 1]
How to declare matrix:
M = {1 1 1 ; 2 2 2 ; 3 3 3}
Of course if the inside sizes of row would not match, you will get an error.
Default type of any number is INT. However there are two more types: FLOAT and LONG.
If you wish to type FLOAT just set the value to be in an x.y form i.e. 5.1 for example
If you with to type LONG do the same as in FLOAT but put uppercase L at the end i.e. 10.034L for example.

To simply print a variable information (its name, type and value) just type the name of the VAR and nothing more
for example:
V
results in [1,2,3,4,5]