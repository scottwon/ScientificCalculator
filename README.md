# Scientific Calculator
This is the course project for 'Data Structure'.

In this project, I designed a text-parsing framework that is able to handle most of the usual operators and functions in the mathematical expressions and calculate the value of the expressions.

The general text-parsing process of my scientific calculator is as follows:

1. To match the strings/characters of the operators and the function names. In my scientific calculator, there is a built-in binary tree whose leaf nodes store all information for the supported functions. If the name matching process is failed, an exception will be thrown and the information of the gramatical error will be printed on the screen. If the name matching process is successful, then we will get the leaf node that store the information of the corresponding function.

