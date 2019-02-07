# Thinking

## Further Thinking

Basic mathematics

​	principle of adder

​	use linked list

## Best Solution for C++

**Malloc()** is needed for adding an element into a list list

Use recursion to reduce the amount of code



## Question

In the runtime error code, all the grammar are in C. However, in the test platform, it throws "demalloc" runtime error, which makes me confused.



## Reference

作者：DEMON_JC 
来源：CSDN 
原文：https://blog.csdn.net/weixin_38885154/article/details/80186186 

C++中有了malloc/free,为什么还需要new/delete？
1.malloc/free是C++/C语言的标准库函数，new/delete是C++运算符，

它们都可进行动态内存和释放内存。

2.对于非内部数据类型的对象而言，光用malloc/free无法满足动态对象的要求

由于malloc/free是库函数不是运算符，不在编译器的权限之内，不能够把执行构造函数和析构函数的任务强加于malloc/free.

3.C++需要一个能完成动态内存分配和初始化工作的运算符new，一个能完成清理与释放工作的运算符delete。

