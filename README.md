# Push_swap
<div align="center">

![badge](https://github.com/humbertoarndt/humbertoarndt/blob/main/42_badges/push_swape.png)  

</div>

## About
The project goal is to write a program in C called `push_swap` which sorts a given list of random number using two stacks and a limited set of operations (swap, rotate, reverse rotate and push), using the minimum of action possible.

## Usage
Git clone the repository. Then use `make`to compile it.  
```git clone https://github.com/humbertoarndt/push_swap.git```  
```make```  
Run it as:  
```./push_swap <list>```  
The list provided must attend the following condition:
* Do not contain arguments that are not integer;
* Do not contain arguments bigger than integer;
* Do not contain duplicated arguments;
If the arguments are valid, the program will output the list of action to sort the list.

You can visualize this `push_swap`algorithm in action with [O-reo's push_swap visualizer](https://github.com/o-reo/push_swap_visualizer).