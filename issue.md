# Issue

这里记录我在完成习题过程中的一些困惑。

## exercise 4-8

> Exercise 4-8. Suppose that there will never be more than one character of
pushback. Modify getch and ungetch accordingly.

疑问：题目的意思是“假设不会有多个字符被pushback，并根据此对getch和ungetch
进行相应修改”。但是在原版的程序中，getch和ungetch本身就是对单个字符进行
操作的，如果每次pushback的都是单个字符，那么程序就不用修改才对啊？

