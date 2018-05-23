# Advanced C review notes

This is a page for advanced C. 

- For basic knowledge of C, I recommend read the following blog:

	[http://www.runoob.com/cprogramming/c-tutorial.html](http://www.runoob.com/cprogramming/c-tutorial.html).

- The recommend editor is [sublimetext3](https://www.sublimetext.com/3). For use of sublime, please follow this blog [Sublime Text3 keyboard shortcuts summary](https://www.jianshu.com/p/d5441fb2ccae).

- The recommend platform is [linux ubuntu 14.04](http://releases.ubuntu.com/14.04/).

- For Mac, I recommend you install ubuntu by Parallels, you can follow this youtube video [Install Ubuntu on Mac with Parallels 10](https://www.youtube.com/watch?v=PApudf-ftkU).

- All of the code in this page could be found in [test.cpp](test.cpp). You could uncomment, then compile and run.

### Tutorials
Here we recommend two tutorials for learning C programming language. Actually, the first one is a good start point for beginners. The book is about 200+ pages but is concise and clear. There are many code examples in C included by the second one. You may also refer to the [CMU 15-213](https://www.cs.cmu.edu/~213/).

- Brian W. Kernighan and Dennis M. Ritchie, The C Programming Language, Second Edition, Prentice Hall, 1988

- Randal E. Bryant and David R. O'Hallaron, Computer Systems: A Programmer's Perspective, Third Edition, Pearson, 2016 

### [***linux terminal compile and run***]
```
new a file called test.cpp: touch  test.cpp
compile: gcc -o test test.cpp
Run: ./test
```

### C file format
```
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
int main()
{
    int a = 10;
    printf("the file format: %d\n",a);
    return 0;
}
```
### [***Knowledge Note***]

#### [***Chapter_One***] : 4_Region_of_Memory

- 1.1 Data Type

	- 1.1.1 Classification of data type
	
		- simple: basic type(int,float/double, char, void), user-define-type/enum
	
		- struct:array[], struct, union, class
		
		- pointer: *

	- 1.1.2 Essence of data type： [**alias of fixed space of memory**]

		- Function： **Compiler** pre-calculate space of memory to be alloced, but it has not alloc. Only when the **variable** be created will the memory be alloc.

		```
		int a = 10
		"int"  tell Compiler to alloc 4 byte memory. When compile see "a", it will alloc. 
		```

	- 1.1.3 Size of data type

		- sizeof is operator，the same as (+ — * /), it is not a function.  Size will be return after compile.


		```
		// note the %zu, should not be %d, or it will return [e1];
		printf("sizeof(a): %zu \n", sizeof(a))
		```

	- 1.1.4 Rename of datatype

	```
        // rename for struct
        typedef struct People
        {
	        char name[64];
	        int age;
        } people_t;
        // rename for unsigned int
        typedef unsigned int u32;
	```

	- 1.1.5 Void(Data Encapsulating: "nothing is impossible" type)

		- void* as left value, can point to any type of data

		```
		void* memcpy( void* dest, const void* src, size_t len );
		void* memset( void* buffer, int c, size_t num );
		void* malloc (size_t size);
		```
		
		- void* as right value, must be casted to other type of point, because ***C define only the same type of pointers can be allowed to assign with each other***.
		```
		char* p2 = (char*)malloc(sizeof(char)*20)
		```
		
		- void in function **pramater** and **return value**, means nothing.
		```
		int function(void)
		{
			return 1;
		}
		void function1(void)
		{
			return;
		}
		```
		
		- No void type variable
		
			C does not define the size of memory for void.

- 1.2 Variable
	- 1.2.1 Definition of Variable
	
		- Memory that can be read and write.
		
		- Alia of a continuous size of memory.
		
- 1.3 Model of Memory
	- Work flow

		- 1. Computer system loads C code to memory.
		
		- 2. Computer system seperates C code into 4 region.
		
			- ***stack***: **Compiler** **automatically** memory alloc and free; Store **function paramerter** and **local variable**.
			```
			char *getMem2()
			{
				char buf[64];	//  temporary local variable in stack
				strcpy(buf, "123456");
				printf("buf: %s\n", buf); // # buf: 123456
				return buf; // return the first address of memory block , not the 64 byte
			}
			```
			
			- ***heap***: **Programmer** alloc and free(dynamic memory alloc and free); If Programmer not free, **Computer System** will free it at the end of program;
			
			```
			char *getMem(int num)
			{
				char *p1 = NULL;
				p1 = (char*)malloc(sizeof(char)* num); // dynamic memory alloc in heap
				if (p1 == NULL)
				{
					return NULL;
				}
				return p1; // return head of memory block of num byte
			}
			// for test code, please check test.cpp 1.3.1
			```
			
			- ***static***: **global variable** & **static variable**; **Initialized** and **Uninitialized** are seperately put in adjacent two memory region; **Computer System** will free at the end of program.
			
			- ***const***: Store string const and other const; **Computer System** will free at the end of program.

			```
			//1.3.2 global 
			// note should use const, or it will output warning/error [e2]
			const char *getStr1()
			{
				const char *p1 = "abcdefg2";
				return p1;
			}
			const char *getStr2()
			{
				const char *p2 = "abcdefg2";
				return p2;
			}
			// for test code, please check test.cpp 1.3.2
			```
			
			- ***code***: Store binary code of function.
			
- 1.4 Model of Function Callback

<img src = 'pic/Funtion_Callback_Model.png' width="800" height="300" />

- 1.5 Analyze of Varibale Transfer During Function Callback

	<img src = 'pic/stack_heap_global.png' width="500" height="300" /> <img src = 'pic/variable_transfer.png' width="250" height="300" />

	- 1. main could alloc on **stack/heap/global**, this variable could be used by func1 & func2;
	
	- 2. Memory on **stack** alloced by func2, could **not** be used by func1 & main;
	
	- 3. Memory on **heap** alloced by func2, could be used by func1 & main;
	
	- 4. Memory on **global** alloced by func2, could be used by func1 & main;

- 1.6 Direction of stack and memory.

	- [stackflow-stack-address-grow-towards-decreasing-memory-addresses](https://stackoverflow.com/questions/4560720/why-does-the-stack-address-grow-towards-decreasing-memory-addresses)
	
	<img src = 'pic/stack_grow_direction.png' width="500" height="300" /> 

	```
	// 1.6.1 stack_grow_direction 
	int main(void)
	{
		int a;
		int b;
		char buf[4];
		printf("&a: %p\n", &a); // # &a: 0x7fff51f11eb8
		printf("&b: %p\n", &b); // # &b: 0x7fff51f11ebc
		printf("Address of buf : %p\n", &buf[0]); // # 0x7fff51f11ec0
		printf("Address of buf+1: %p\n", &buf[1]);// # 0x7fff51f11ec1
		return 0;
	}
	// 这里我测试的地址是 a低，b高，但a是先压栈的，b是后压栈的，如果按照栈从高地址开始的解释话，
	// 就不对了，所以我电脑（macbook虚拟机Ubuntu14）上应该是栈也从低地址开始压，所以和内存生长是一个方向了？
	```
	
	<img src = 'pic/stack_heap.png' width="500" height="300" /> 

	```
	// 1.6.2 stack_heap_practice
	char *get_mem(int size)
	{
		char *p2 = NULL;
		p2 = (char*)malloc(size);
		printf("p2 point address: %p\n", p2); // heap # 0x20bf010
		return p2;
	}
	int main()
	{
		char buf[100];
		printf("buf point address: %p\n", buf);	// stack #0x7ffdf9e993e0
		printf("buf[0] point address: %p\n", &buf[0]); // stack # 0x7ffdf9e993e0
		printf("buf[1] point address: %p\n", &buf[1]); // stack # 0x7ffdf9e993e1
		printf("buf[0] point data: %d\n", buf[0]); // # -1
		printf("buf[1] point data: %d\n", buf[1]); // # -1
		printf("buf[98] point data: %d\n", buf[98]); // # -23
		printf("buf[99] point data: %d\n", buf[99]); // # -7
		printf("buf[100] point data: %d\n", buf[100]); // # -3
		printf("buf[101] point data: %d\n", buf[101]); // # 127
		int a = 10;
		printf("int a point address: %p\n", &a);	// stack #  0x7ffdf9e993b4
		printf("int a datas: %d\n", a);	// # 10

		int *p_test0;
		printf("int*p_test point address: %p\n", p_test0); // stack # 0x7ffdf9e993f0
		int *p_test1;
		printf("int*p_test1 point address: %p\n", p_test1); // stack # 0x7ffdf9e993e0

		int *p_test2;
		printf("int*p_test2 point address: %p\n", p_test2); 
		// # 0xf63d4e2e # this is a nochange sapce like the following 0x40038a
		// If you put the code "int *p_test2" below the code"int *p", it will output [e3] at "printf("int*p data: 		  // %d\n", *p)"
		// It is because [p_test2=0x40038a, p = 0xf63d4e2e], maybe you cannot access the address # 0xf63d4e2e
		// So where is 0x40038a, p = 0xf63d4e2e, heap/stack/global I am not sure. Why can't I access the address #    		      // 0xf63d4e2e.
		int *p;
		printf("int*p point address: %p\n", p);	//  # 0x40038a ??? I am not sure if p in heap or stack, 
							// since it never changes after I add several print buf.
							// But the stack result like buf change every time I run.
							// Or perhaps it randomly point to a fixed space for point initilize.
							// For p_test0, p_test initialize, the result obvioulsly in stack,
							// But for p_test2, result never fixed like p

		printf("int*p data: %d\n", *p);	// stack # 1768709983
		p = &a;
		printf("p point address: %p\n", p); // stack #  0x7ffdf9e993b4
		*p = 20;
		printf("int*p 20 data: %d\n", *p);	// # 20

		char *mp = get_mem(100);
		printf("mp point address: %p\n", mp); // heap # 0x20bf010
		strcpy(mp, "ABCDEFG");
		printf("mp memory data: %d\n", *mp); // # 65

		if (mp != NULL)
		{
			free(mp);
			mp = NULL;
		}
		printf("mp after free: %p\n", mp); // # (nil)
	}
	```

#### [***Chapter_Two***] : Pointer

- 2.1 Advanced Pointer

	- Advanced 1 : Pointer is a kind of **data type**.
	
		- 1. Pointer variable is a kind of variable, so it will occupy memory space to store memory address.
		
		- 2. *p manipulates memory.
		
			- During declaration, * used for decalaring a variable is a pointer. int *p;
			
			- During usage, * means the data in the paticular memory that the pointer points to. 
			```	
			*p = 10; // left of equal-sign , write memory
			 a = *p; // right of equal-sign, read memory
			```
		
		- 3. Make sure memory block that the pointer points to is revisable.
		
		- 4. The type of pointer is defined by the type of data in memory its points to.
			```	
			int a;
			int *p = &a;
			p++;	// the step is defined by the type of data, for example heres is int(2/4 byte).
			```
		- 5. C don't allow copy memory to NULL and unknow illegal address.

	- Advanced 2 : (*p) Indirect method of accessing variables is the biggest meaning of pointer.
	
	- Advanced 3 : Understanding of Pointer + 4 Region of Memory
	
	- Advanced 4 : Use of Pointer + Function callback (pointer as function parameters)

###  [***Common Error & Solution***]
**[e1]** ``` ‘%d’ expects argument of type ‘int’, but argument 2 has type ‘long unsigned int’ ```

**[s1]** 1.1.3  %d -> %zu

[stackflow-d-expects-argument-of-type-int-but-argument-2-has-type-long-unsigned-int](https://stackoverflow.com/questions/21128092/d-expects-argument-of-type-int-but-argument-2-has-type-long-unsigned-int)

**[e2]** ```warning:  deprecated conversion from string constant to ‘char*’ ```

**[s2]** 1.3.2  char* -> const char*

[https://stackoverflow.com/questions/1524356/c-deprecated-conversion-from-string-constant-to-char](https://stackoverflow.com/questions/1524356/c-deprecated-conversion-from-string-constant-to-char)

**[e3]** ```segmentation faul```

**[s3]** 1.6.2 rearrange code, check if the pointer access unreadable memory 

[https://stackoverflow.com/questions/2346806/what-is-a-segmentation-fault](https://stackoverflow.com/questions/2346806/what-is-a-segmentation-fault)
