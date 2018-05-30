# Review note for C++

### Compiler
```
touch c_pp.cpp
g++ c_pp.cpp -o c_pp
./c_pp
```

### [***Knowledge Note***]
#### [***Chapter_One***] : C++: Enhancement of C

- namespace

     - <iostream> havenot define global namespace,so we muse use **using namespace std**;

     - C++ ask us not to use head file .h. But for compatibility with C, we can still used it

     - namespace name { ... }

     - namespace could be nested

 - Practicability
 
     - We must define variable at the start of scope in C.
     
     - We can define variable at anywhere in C++
     
 - Check for variable with same name
 
     - We can re-define global variable in C. And they will linked to same memory address.
     
     - We can not re-define global variable in C++.
     
 - struct enhanced
 
     - struct is an union of variables in C.
     
     - struct is a new data type in C++.
     
 - C++: all variable and function must explicitly declare their type
 
     - in C: **int func();** means return value is int, accept any arguments.  **int func(void)**; means return value is int, accept none arguments.
     
     - in C++: **int func(); == int func(void);** means return value is int, accept none arguments.
     
 - C++: add bool
 
     - bool only have true(none 0) and false(0).
     
     - occupy 1 byte
     
 - ternary operator
 
     - C: ternary operator return variable value, it cannot be used as left value.
     
          - the left value: must have memory space.
     
     - C++: ternary operator return variable it self, it can be used at anywhere.
     
 - const enhanced
 
     - in C, even the const variable is an variable(an read only memory space).
     
     - C++, it is an real constant that fixed during compiling. (with memory space or not)
     
     - C++: const int c =5; ≈ #define c 5
     
          - const is process by compiler, with type check and scope check
          
          - #define is process by preprocessor, naive replace
     
 - enum
 
     - C: enum can be initialize by any int value
     
     - C++: enum can only be initlize by the item it has list
     
 #### [***Chapter_Two***] : C++: Extension of C    
 
 - Reference
 
      - variable name is an alias of a memory space. Reference is an alias of variable name.
        ```
        Type& name = var;
        ```
        
      - Reference dose not have definition. It is an relationship declaration. So it does not allocate memory. It share the same address with variable name.
      
      - Reference must be initlize when declaration. Once declared, it could not be changed.
      
      - Reference could be nested
      
      - & is reference only when there is a data type before &. Others is get address. 
     
     - Reference as function arguments could not be initilized.
     
     - Compared to pointer,
     
          - reference is more readable and practical. C++ can avoid use of pointer by use reference.
     
          - Type& name <===> Type* const name
          
          - const pointer is the inner implementation of reference. So reference and pointer have the same size of memory. They all have own memory sapce.
          
          - Reference use **indirectly assignment**. Indirectly assignment: 
               
               - step1. Definie two variable(formal/real argument).
               
               - step2. Build relationship, formal = &real.
               
               - step3. Change *formal to change value of real.
               
               - Reference combine step2/3, C++ compiler helps us complete &real and *formal.
               
          - Reference as return value can be as left value.
          
               - Return stack(local) variable:  should not be as left value. But compiler only give you an warning when you return local variable.
                    ```
                    int& getA2()   // warning: reference to local variable 'a' return
                    {
                         int a;
                         a = 10;
                         return a;
                    }
                    int a1 = getA2();    // 10 value copy
                    int &a2 = getA2()    // 32535 stack reference, memory illegal
                    ```
               
               - Return static/global variable: can be as left/right value.
                    ```
                    int& getA2()   // no warning
                    {
                         static int a;
                         a = 10;
                         return a;
                    }
                    int a1 = getA2();    // a1 =10 value copy
                    int &a2 = getA2()    // a2 =10 local reference, memory legal
                    getA2() = 20;        // a2 =20
                    ```
          
         - Pointer Reference
         
              - 2nd level pointer

                   ```
                   void getTeacher1(Teacher **p)
                   {
                   Teacher *tmp = NULL;
                   tmp = (Teacher *)malloc(sizeof(Teacher));
                   tmp -> age = 33;
                   *p = tmp;
                   // skip some NULL check
                   }
                   ```
                    
              - pointer reference

                   ```
                   void getTeacher2(Teacher* &myp)
                   {
                   myp = (Teacher *)malloc(sizeof(Teacher));
                   myp->age = 33;
                   // skip some NULL check
                   }
                   // main
                   Teacher *pT1 = NULL;
                   getTeacher1(&pT1);       // 2nd level pointer
                   getTeacher1(pT1);        // reference
                   ```
                    
          - const reference
          
               - const object must use const reference. Or compiler error.
                    ```
                    const int a = 1;
                    
                    const int &b = a;
                    int &b = a;    // error, must use const reference
                    ```
                
               - const reference can be initialized by relative type. Biggest difference from normal reference(without const).
                    ```
                    const int &a =1;
                    
                    double x = 3.14;
                    const int &b = x;
                    ```
                    
               - Purpose of const: forbid change object by changing its reference
                    ```
                    int a = 1;
                    const int &b = a;
                    b = 12;        // error, b read only 
                    ```
               - implementation of const reference
               
                    const int &b == const int *const b;      // const int* pointer that points to const b. 
                    int &b == int *const b                   // int* pointer that points to const b. 
                    ```
                    double a = 3.14;
                    const int &b = a;   // b = 3 read only, cannot change
                    double &c = a;      // c = 3.14
                    val = 4.14          // c = 4.14, b = 3
                    ```
                    for const int&b = a, actually in C++ it is implemented by:
                    ```
                    int temp =a;
                    const int &b = temp;     // so when you change b, you change temp, no a
                    ```
                    So C++ will allocate memory for const reference, but no allocate memory for normal reference
                    ```
                    const int &m = 3;     // sucess and read only, because
                                             // int tmp = 3; const int &m = tmp
                    int &m = 3;           // error,  because  constant 3 does not have memory address
                    ```
        
  - inline function
  
     - inline in C++ is a replacement for macro in C. macro in C is processed during preprocess period, just simply replace code, so there is no check on gramma and  meaning error.
     
     - Concept
     
          - inline is real embedded in code
          ```
          inline void func(int a)
          {
               a = 20;
               cout<<a<<endl;
          }
          int main(void)
          {
               func(10);
               /*
               // the compiler will stretch the func(10) like this
               {
                    a = 20;
                    cout<<a<<endl;
               }
               */
          }
          ```
               
          - **inline** declaration and definition at the same time, same place.

          - call inline function just simply replace function like macro, without other expense(push stack, jump, return etc.). This is the only difference between inline and normal function. **More space for less time**

          - processed by compilier, so we can test error

          - no loop, no too much if, not so big(usually < 10 line), no get address operation(&),  declaration must before call.

     - inline and macro

          ```
          #define SQR(x) ((x)*(x))

          #inline int sqr(int x)
          {
               return x*x;
          }
          ```

- Default argument and placeholder argument

     - Default argument
          
          - Noramly in C, when you call a function, the value of formal argument is get from real arguments. But in C++, you can set default value for formal argument.
          ```
          void myPrint(int x = 3)
          ```
          
          - Once you give an default value, the right formal arguments should all be assignmented with default value.
          ```
          float volume(float length, float weigh = 4, float high = 5)
          // main
          float v0 = volume(10);
          float v1 = volume(10, 20);
          float v2 = volume(10, 20, 30);
          ```
     
     - Placeholder argument
     
          - type without name in formal argument
          ```
          int func(int a, int b, int)
          {
               return a+b;
          }
          // main
          func(1,2);      // error
          func(1,2,3);    // sucess
          ```
          
          - combine with default value. C++ use it for compatibility with C
          ```
          int func(int a, int b, int = 0)
          {
               return a+b;
          }
          func(1,2);      // sucess
          func(1,2,3);    // sucess
          ```
     
- Function Overload
     
     - Definition rule
          - Same function name, 
          - Same return value, 
          - Different function formal parameters(different order,type,number).
     
     - Call rule
     
          - All function with same name as candidate
          
          - Strictly match
          
          - Could implicitly cast(float->double, char->int)
          
     - Implementation of overload
          
          - name mangling(v c i f l d -> void char int float long double)
          ```
          void func(char a)                            // func_c(char a)
          void func(char a, int b, double c);          // func_cid(char a, int b, double c)
          ```
          
     - overload and default argument cannot be as the same time
     ```
     int func(int a);
     int func(int a, int b, int c =0 );      // default argument
     int func(int a, int b);                 // overload
     
     //main
     int c = func(1,2);                      // error, ambiguity
     ```
     
     - overload and function pointer
     
          ```
          int func(int a);
          int func(int a, int b);

          typedef int (*PFUNC1)(int a);  // int(*)(int a)
          typedef int (*PFUNC2)(int a);  // int (*)(int a, int b)

          // main
          PFUNC1 p1 = func();
          int c = p(1);
          PFUNC2 p2 = func();
          int c = p2(1,2);
          ```
     
          - review of function pointer (you can found detail in C review note)
          ```
          // method 1
          typedef void (FUNC)(int a, int b);      // declare a function type
          FUNC *p1 = NULL;                        // define a function pointer
          // method 2
          typedef void (*FUNC)(int a, int b);     // declare a function pointer type
          FUNC p2 = NULL;                         // define a function pointer
          // method 3
          void (*FUNC)(int a, int b);             // : define a function pointer variable
          
          ```
     
#### [***Chapter_Three***] : Class
- Concept
     - class and object
     
     - member function and member variable
     
     - Feature of object orientation: package, inheritance, polymorphism
     
     - class in C++ is an replacement of struct in C
     
 - Package and access control
 
     - struct
          
          - all action and access property is **public**, so we cannot hide inner data.
          
          - manipulation of struct is from outer function. 
          
      - access properity
      
          - **public**(default for struct): both outer and inner can access
          
          - **protected**: outer function cannot access, inner function can access.
          
          - **private**(default for class): outer function cannot access, inner function can access.
          
      - Object-oriented and Process-oriented
          
          - Object-oriented: Dog.Eat(shit);
          
          - Process-oriented: Eat(Dog, shit);
     
      - Definition of class
          ```
          class Circle
          {
          private:
                    double radius;
          public:
                    void Set_Radius(double r)
                    {
                         radius = r;
                    }
                    double Get_Radius()
                    {
                         return radius;
                    }
                    double Get_Area()
                    {
                         return 3.14f * radius * radius;
                    }
          };
          
          // main
          Circle A;
          A.Set_Radius( 6.24 );
          double r = A.Get_Radius();
          ```
     
#### [***Chapter_Four***] : Object construct and destruct

- Constuct function

     - Construct function is used for initilize object of class. like malloc in C.
     
     - Call:  Manually / Automatically
     
     - format: Same name with class. No return value
          ```
          class A
          {
          public:
               A( formal argument )
               {
                    ;
               }
          private:
               int a;
               int b;
          }
          ```
     - C++ has default construct function(**swallow copy**). Once you implement (deep copy) youself, default construct function won't exist.
     
     - Classification
          
          - Without argument(**default**)
          ```
          A()
          {
               ;
          }
          // main
          A a;
          ```
               
          - With arguments. Once you implement it, C++ compiler won't give you **without argument construct** will not exit.
          ```
          A( int a, int b)
          {
               ;
          }
          // main
          A a(10,20);
          ```
          
          - Copy construct function(**default**: only copy member variable): constuct an object by an exist object. Once you implement it, C++ compiler won't give you **without argument construct** will not exit.
          ```
          A( const A &another_obj)
          {
               ;
          }
          // main
          A a1;          // Witout argument
          A a1(10,20);   // With arguments
          A a2 = a1;     // 1. copy construct
          A a2(a1);      // 2. copy construct
          void func(A p);
          func(a1);      // 3. copy constuct, p = a2
          A func1();
          A a3= func1(); // 4. copy construct
          ```
          
          - Initilize list
               
               - When a **big class** include a **small class**, we must use construct function **with arguments** & **initlize list** for big class.
               
               - When **const/reference** object as member variable, we must use construct function **with arguments** & **initlize list** for big class.  
          ```
          class AB
          {
          public:
               AB(int a, int b)
               {
                    ;
               }
          private:
               int _a;
               int _b;
          }
          
          class ABC
          {
          public:
               ABC():_ab1(1,2), _ab2(3,4), _m(100)         // random order for list
               {
                    ;
               }
          private:
               AB _ab1;
               AB _ab2;
               const int _m;
          }
          ```
               
     
- Destruct
     
     - Used for clear something before delete object. Like free in C.
     
     - - Call: Automatically
     
     - format
     ```
     class A
     {
          ~A()
          {
               ;
          }
     }
     ```
     
     
- Object new and delete

     - **new** and **delete** in C++ is a replacement for **malloc** and **free** in C.
     
     - new and delete is operator, not function. So it is very efficient.
     
     - **malloc** will not call class **construct** function, but **new** will
     
     - **free** will not call class **destruct** function, but **delete** will
     
     - **new** allocated array should not assign initlize value.
     ```
     float *p = new float (3.14);
     char *p = new char[10];
     int (*)[4] p = int[5][4];
     int **p = new int *[4];
     ```
     
     - format
          
          - new:    pointer_variable = new type (constant)
          
          - new:    pointer_variable = new type[expression]
          
          - delete: delete pointer_variable
          
          - delete: delete[] pointer_variable
     
- static member variable & member function

     - static member variable(data segment): 
     
          - Belongs to class, not just any specific object. All object will share it.
          
          - It is declared inside class, but must **initialize outside** class.
          ```
          class A
          {
               static int s;.....
          }
          int X::s = 0;            // not in main
          // main
          A a, b, c, d;
          cout<<a::s<<endl;
          ```
          
          - stored in data segment, so doesnot caculated in class size.
 
     - static member function
     
          - declaration and call
                    ```
          class A
          {
               static int func();
          }
          int A::func()
          {
               ;
          }
          // main
          A a, b, c, d;
          cout<<a.func()<<endl;
          ```
          
          - It can only access static member. 
          
          - It only belongs to class not object, so doesnot has **this pointer**.
          
          - None static member function belongs to object, it has **this pointer**.
          
 - Mechanism of property & function prosessing by compiler 
 
     - Store
          
          - member variable(use _ before its name)
          
               - static: store in object, like struct
               
               - normal: store in data segment(global)
               
          - member function: store in code segment
          
               - static: without this pointer
               
               - normal: with this pointer pointing to current object
               
      - **this** pointer
      
          - member function implicitly include this pointer that points to current obj.
          ```
          class A
          {
               void func(int a,  int b)      void func(A *const this, int a, int b)
               {                             {
                    x = a;                        this->x = a;
                    y = b;                        this->y = b;
               }                             }
          }
          ```
          
      - global function & member function
      
          - global ===> member : use this to hide left operand
          ```
          A add(A &a1, A &a2) ===> A add(A &a2)
          ```
          
          - member ===> global: add an arguments
          ```
          void func() ===> void func(A *athis)
          ```
          
          - return item / reference
          ```
          A& add(A &a2)                           // return reference
          {
               this->a = this->a + a2.getA();
               this->b = this->b + a2.getB();
               return *this;
          }
          A add(A &a2)                            // return item
          {
               this->a = this->a + a2.getA();
               this->b = this->b + a2.getB();
               A a3(this->a, this->b);
               return a3;
          }
          ```
     
- friend
     
     Friend is someone that need to vist class member frequently. It is not a member of class. Friend can accelerate efficiency of program, but damage the encapsulation and hiddenness of class. Friend can vist **private member** of class. Friend include **friend function** and **friend class**.
     
     - friend function
          
          - friend is none-member function that can vist private member of class. It does not belong to any class.
          
          - global function as friend function:
          ```
          class A
          {
          public:
               A(int x, int y): _x(x), _y(y)
               {
                    ;
               }
               friend int func_f(A &a, A &b);
          private:
               int _x, _y;
          }
          int func_f(A &a, A &b)
          {
               ;
          }
          // main
          A a1(1,2),a2(3,4);
          int a = func_f(a1, a2);
          ```
     
          - member function in other class as friend function in current class:
          ```
          class A;                           // Forward declaration，used for point and reference in B
          
          class B
          {
          public:
               int func_f(A &a, A &b);
          }
          
          class A
          {
          public:
               A(int x, int y): _x(x), _y(y)
               {
                    ;
               }
               friend int B::func_f(A &a, A &b);
          private:
               int _x, _y;
          }
          int B::func_f(A &a, A &b)
          {
               ;
          }
          // main
          A a1(1,2),a2(3,4);
          B b;
          int a = b.func_f(a1, a2);
          ```
     - friend class
     
          - all members function in friend class is friend function. It is used when you want one class can access another class private and protected member.
          ```
          class A
          {
          public:
               friend class B;
          private:
               int _x,_y;
               friend class C;
          }
          class B
          {
          public:
               inline int func()
               {
                    A a;
                    cout<<a._x<<endl;
               }
          }
          ```

     - friend discussion
          
          - location: declaration must in class. It doesn't matterh weather it is public/private/protucted. But normally, we declare at the beginning of class.
          
          - Friend relationship cannot be inheritted.
          
          - Friend relationship is one way.
          
          - Friend relationship is cannot be transfer. B is frient of A, C is friend of B, C might not be friend of A.
          
- operator overloading

     - Overloading means give a new meaning. Operator overloading is actually function overload
     ```
     Type operator name_operator(formal arguments)
     {
          ;
     }
     ```
     
     - Example
     ```
     class A
     {
     public:
          A(int x, int y): _x(x), _y(y){}
          friend A operator+(A &a, A &b);
          A operator+(A &b);
     private:
          int _x, _y;
     }
     A operator+(A &a, A &b)
     {
          return A(a._x+b._x, a._y+b._y);
     }
     A A::operator+(A &b)
     {
          return A(this._x+b._x, this._y+b._y);
     }
     // main
     A a1(1,2), a2(3,4);
     A a3 = a1+a2;
     A a3 = c3.operator+(c1,c2);
     ```
     
     - rule
          
          - C++ doesnot allow you to define a new operator. We can only overload existed C++ operator.
          
          - overload cannot change the number of object that processed by operator( no default arguments). 
          
          - overload cannot change the priority of operator.
          
          - overload cannot change the associative of operator.
          
          - overload must defined with class object at the same time.
          
          - most of operator for class should overload, except **=** , **&**.
          
     - friend function / member function
     
          - whose member function: who call the operator( usually left operand )
          
          - whose friend function: who is the parameter of the operator( usually right operand )
          
          - Exmaple
          ```
          class Mail;
          class Sender
          {
          public:	
               Sender(string	s):_addr(s){}
               Sender& operator<<(const Mail & mail);
          private:
               string _addr;
          };
          
          class Mail
          {
          public:
               Mail(string _t,string _c ):_title(_t),_content(_c){}
               friend Sender& Sender::operator<<(const Mail & mail);	
          private: 
               string _title;	
               string _content;	
          }; 
          
          Sender& Sender::operator<<(const Mail & mail)	
          { 
               cout<<"Address:"<<_addr<<endl;	
               cout<<"Title	:"<<mail._title<<endl;	
               cout<<"Content:"<<mail._content<<endl;	
               return *this;	
          }	
          
          in main()	
          {
               Sender sender("danbing_at@gmail.com");	
               Mail	mail("note","meeting at 3:00	pm");	
               Mail	mail2("tour","One night in beijing");	
               sender<<mail<<mail2;	
               return 0;	
          }	
          ```





































