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

		- void* as left value, can point to any type of data(Think of void* is a base class, other is derived class)

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
		
			- If a function dosenot have  return value, it must be explicitly declared as void.Or C will automatically return int type.
			- In C++ If a function dosenot have parameter, it must be explicitly declared as void. Or C++ will return "error: funciton dosed not take 1 parameters. " But C will tell you no problem. So for safety, explicitly declare void parameter.
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
			
			- ***static in global region***: **global variable** & **static variable**; **Initialized** and **Uninitialized** are seperately put in adjacent two memory region; **Computer System** will free at the end of program.
			
			- ***const in global region***: Store string const and other const; **Computer System** will free at the end of program.

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
			// If you put the code "int *p_test2" below the code"int *p", it will output [e3] at "printf("int*p data:  %d\n", *p)"
			// It is because [p_test2=0x40038a, p = 0xf63d4e2e], maybe you cannot access the address # 0xf63d4e2e
			// So where is 0x40038a, p = 0xf63d4e2e, heap/stack/global I am not sure. Why can't I access the address # 0xf63d4e2e.
		
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

		- 1. 3 steps for indirect assignment
			```
			int num = 0;
			int *p = NULL;	// 1. set 2 variable
			p = &num; 	// 2. set connect between them
			*p = 2;	// 3. use * to assign value
			```
	
	- Advanced 3 : Understanding of Pointer + 4 Region of Memory
	
	- Advanced 4 : Use of Pointer + Function callback (pointer as function parameters)
	
#### [***Chapter_Three***] : String

- 3.1 Basic String Manipulation

	- 3.1.1 String Initialize
	
		- Difference between **sizeof** and **strlen**

			- **sizeof** is a operator, result fixed during compile; **strlen** is a function, result output at run time;

			- For char array, **sizeof** include **'\0'**, **strlen** dosenot include **'\0'**. 


			```
			//3.1.1 init char array
			int main(void)
			{
				// 1 Not assign lenth, Compiler will automatically calculate lenth
				char buf1[] = {'a', 'b', 'c', 'd'};
				// 2 assign lenth, buf[4-99] = '\0'
				char buf2[200] = {'a', 'b', 'c', 'd'};
				// char buf3[2]= {'a', 'b', 'c', 'd'};
				// over lenth, Compiler error
				printf("buf1: %s \n", buf1); // # abcd 
				printf("buf2: %s \n", buf2); // # abcd 
				printf("buf2: %d \n", buf2[88]); // # 0

				// 3 use string to init, 
				char buf3[] = "abcd";
				// buf3 as char array with 5 byte
				printf("buf3 length as string : %d \n", (int)strlen(buf3)); // # 4
				// buf3 as string with 4 byte
				printf("buf3 length as char array : %d \n", (int)sizeof(buf3)); // # 5

				char buf4[128] = "abcd";
				printf("buf4[100]: %d \n", buf4[100]); // # 0
			}
			```
		- Difference between char '\0', number 0, NULL, char '0';
		
			- 1. char '\0' is a char whose ASSCII encode value is 0. 
			
			- 2. char '\0' equals to number 0. '\' is escape char.
			
			- 3. NULL is a macro in (stdio.h) whose value is number 0 = char '\0'.
			
			- 4. char '0' is char whose content is '0' and ASSCII encode value is 48.
			


- 3.3 String as Function Parameter

	- copy string, remember add '\0'
	```
	int main(void)
	{
		char a[] = "I am a student";
		char b[64];
		int i = 0;
		for ( i =0; *(a+i)!='\0'; i++)
		{
			*(b+i) = *(a+i);
		}
		b[i] = '\0'; // important
		printf("a:%s \n", a);
		printf("b:%s \n", b);
	}
	```
	- Donnot change formal parameters, add an temporary parameter to replace formal parameter
	```
	int copy_str6(char *from, char* to)
	{
		char *tmpfrom = from;
		char *tmpto = to;
		if ( from == NULL | to == NULL)
		{
			return -1;
		}

		while(*tmpto++ = *tmpto++);
		printf("from:%s\n", from);
		return 0;
	}
	```

#### [***Chapter_Four***] : Pointer more and more

- Const
	
	- const declare the variable as readonly
	
		```
		char buf[100] = "abcdef"
		```
		- const char *p = buf
		
			same as char *p = "abcdef"， is literal constant 
		
		- char const *p = buf
			
			pointer can redirect, but memory cannot change
			```
			p = '123456'; // ok
			```
		
		- char * const p = buf
		
			pointer cannot redirect, but memory can change
			```
			p[0] = '1';
			```
		
		- const char const *p = buf
			
			read only, both pointer and memory cannot change

- Multi-level Pointer

	- How to define appropriate pointer variable
	```
	int b;
	int *p = &b;		// first level
	int **t = &p;		// second level
	int ***m = &t;		// third level
	```
	- Second level pointer as output
	
		Must use address transfer for **formal parameters** >>> **arguments**.
		```
		char *p1 = NULL;		// Doesnot alloc memory
		int len = 0;
		getMem(&p1, &len);		//  Must use address transfer for formal parameters >>> arguments.
		
		void getMem(char **p1 /*out*/, int *plen/*int*/)
		{
			*p1 = malloc(100);	// Indirect assignment is the biggest meaning of pointer
			*plen = 100
		}
		```
	
	- Second level pointer as input (3 kind of memory model)

		The most important thing of second level pointer is step. Sometimes different second pointer point to same address, but their steps vary from the way determining them.
		
		- 1. Pointer **array**
		
			- Actually it is the **array** that matter compared with the **array pointer** who emphasizes pointer. Check more detail in 5.3
		
			<img src = 'pic/pointer_array.jpg' width="500" height="200" />
		
			- Conclusion, if your want to use second pointer to point to a list of strings in global region, your must define an pointer array first. Then use the second pointer to point to the pointer array.
			```
			// char **p ={"aaaa", "cccc"}; // error scalar object ‘p’ requires one element in initializer
			char *myArray[] ={"aaaa", "cccc"}; // myArray is an array in stack, ang every element is char*
			char **p = myArray; 		   // myArray[] = *myArray
			```
			
			- Obviously, for pointer array, it allocate memory in stack for pointer and use this pointers in pointer array to point to the const memory in global memory region which has allocated by compiler before.
			- You cannot actually sort the data in global memory region, you can only change their pointer value in stack. So if you want to sort this array, what you will do is change the pointer value.
			```
			void sortMyArray(char **myArray, int num);
			```
			
			- Pointer array as formal parameter
			```
			void fun(char **str[]);
			void fun(char **str);	// str[]->*str
			```
			
			- Pointer array in main
			```
			int main(int argc, char *argv[])
			
			: demo.exe a b test
			int argc = 4
			char *argv[] = {"demo.exe", "a", "b", "test"}
			```

		- 2. Two dimentional array
		
			<img src = 'pic/2_dimentional_array.jpg' width="500" height="200" />
			
			- Two dimention array must be initlize with value.
			```
			// char a[][30]; // # error storage size of ‘a’ isn’t known
			char a[10][30] = {"aaa","bbb", "ccc", "111"};
			```
			- Step in array
			
				&a = a = &a[0] but their steps vary with each other
				```
				printf("&a: %p \n", &a);		// # 0x7ffded01e0a0 
				```
				
				- a is the address of first item"aaa", not the address of the 2-d array
				```
				printf("a: %p \n", a);			// # 0x7ffded01e0a0
				```
				
				- &a is the address of the 2-d array
				```
				printf("&a[0]: %p \n", &a[0]);	// # 0x7ffded01e0a0 
				```
				
				- &a[0][0] is the address of the 1st item of 1-d array which is the 1st item of the 2-d array
				```
				printf("&a[0][0]: %p \n", &a[0][0]);	// # 0x7ffded01e0a0 
				printf("a[0][0]: %c \n", a[0][0]);      // a
				```
				
				- &a + 1 = &a + 30*4 byte
				```
				printf("&a+1: %p \n", &a+1);	        // # 0x7ffded01e1cc  
				```
				
				- a+1 = a + 30 byte
				```
				printf("a+1: %p \n", a+1);		// # 0x7ffded01e0be  
				```
				
				- (&a[0])++ = a + 1 byte
				```
				printf("a[0]+1: %p \n", a[0]+1);// # 0x7ffded01e0a1
				```
				
				- a[0][0]+1 = ASSCI(a) + 1 = b 
				```
				printf("a[0][0]+1: %c \n", a[0][0]+1);  // b
				```
				
			- Don't use char **buf  as formal parameter for two dimention array, use char buf[10][30].
				Because their step is different. char ** is 4 byte, char[][30] step is 30 byte.
			
			- If you want to sort this array, you actually sort their string value , which is not like 1rd method that just change their pointer.
			
				```
				void sortMyArray(char myArray[10][30], int num);
				```
			
			- Obviously, this kind of pointer easy to lead to stack overflow because it allocate memory for string value not string's pointer in stack. So for big array, use the 3rd methods to allocate memory in heap.
			
			
		- 3. Dynamicly allocate memory 
		
			<img src = 'pic/dynamic_allocate_pointer.jpg' width="500" height="200" /> 

			```
			int b[3];
			int *q = (int*) malloc(3 * sizeof(int)); // equal to 9[3]

			int n =3;
			char **buf = (char **)malloc(3 * sizeof(char*));// equal to char *buf[3]
			printf("&buf: %p \n", &buf);						// stack # 0x7ffe0a65df30  
			printf("buf: %p \n", buf);							// heap # 0x1693030 
			for (int i = 0; i < n; i++)
			{
				buf[i] = (char*)malloc(30 * sizeof(char));
				printf("&buf[%d]: %p \n", i, &buf[i]);			// heap # 0x1693030 0x1693038 0x1693040
				printf("buf[%d]: %p \n", i, buf[i]);			// heap # 0x1693050 0x1693080 0x16930b0
			}
			// buf in stack; char* in heap; char in heap

			char **myArray = NULL;
			printf("&myArray: %p \n", &myArray); 				// stack # 0x7ffe0a65df40 
			```
			
			- Sort is the same as 1rd method
			```
			void sortMyArray(char **myArray, int num);
			```

#### [***Chapter_Five***] : Multi-dimentional Array	

- Basic
	- Notion of array
	
		- item: an ordered set with variables of same type.
		
		- memory: a big continuous memory region.
		
	- 2-D array
	
		There is no direct type of multi-dimentional array in C. The 2-D array is a special 1-d array that is defined by a nested syntax.
		
		- Definition
			```
			int a[3][4];
			```
		
		- Name of array
			
			Name of array is the address of the first item in array. It is a **const value**. 
			
			So, once you define the name, you cannot change. For variable is alias of memory. Once the array is defined, the memory is fixed.
			
			The address of first item of array = the address of array (check it in 4.2.2)
			
- Type of array

	The type of array is determined by item type and number of item in array. 
	
	typeof(int array[5]) == **int[5]**
	
	You could define your own array **type** by typedef.
	
	```
	typedef int MYARRAY[5]; == typedef int (MYARRAY)[5]; // define a new type MARRAY as int[5]
	int array[5]; == MYARRAY array;		             // define a variable it is an array
	```

- Pointer array and array pointer

	The difference between the definition of them is just an (parantehsis) on ***name**.
	
	Remember the later of their name is the significance.

	- Pointer **array** (4.2.3.1)
	
		An array with many pointer items in it.
		```
		char *pointer_array[4];	// 4 means there is 4 pointers in the array in stack. 4 could be removed as you can add manin pointers as you can to stack like main(int argc, char *argv[]) does.
		```
		
	- Array **pointer**
		
		A pointer points to an array with fixed type. There are 3 ways to define an array pointer.
		
		- 1st Directly
			```
			int (*array_pointer)[4]; An pointer points to a memory for a array whose type is int[4], which means there is 4 int item in the array.
			```
			
		- 2ed By array type
			```
			typedef int(MYARRAY)[5];
			MYARRAY *array_pointer;
			```
			
		- 3rd By array pointer type
			```
			typedef int(*MYARRAY)[5];
			MYARRAY array_pointer;
			```
			
		If we have an ```int a[10];```
		then we can define by ```array_pointer = &a;```

- Essence of Multy-dimention Array

	<img src = 'pic/int_a35.png'  />
	
- Degration of M-D array

	 - 1-D array as function formal parameter degrate to 1st level pointer.
	 
		```
		void print_array(int arr[10]);	// 10 could be erase because the step is always 1. 10 elements in the 1-D array.
		void print_array(int arr[]);
		void print_array(int* arr);	// 1st level pointer
		```
	 
	 - 2-D array as function formal parameter degrate to array pointer.
	 
	 	- 3 mode for M-D array as formal parameter
	 
			Second bracket must be filled. means step for a. a+1 = a+step

			```
			void print_array(int a [3][5]);	// step = 5 * sizeof(int)
			void print_array(int a [][5]);
			void print_array(int (*a)[5]); // array pointer
			```
			
	- The reason for degration
	
		When deal with a[5], C doesnot care what is in a, and it dose not know 5 is 5. Its only care about &a[0]: the address of first element.


#### [***Chapter_Six***] : Struct

- Definition and type of struct

	struct is an kind of constructed data type. It is used to combine different data type together in order to build our own data type.
	
	- Declaration of struct
	
		```
		struct Teacher
		{
			char name[32];
			int age;
		};
		```
		
		Remember **;**
		
		***struct Teacher*** is a type not just Teacher.
		
		But you could use typedef to rename struct Teacher as Teacher.
				```
		typedef struct Teacher
		{
			char name[32];
			int age;
		} Teacher;
		```
		
		
	- 3 ways of definition and intilization of struct variable
	
		- First struct type, then struct variable
			```
			struct Teacher a = {"Lili", 22};
			```
		
		- struct type, then struct variable
			```
			struct Teacher
			{
				char name[32];
				int age;
			}c = {"Lili", 22};
			```
		
		- not struct type , directly struct variable
			```
			struct
			{
				char name[32];
				int age;
			}e = {"Lili", 22};
			```
			
	- Manipulation of struct
	
		- variable, use .
			```
			struct Stu h;
			strcpy(h.name, "Amos");
			(&h)->name
			```
		
		- pointer, use ->
			```
			struct Stu h;
			strcpy(p->name, "abc");
			(*p).name
			```
			
	- Struct array
		```
		Teacher t1[2] = 
		{
			{"Lili", "teacher"},
			{"Lilei", "teacher"}
		};
		Teacher t1[2] = {"Lili", 18, "Lilei", 22};
		```
		
	-  Struct with pointer
		```
		typedef stuct Teacher
		{
			char *name;
			char **stu;
			int age;
		} Teacher;
		```
		
	- Value assigment for struct
		Teacher t2 = e;
		
	- Deep copy and swallow copy
	
		struct with point + dynamic memory alloc
		
		```
		typedef stuct Teacher
		{
			char *name;
			int age;
		} Teacher;
		Teacher t1, t2;
		t1.name = (char*)malloc(30);
		strcpy(t1.name, "Lili");
		t1.age = 22
		
		// swallow copy, different struct pointer variable points to the same memory.
		t2 = t1;
		// deep copy, you alloc a new memory by hand for the new pointer
		t2.name = (char *)malloc(30);
		strcpy(t2.name, t1.name)
		
		```
		
	- Memory alignment
		```
		#pragma pack(XX)
		#pragma pack(1)	// 1 byte alignment
		#pragma pack(2)	// 2 byte alignment
		#pragma pack(4)	// 4 byte alignment
		```


###  [***Chapter Seven***] : File

- Open and Write of standard file
	
	- FILE
			
		FILE is a standard C struct define by C for file. It include some brief information for the file.
		```
		#include <stdio.h>
		FILE *fp;
		```
		
	- fopen()
		```
		fopen(char *filename, char *type);
		```

		- fopen will return a pointer to a file if it success; return NULL if faile.
		
		```
		if((fp = fopen("test", "w"))==NULL)
		{
			printf("File cannot be open\n");
			exit();
		}
		else
		{
			printf("File open sucessfully");
		}

		fclose(fp);
		```

		- There are 3 default file pointer in C;
		
			- stdin: standard input from keyboard; You can use **scanf**, **getchar**;

			- stdout: standard output to screen. You can use **printf**, **puts**;
			
			- stderr: standard error output to screen. You can use **perror**
	- fclose()
		```
		int fclose(FILE* stream);
		```
		
		If it close a file sucessfully it will return 0; it not 0; Everytime will complete manipulation on a file, we **must** close it or the change will store in buff not on memory. Usually we can test if a file is closed sucessfully by these way:
		```
		if(fclose(fp)!=0)
		{
			printf("FILE cannot be closed");
			exit(1);
		}
		else
		{
			printf("File is now closed");
		}
		```
		
	- File read and open
	
		- Read char in file, one time one char
			```
			int fgetc(FILE *stream); // char = fget(fp); if the end of file(flag "EOF"), return '-1'
			int fputc(int ch, FILE* stream);
			
			int getc(FILE *stream);
			int putc(int ch, FILE *stream);
			```
			
			- Check end of file for deciding if continue certain operation on file
			```
			char ch;
			if(fp = fopen("myfile.txt", "r")==NULL)
			{
				printf("file cannot be openned");
				exit(-1);
			}
			while(ch=fget(fp)!=EOF)
			{
				fputc(ch, stdout);	// write ch into stdout and output to screen
			}
			
			fclose(fp);
			return 0;
			```
			
		- Read string in file
			```
			char *fgets(char *string; int n; FILE *stream);	// read n-1 chars into string 
			int fprintf(FILE *stream, char *format, ...);
			int fputs( char*string, FILE *stream);
			```
			
			- fgets(), feof(), ferror
			```
			fgets(buffer, 9, fp); // read 8 chars into buffer in fp; buffer could be in stack or heap(malloc)
				// fgets will stop when meet '\n' whatever the number and add a '\0' at the end of buffer
		     	        // retun a pointer to the string
			        // return NULL if at the end of file of error
			
			
			char str[128];
			while(!feof(fo))
			{
				if(fgets(str, 128, fp)!=NULL)
				{
					printf("%s", str);
				}
			}
			```
			
			- fputs()
			```
			fputs("Your score if TOFELS is", fp); // write string into fp
			fputs(":", fp);
			```
			
			-  fprintf()
			
				same as printf(). printf() to screen, fprintf() to file
			```
			int i = 67;
			char *s="That is a good news";
			fprintf(fp, "%d\n", i)
			fprintf(fp,"%s", s);
			// out put : Your score of TOEFL is: 617
			//	     That's good news
			```
			

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
