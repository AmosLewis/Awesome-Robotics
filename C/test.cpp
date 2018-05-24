#include "stdio.h"
#include "stdlib.h"
#include "string.h"
// #include <iostream>
// using namespace std;

// 4.2.3
// int main(void)
// {
// 	// 1. pointer array

// 	// - Conclusion, if your want to use second pointer to point to a list of strings in global region,your must determine an pointer array first. Then use the second pointer to point to the pointer array.
// 	// char **p ={"aaaa", "cccc"}; // error scalar object ‘p’ requires one element in initializer
// 	char *myArray[] ={"aaaa", "cccc"}; // myArray is an array in stack, ang every element is char*
// 	char **p = myArray; 		   	// myArray[] = *myArray


// 	// 2. Two dimention array

// 	// - Two dimention array must be initlize with value
// 	// char a[][30]; // error storage size of ‘a’ isn’t known
// 	char a[10][30] = {"aaa","bbb", "ccc", "111"};
// 	// &a = a = &a[0] but there step vary
// 	printf("&a: %p \n", &a);		// # 0x7ffded01e0a0 
// 	printf("a: %p \n", a);			// # 0x7ffded01e0a0 
// 	printf("&a[0]: %p \n", &a[0]);	// # 0x7ffded01e0a0 
// 	printf("&a[0][0]: %p \n", &a[0][0]);	// # 0x7ffded01e0a0 
// 	printf("a[0][0]: %c \n", a[0][0]);      // a
// 	// &a + 1 = &1 + 30*4 byte
// 	printf("&a+1: %p \n", &a+1);	// # 0x7ffded01e1cc  
// 	// a+1 = a + 30 byte
// 	printf("a+1: %p \n", a+1);		// # 0x7ffded01e0be  
// 	// (&a[0])++ = a + 1 byte
// 	printf("a[0]+1: %p \n", a[0]+1);// # 0x7ffded01e0a1
// 	// a[0][0]+1 = ASSCI(a) + 1 = b 
// 	printf("a[0][0]+1: %c \n", a[0][0]+1);    // b

// 	// 3. Dynamicly allocate memory 
// 	int b[3];
// 	int *q = (int*) malloc(3 * sizeof(int)); // equal to 9[3]

// 	int n =3;
// 	char **buf = (char **)malloc(3 * sizeof(char*));// equal to char *buf[3]
// 	printf("&buf: %p \n", &buf);						// stack # 0x7ffe0a65df30  
// 	printf("buf: %p \n", buf);							// heap # 0x1693030 
// 	for (int i = 0; i < n; i++)
// 	{
// 		buf[i] = (char*)malloc(30 * sizeof(char));
// 		printf("&buf[%d]: %p \n", i, &buf[i]);			// heap # 0x1693030 0x1693038 0x1693040
// 		printf("buf[%d]: %p \n", i, buf[i]);			// heap # 0x1693050 0x1693080 0x16930b0
// 	}
// 	// buf in stack; char* in heap; char in heap

// 	char **myArray = NULL;
// 	printf("&myArray: %p \n", &myArray); 				// stack # 0x7ffe0a65df40 

// 	return 0;
// }



// 3.4.1 while / do-while in strstr
// char* strStr( char *str1, char *str2) // wrong function
// {
// 	if ( str1 == NULL | str2 == NULL)
// 	{
// 		return NULL;
// 	}

// 	char *src = str1;
// 	char *target = str2;

// 	while (*src)
// 	{
// 		char *begin = src;
// 		char *partern = target;
// 		while(*src = *target) // segmentation fault ???
// 		{
// 			src++;
// 			partern++;
// 		}
// 		if (!*partern)
// 		{
// 			return begin;
// 		}
// 		src = begin+1;
// 	}

// 	return NULL;
// }

// int countStr(char *src, char *target )
// {
// 	int count = 0;
// 	if ( src == NULL || target == NULL)
// 	{
// 		return 0;
// 	}

// 	do
// 	{
// 		src = strstr(src, target);
// 		if ( src != NULL )
// 		{
// 			count++;
// 			src = src + strlen(target);
// 			printf("%p\n",src);
// 		}
// 		else
// 		{
// 			break;
// 		}
// 	} while( *src != '\0');
// 	return count;
// }

// int main(void)
// {
// 	char *p =(char*) "11abcd11234abcd34278abcd";
// 	int ncount = countStr(p, (char*)"abcd");
// 	printf("ncount:%d\n", ncount);
// }


// 3.3 copy a string
// int copy_str6(char *from, char* to)
// {
// 	char *tmpfrom = from;
// 	char *tmpto = to;
// 	if ( from == NULL | to == NULL)
// 	{
// 		return -1;
// 	}

// 	while(*tmpto++ = *tmpto++);
// 	printf("from:%s\n", from);
// 	return 0;
// }

// int main(void)
// {
// 	char a[] = "I am a student";
// 	char b[64];
// 	int i = 0;
// 	for ( i =0; *(a+i)!='\0'; i++)
// 	{
// 		*(b+i) = *(a+i);
// 	}
// 	b[i] = '\0'; // important
// 	printf("a:%s \n", a);
// 	printf("b:%s \n", b);

// 	char *from = (char*)"abcd";
// 	char buf[20];
// 	int ret = copy_str6(from, buf);
// }


// 3.1.2 array/pointer to manipulate string
// int main(void)
// {
// 	int i = 0;
// 	char *p = NULL;
// 	char buf[128] = "abcdefg";

// 	// array[]
// 	for ( int i = 0; i < strlen(buf); i++)
// 	{
// 		printf("%c", buf[i]); // # abcdefg
// 	}

// 	// buf is a const pointer 
// 	for ( int i = 0; i < strlen(buf); i++)
// 	{
// 		printf("%c", *(buf+i)); // # abcdefg
// 	}

// 	return 0;
// }

// 3.1.1 init string array
// int main(void)
// {
// 	// 1 Not assign lenth, Compiler will automatically calculate lenth
// 	char buf1[] = {'a', 'b', 'c', 'd'};
// 	// 2 assign lenth, buf[4-99] = '\0'
// 	char buf2[200] = {'a', 'b', 'c', 'd'};
// 	// char buf3[2]= {'a', 'b', 'c', 'd'};
// 	// over lenth, Compiler error
// 	printf("buf1: %s \n", buf1); // # abcd 
// 	printf("buf2: %s \n", buf2); // # abcd 
// 	printf("buf2: %d \n", buf2[88]); // # 0

// 	// 3 use string to init, 
// 	char buf3[] = "abcd";
// 	// buf3 as char array with 5 byte
// 	printf("buf3 length as string : %d \n", (int)strlen(buf3)); // # 4
// 	// buf3 as string with 4 byte
// 	printf("buf3 length as char array : %d \n", (int)sizeof(buf3)); // # 5

// 	char buf4[128] = "abcd";
// 	printf("buf4[100]: %d \n", buf4[100]); // # 0
// }


// 2.1.3 
// int getMem(char **myp1, int *mylen1, char **myp2, int *mylen2)
// {
// 	int ret = 0;

// 	char *temp1, *temp2;

// 	temp1 = (char*)malloc(100);
// 	temp2 = (char*)malloc(100);

// 	strcpy(temp1, "009987922");
// 	strcpy(temp2, "sadfaegwgd");

// 	// second order pointer
// 	*myp1 = temp1;
// 	*myp2 = temp2;

// 	// first order pointer
// 	*mylen1 = strlen(temp1);
// 	*mylen2 = strlen(temp2);

// 	return ret;
// }


// int main(void)
// {
// 	int ret = 0;

// 	char *p1 = NULL;
// 	char *p2 = NULL;
// 	int len1 = 0;
// 	int len2 = 0;

// 	ret = getMem(&p1, &len1, &p2, &len2 );
// 	if ( ret!=0 )
// 	{
// 		printf("error %d \n", ret);
// 		return ret;
// 	}

// 	printf("p1 : %s \n", p1);
// 	printf("p2 : %s \n", p2);

// 	if ( p1!= NULL)
// 	{
// 		free (p1);
// 		p1 = NULL;
// 	}
// 	if ( p2!= NULL)
// 	{
// 		free (p2);
// 		p2 = NULL;
// 	}
// }


// 2.1.2 indirectly addressing

// void copy_to(char *p1, char*p2) // step 3 : *p set to
// {
// 	while( *p1!='\0')
// 	{
// 		*p2 = *p1;
// 		p1++;
// 		p2++;
// 	}
// }

// int main(void)
// {
// 	char from[128];
// 	strcpy(from, "safjdlaeflsjflsd");
// 	char to[128] = {0}; // step 1: define a variable(real parameter)
// 	copy_to(from,to); // step 2: build relation by formal parameter
// 	printf("to: %s\n", to);
// }

// struct A
// {
// 	int a1:5;
// } B;

// int main()
// {
// 	printf("hi\n");
// 	return 0;
// }

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
