```
@Copyright:LintCode
@Author:   holiday_0802
@Problem:  http://www.lintcode.com/problem/add-two-numbers
@Language: Markdown
@Datetime: 16-05-28 17:16
```

while循环条件要设为l1!=null || l2 !=null,
而不是 l1!=null && l2 !=null,
设为后者的话，离开while后需要考虑的太多。