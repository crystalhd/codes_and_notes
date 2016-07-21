```
@Copyright:LintCode
@Author:   holiday_0802
@Problem:  http://www.lintcode.com/problem/string-to-integer-ii
@Language: Markdown
@Datetime: 16-06-04 22:45
```

1.边界条件： 起始为若干空格，忽略空格
2."    52lintcode   ", 遇到char后直接返回当前的结果，而不是0.
3.也有可能有‘+’号
4.每次计算完都要判断是否出界，防止字符串过大，使得long也会overflow
5.