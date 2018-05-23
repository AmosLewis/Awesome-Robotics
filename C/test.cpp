#include "stdio.h"
#include "stdlib.h"
#include "string.h"
// #include <iostream>
// using namespace std;

// 2.1 advanced pointers

// 1.6.2 stack_heap practice
// char *get_mem(int size)
// {
// 	char *p2 = NULL;
// 	p2 = (char*)malloc(size);
// 	printf("p2 point address: %p\n", p2); // heap # 0x20bf010
// 	return p2;
// }

// int main()
// {
// 	char buf[100];
// 	printf("buf point address: %p\n", buf);	// stack #0x7ffdf9e993e0
// 	printf("buf[0] point address: %p\n", &buf[0]); // stack # 0x7ffdf9e993e0
// 	printf("buf[1] point address: %p\n", &buf[1]); // stack # 0x7ffdf9e993e1
// 	printf("buf[0] point data: %d\n", buf[0]); // # -1
// 	printf("buf[1] point data: %d\n", buf[1]); // # -1
// 	printf("buf[98] point data: %d\n", buf[98]); // # -23
// 	printf("buf[99] point data: %d\n", buf[99]); // # -7
// 	printf("buf[100] point data: %d\n", buf[100]); // # -3
// 	printf("buf[101] point data: %d\n", buf[101]); // # 127
// 	int a = 10;
// 	printf("int a point address: %p\n", &a);	// stack #  0x7ffdf9e993b4
// 	printf("int a datas: %d\n", a);	// # 10

// 	int *p_test0;
// 	printf("int*p_test point address: %p\n", p_test0); // stack # 0x7ffdf9e993f0
// 	int *p_test1;
// 	printf("int*p_test1 point address: %p\n", p_test1); // stack # 0x7ffdf9e993e0
	
// 	int *p_test2;
// 	printf("int*p_test2 point address: %p\n", p_test2); // # 0xf63d4e2e # this is a nochange sapce like the following 0x40038a
// 	// If you put the code "int *p_test2" below the code"int *p", it will output [e3] at "printf("int*p data: %d\n", *p)"
// 	// It is because [p_test2=0x40038a, p = 0xf63d4e2e], maybe you cannot access the address # 0xf63d4e2e
// 	// So where is 0x40038a, p = 0xf63d4e2e, heap/stack/global I am not sure. Why can't I access the address # 0xf63d4e2e.
// 	int *p;
// 	printf("int*p point address: %p\n", p);	//  # 0x40038a ??? I am not sure if p in heap or stack, 
// 											// since it never changes after I add several print buf.
// 											// But the stack result like buf change every time I run.
// 											// Or perhaps it randomly point to a fixed space for point initilize.
// 											// For p_test0, p_test initialize, the result obvioulsly in stack,
// 											// But for p_test2, result never fixed like p

// 	printf("int*p data: %d\n", *p);	// stack # 1768709983
// 	p = &a;
// 	printf("p point address: %p\n", p); // stack #  0x7ffdf9e993b4
// 	*p = 20;
// 	printf("int*p 20 data: %d\n", *p);	// # 20

// 	char *mp = get_mem(100);
// 	printf("mp point address: %p\n", mp); // heap # 0x20bf010
// 	strcpy(mp, "ABCDEFG");
// 	printf("mp memory data: %d\n", *mp); // # 65

// 	if (mp != NULL)
// 	{
// 		free(mp);
// 		mp = NULL;
// 	}
// 	printf("mp after free: %p\n", mp); // # (nil)
// }


// 1.6.1 stack grow direction 
// int main(void)
// {
// 	int a;
// 	int b;
// 	char buf[4];
// 	printf("&a: %p\n", &a); // # &a: 0x7fff51f11eb8
// 	printf("&b: %p\n", &b); // # &b: 0x7fff51f11ebc
// 	printf("Address of buf : %p\n", &buf[0]); // # 0x7fff51f11ec0
// 	printf("Address of buf+1: %p\n", &buf[1]);// # 0x7fff51f11ec1
// 	return 0;
// }


//1.3.2 global 
// const char *getStr1()
// {
// 	const char *p1 = "abcdefg2";
// 	return p1;
// }

// const char *getStr2()
// {
// 	const char *p2 = "abcdefg2";
// 	return p2;
// }

// int main(void)
// {
// 	const char *p1 = NULL;
// 	const char *p2 = NULL;
// 	p1 = getStr1();
// 	p2 = getStr2();

// 	printf("p1 memory data: %s,\np2 memroy data: %s, \n", p1, p2);
// 	printf("p1 point value: %p,\np2 point value: %p, \n", p1, p2);

// 	return 0;
// }


// 1.3.1 stack and heap
// char *getMem2()
// {
// 	char buf[64];	//  temporary variable put in stack
// 	strcpy(buf, "123456");
// 	printf("buf: %s\n", buf); // # buf: 123456
// 	return buf; // return the first address of memory block , not the 64 byte
// }

// char *getMem(int num)
// {
// 	char *p1 = NULL;
// 	p1 = (char*)malloc(sizeof(char)* num); // dynamic memory alloc in heap
// 	if (p1 == NULL)
// 	{
// 		return NULL;
// 	}
// 	return p1; // return head of memory block of num byte
// }

// int main (void)
// {
// 	char *tmp = NULL;
// 	tmp = getMem(10);
// 	if (tmp == NULL)
// 	{
// 		return 0;
// 	}
// 	strcpy(tmp, "112222");
// 	printf("tmp112222: %s\n", tmp); // # tmp112222: 112222
// 	tmp = getMem2();
// 	printf("stack: %s\n", tmp); // # stack: 123456
// 	return 0;
// }


// 1.1.5
// int main ()
// {
// 	int *p1 = NULL;
// 	printf("point : %p\n", p1); // point : (nil)
// 	char* p2 = NULL;
// 	printf("NULL: %p\n", p2); // NULL: (nil)
// 	return 0;
// }


// 1.1.4
// typedef struct People
// {
// 	char name[64];
// 	int age;
// } people_t;

// typedef unsigned int u32;
// int main()
// {
// 	struct People p1;
// 	people_t p2;
// 	u32 a;
// 	p1.age = 10;
// 	p2.age = 11;
// 	a = 10;
// 	return 0;
// }


// 1.1.3
// int main()
// {
// 	int a = 10;
// 	printf("size of (a): %zu \n", sizeof(a));
// }