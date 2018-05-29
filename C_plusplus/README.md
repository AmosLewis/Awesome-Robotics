# Review note for C++

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
          
          - const pointer as the inner implementation of reference. Reference and pointer have the same size of memory. They all have own memory sapce.
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
