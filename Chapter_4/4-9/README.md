# 4-9 README

根据K&R，P43：

> There is one subtle point about the conversion of characters to integers. 
> The langage does not specify whether variables of type `char` are signed or
> unsigned quantities. When a `char` is converted to an `int`, can it ever 
> produce a negative integer? The answer varies from machine to machine, reflecting 
> differences in architecture. On some machines a `char` whose leftmost bit is 1 
> will be converted to a negative integer ("sign extension"). On others, a `char` 
> is promoted to an `int` by adding zeros at the left end, and thus is always positive.

也就是说，对于C语言中的`char`类型转`int`类型，在有些机器上是按照符号位扩展，可以产生
负数。在一些机器上，则只能产生正数。

对于4-9这道题目而言，在那些可以产生出负数的机器上，原程序可以正确处理`EOF (-1)`，而
在那些只能产生正数的机器上，`EOF (-1)`则会被看成`255 (全1)`。为了解决这个问题，我们
需要将原程序中的`char buf[BUFSIZE];`改为`int buf[BUFSIZE];`。这样就不存在`char`到`int`
的转换问题，程序无论在哪种机器上都可以正确处理`EOF`了。

最后记录一下关于`getchar()`函数的一些感悟。

```c
int main()
{
	int c;

	while ((c=getchar()) != EOF)
		putchar(c);
	return 0;
}
```

这个经典的小程序，可以实现Linux程序`echo`的功能。我想讲的是，如果你
从键盘中输入`123EOF (Ctrl_D)`，程序会打印出`123`但并不会立即退出，而是需要再输入一个
`EOF (Ctrl_D)`才可以退出。即：
```
	123EOF123EOF
	<process quit>
```
这是因为`getchar`并不是从键盘文件中读一个字符就立即将这个字符返回，而是将它存在
一个缓冲区中，当`getchar`收到第一个`EOF`的时候，将缓冲区中的内容全部返回。如果缓冲区
为空，则将返回一个`EOF`。

所以，当我们输入`123EOF`的时候，`getchar`实际上返回的是已经读取的`123`；当我们输入第二个
`EOF`的时候，缓冲区中没有数据，所以`getchar`会返回一个`EOF`，程序退出。

补充，实验表明，当`getchar`接收到`回车`的时候，也会将读取到的信息（**含有收到的回车**）一并返回，
因此，当我们输入：
```
	123(Enter)    # 用户输入
	123(Enter)    # 程序输出
```

以上。
