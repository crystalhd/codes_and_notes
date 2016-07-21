```
@Copyright:LintCode
@Author:   holiday_0802
@Problem:  http://www.lintcode.com/problem/insert-interval
@Language: Markdown
@Datetime: 16-06-13 21:42
```

如果在current Interval前面，先insert new再insert current
如果交叉 update new interval
如果在current interval后面，先insert current

使用一个bool变量indicate new是否已经insert进去，已经完成insert后，只需按序保存current interval