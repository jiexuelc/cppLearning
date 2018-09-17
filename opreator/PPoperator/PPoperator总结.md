# ++操作符总结
## 基础知识点:
    1. "()"优先级大于"++"运算符
    2. "()"运算结合方向从左往右
    3. "++"运算结合方向从右往左
    4. (i++)不能做左值，而(++i)可以
## 为何(i++)不能做左值，而(++i)可以
- (++i) "++"运算符在C++里面的重载实现
   - 前缀形式：
    int& int::operator++() //这里返回的是一个引用形式，就是说函数返回值也可以作为一个左值使用
    {//函数本身无参，意味着是在自身空间内增加1的
        *this += 1;  // 增加
        return *this;  // 取回值
    }
   
   - 后缀形式:
    const int int::operator++(int) //函数返回值是一个非左值型的，与前缀形式的差别所在
    {//函数带参，有另外的空间开辟
        int oldValue = *this;  // 取回值
        ++(*this);  // 增加
        return oldValue;  // 返回被取回的值
    }
- 参考链接：https://www.cnblogs.com/duguochao/p/4665830.html
## 代码举例1

```c++
#include <cstdio>

int main()
{

    int d = 4;
    (++d) += d++;
    printf("%d\n",d);

    return 0;
}
```
#### 输出结果
```
//GNU 4.8.4
11
//vs2010
11
```

------

### 汇编原码分析
#### GNU 4.8.4汇编结果
```
	.file	"2.cpp"
	.section	.rodata
.LC0:
	.string	"%d"
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	andl	$-16, %esp
	subl	$32, %esp           ;以下的注释可能不符合汇编注释，凑合看，是个意思
	movl	$4, 28(%esp)        ;esp = d = 4;
	addl	$1, 28(%esp)        ;esp = esp + 1 = 5
	movl	28(%esp), %eax      ;eax = esp = 5
	leal	1(%eax), %edx       ;edx = eax + 1 = 6;
	movl	%edx, 28(%esp)      ;esp = edx = 6
	addl	%eax, 28(%esp)      ;esp = esp + eax = 6 + 5 =11
	movl	28(%esp), %eax
	movl	%eax, 4(%esp)
	movl	$.LC0, (%esp)
	call	printf
	movl	$0, %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 4.8.4-2ubuntu1~14.04.4) 4.8.4"
	.section	.note.GNU-stack,"",@progbits
```
#### VS2010汇编结果
```MAS
#include <cstdio>
#include <cstdlib>

int main()
{
00E81530  push        ebp  
00E81531  mov         ebp,esp  
00E81533  sub         esp,0CCh  
00E81539  push        ebx  
00E8153A  push        esi  
00E8153B  push        edi  
00E8153C  lea         edi,[ebp-0CCh]  
00E81542  mov         ecx,33h  
00E81547  mov         eax,0CCCCCCCCh  
00E8154C  rep stos    dword ptr es:[edi]  

    int d = 4;
00E8154E  mov         dword ptr [d],4  ;d=4;
    (++d) += d++;                           ;以下的注释可能不符合汇编规范，凑合看，是个意思
00E81555  mov         eax,dword ptr [d]     ;eax = d = 4
00E81558  add         eax,1                 ;eax = eax+1 = 5
00E8155B  mov         dword ptr [d],eax     ;d = eax = 5
00E8155E  mov         ecx,dword ptr [d]     ;ecx = d = 5
00E81561  add         ecx,dword ptr [d]     ;ecx = ecx + d = 10
00E81564  mov         dword ptr [d],ecx     ;d = ecx = 10
00E81567  mov         edx,dword ptr [d]     ;edx = d = 10
00E8156A  add         edx,1                 ;edx = edx + 1 = 11
00E8156D  mov         dword ptr [d],edx     ;d = edx = 11
    printf("%d",d);
00E81570  mov         esi,esp  
00E81572  mov         eax,dword ptr [d]  
00E81575  push        eax  
00E81576  push        offset std::tr1::integral_constant<bool,0>::value (0E8773Ch)  
00E8157B  call        dword ptr [__imp__printf (0E8A3F0h)]  
00E81581  add         esp,8  
00E81584  cmp         esi,esp  
00E81586  call        @ILT+400(__RTC_CheckEsp) (0E81195h)  

	system("PAUSE");
00E8158B  mov         esi,esp  
00E8158D  push        offset std::tr1::integral_constant<unsigned int,0>::value (0E87740h)  
00E81592  call        dword ptr [__imp__system (0E8A3ECh)]  
00E81598  add         esp,4  
00E8159B  cmp         esi,esp  
00E8159D  call        @ILT+400(__RTC_CheckEsp) (0E81195h)  

    return 0;
00E815A2  xor         eax,eax  
}
```
#### 小结
 对于`(++d) += d++;`语句不同的编译器不同的实现方式
- GNU里面的实现方式：
   - 先做++d, d=5;
   - 然后做d++;d=6;
   - GNU编译器前一个加操作数取5,后一个加操作数取6;即d = 5 + 6
- VS2010里面的实现方式：
   - 先做++d, d=5;
   - 然后做d = d+d = 5+5 = 10;
   - 最后d = d+1 = 11;
- 两种实现方式读起来都比较奇怪

## 代码举例2
```c++
#include<iostream>
using namespace std;

int main()
{
    /*
     * 先计算a++,a=5;然后计算 a=a+4;
     * 注意:这里后一个加操作数取的是a++以前的值 
     */
    int a = 4;
    a += a++;
    cout << "    a += a++;  Value of a:  " << a << endl;    //9

    /*
     * 先计算++b,b=5;然后计算 b=b+5;
     * 注意:这里后一个加操作数取的是++b后的值 
     */
    int b = 4;
    b += ++b;
    cout << "    b += ++b;  Value of b:  " << b << endl;    //10

    /*
     * 先计算++c,c=5;然后计算 c=c+5;
     * 注意:这里后一个加操作数取的是++c后的值 
     */
    int c = 4;
    (++c) += c;
    cout << "(++c) += c;    Value of c:  " << c << endl;    //10

    /*
     * 不加()的情况和上一种情况一样
     * 先计算++c1,c1=5;然后计算 c1=c1+5;
     * 注意:这里后一个加操作数取的是++c1后的值 
     */
    int c1 = 4;
    ++c1 += c1;
    cout << " ++c1 += c1;   Value of c1: " << c1 << endl;   //10

    //int c2 = 4;
    //(c2++) += c2; //没有这种表达，编译出错; c2++不可用来作为左值

    /*
     * 这种情况不同的编译器有不同的实现方式
     * GNU里面的实现方式：
     *   1.先做++d, d=5;
     *   2.然后做d++;d=6;
     *   3.GNU编译器前一个加操作数取5,后一个加操作数取6;即d = 5 + 6
     * VS2010里面的实现方式：
     *   1.先做++d, d=5;
     *   2.然后做d = d+d = 5+5 = 10;
     *   3.最后d = d+1 = 11;
     * 两种实现方式读起来都比较奇怪
     */
    int d = 4;
    (++d) += d++;
    cout << "(++d) += d++;  Value of d:  " << d << endl;    //11

    /*
     * 和上一种加括号的类似
     */
    int d1 = 4;
    ++d1 += d1++;
    cout << "++d1  += d1++; Value of d1: " << d1 << endl;   //11

    return 0;
}
```
#### 输出结果

```
//GNU 4.8.4输出结果
    a += a++;  Value of a:  9
    b += ++b;  Value of b:  10
(++c) += c;    Value of c:  10
 ++c1 += c1;   Value of c1: 10
(++d) += d++;  Value of d:  11
++d1  += d1++; Value of d1: 11

//VS2010输出结果
    a += a++;  Value of a:  9
    b += ++b;  Value of b:  10
(++c) += c;    Value of c:  10
 ++c1 += c1;   Value of c1: 10
(++d) += d++;  Value of d:  11
++d1  += d1++; Value of d1: 11
请按任意键继续. . .
```

------

## 注意点
- (i++)不能做左值，而(++i)可以做左值是针对于c++编译器而言
- 在C编译器里面，无论是(i++)还是(i++)都不能做左值(在GNU和VS2010里面编译不通过)

------

## TIPS
### GNU将原码编译成汇编
- `gcc/g++ -S 源文件 -o 汇编文件名`

### VS2010将原码编译成汇编
- 编译链接...
- 然后按下F10启动调试
- 再按下Alt + 8

