/*
 * @lc app=leetcode.cn id=38 lang=c
 *
 * [38] 报数
 *
 * https://leetcode-cn.com/problems/count-and-say/description/
 *
 * algorithms
 * Easy (48.78%)
 * Total Accepted:    25.4K
 * Total Submissions: 52K
 * Testcase Example:  '1'
 *
 * 报数序列是一个整数序列，按照其中的整数的顺序进行报数，得到下一个数。其前五项如下：
 * 
 * 1.     1
 * 2.     11
 * 3.     21
 * 4.     1211
 * 5.     111221
 * 
 * 
 * 1 被读作  "one 1"  ("一个一") , 即 11。
 * 11 被读作 "two 1s" ("两个一"）, 即 21。
 * 21 被读作 "one 2",  "one 1" （"一个二" ,  "一个一") , 即 1211。
 * 
 * 给定一个正整数 n（1 ≤ n ≤ 30），输出报数序列的第 n 项。
 * 
 * 注意：整数顺序将表示为一个字符串。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 输入: 1
 * 输出: "1"
 * 
 * 
 * 示例 2:
 * 
 * 输入: 4
 * 输出: "1211"
 * 
 * 
 */
char* countAndSay(int n) {

    char* prev;
    char* res = (char*)malloc(2 * sizeof(char));
    res[0] = '1';
    res[1] = 0;
    // res = "1";
    int count;
    int index;
    char ch;
    for(int i = 1; i < n; i++) {
        prev = res;
        res = (char*)malloc(1 + 2 * strlen(prev) * sizeof(char));
        count = 0;
        index = 0;
        ch = prev[0];

        for(int j = 0; ch; j++)
            if (prev[j] == ch)
                count++;
            else {
                res[index] = '0' + count;
                res[index+1] = ch;
                index += 2;
                ch = prev[j];
                count = 1;
            }
        free(prev);
        res[index] = 0;
    }
    return res;
        
}

