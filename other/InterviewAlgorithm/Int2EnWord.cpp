/*************************************************************************
	> File Name: Int2EnWord.cpp
	> Author: jiexue
	> Mail: jiexuelc@163.com
	> Created Time: Fri 28 Sep 2018 09:32:26 AM CST
	> Description: 给出一个非负整数，输出该数字在英语对应的单词，数字小于2^31-1
        说明：
            1.这里不考虑英语整数读法中and的添加
            2.题目来源https://leetcode.com/problems/integer-to-english-words/
 ************************************************************************/

#include <iostream>
#include <string>
using namespace std;

/*
 * 基本整数到英语的转换实现函数
 */ 
string Int2EnWordBase(int num)
{
    string enstr = "";
    
    switch(num){
        case 1: enstr += "One"; break;
        case 2: enstr += "Two"; break;
        case 3: enstr += "Three"; break;
        case 4: enstr += "Four"; break;
        case 5: enstr += "Five"; break;
        case 6: enstr += "Six"; break;
        case 7: enstr += "Seven"; break;
        case 8: enstr += "Eight"; break;
        case 9: enstr += "Nine"; break;
        case 10: enstr += "Ten"; break;
        case 11: enstr += "Eleven"; break;
        case 12: enstr += "Twlve"; break;
        case 13: enstr += "Thirteen"; break;
        case 14: enstr += "Fourteen"; break;
        case 15: enstr += "Fifteen"; break;
        case 16: enstr += "Sixteen"; break;
        case 17: enstr += "Seventeen"; break;
        case 18: enstr += "Eighteen"; break;
        case 19: enstr += "Nineteen"; break;
        case 20: enstr += "Twenty "; break;
        case 30: enstr += "Thirty "; break;
        case 40: enstr += "Forty "; break;
        case 50: enstr += "Fifty "; break;
        case 60: enstr += "Sixty "; break;
        case 70: enstr += "Seventy "; break;
        case 80: enstr += "Eighty "; break;
        case 90: enstr += "Ninety "; break;        
        defaut: break;
    }
    
    return enstr;
}

/*
 * 小于1000整数到英语的转换实现函数
 */ 
string Int2EnWordLess1000(int num)
{
    if(num <= 0 || num >= 1000)
        return "";
    
    string enstr = "";
    /* 大于100加 Hundred */
    if(num >= 100)
        enstr += Int2EnWordBase(num / 100) + " " + "Hundred ";
    
    /* 转换小于100的部分 */
    num = num % 100;
    if(num > 20)
    {
        enstr += Int2EnWordBase(num /10 * 10);
        if(num % 10 != 0)
            enstr += Int2EnWordBase(num % 10);
    }else
    {
        enstr += Int2EnWordBase(num);
    }
    
    /* 如果最后一个字符为空格，则将其删除 */
    int len = enstr.length();    
    if(enstr.at(len - 1) == ' ')
        enstr.at(len - 1) = '\0';
    
    return enstr;
}

/*
 * 0-(2^31-1)整数到英语的转换实现函数
 */ 
string Int2EnWord(int num)
{
    if(num < 0)
        return "";
    if(num == 0)
        return "zero";
    
    string enstr = "";
    
    int bi = num / 1000000000;  //取得大于十亿的段
    int mi = num % 1000000000 / 1000000;    //取得百万---十亿的段
    int th = num % 1000000000 % 1000000 / 1000;    //取得千---百万的段
    int low = num % 1000000000 % 1000000 % 1000;    //取得千以下的段
    
    if(bi > 0)
        enstr += Int2EnWordLess1000(bi) + " " + "Billion ";
    if(mi > 0)
        enstr += Int2EnWordLess1000(mi) + " " + "Million ";
    if(th > 0)
        enstr += Int2EnWordLess1000(th) + " " + "Thousand ";
    if(low > 0)
        enstr += Int2EnWordLess1000(low);
    
    /* 如果最后一个字符为空格，则将其删除 */
    int len = enstr.length();    
    if(enstr.at(len - 1) == ' ')
        enstr.at(len - 1) = '\0';
    
    return enstr;
}

/*
 * 主函数
 */ 
int main()
{
    string enstr = "";
    int num;
    cout << "-------转换开始，结束输入Ctrl+C-------\n";
    
    while(1)
    {
        cin >> num;
        
        enstr = Int2EnWord(num);

        cout <<"转换结果:\n"<< enstr << endl;
    }
    
    return 0;
    
}
