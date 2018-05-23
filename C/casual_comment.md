
# Chi Casual Comment 

随便写写吐吐槽

2018/05/23

- 不得不说 ，C的骚操作真是多。

    刚刚不经意看到看了 struct 中的 bit field, 看不懂，去查了一下，惊呼还可以这样。 正史上还没整理到这边， 先在这个野史上先随手记录一下吧。
    ```
    #pargma pack(2) // 使结构体2字节对齐 16bit
    struct
    {
        int a1:5;
        int a2:9;
        char c;
        int b:4;
        short s;
    } B;
    sizeof (B) = 16
    ```

    | 0-7| 8-15| 16-23 | 24-31 |
    |:----:| :----: | :----: | :----: |
    | a1, a2|a2| void | void |
    | c1 | * | * | * |
    | b | void | void | void |
    | s | s | * | * |


- Visual studio 如果报 ```_CRT_SECURE_NO_WARNINGS```， 让你换```strcpy->strcpy_s```, 说这样更安全怎么办呀？

    在头文件里加个 ``` #define _CRT_SECURE_NO_WARNINGS  ``` 预处理一哈，强制让编译器给你这样操作，不然你就换咯。
