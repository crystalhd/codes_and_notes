```
@Copyright:LintCode
@Author:   holiday_0802
@Problem:  http://www.lintcode.com/problem/climbing-stairs
@Language: Markdown
@Datetime: 16-05-30 15:53
```

1. 用递归方法，代码简单，但是会报runtime error
2. dynamic programming，可以使用vector存储所有的值，也可以只用三个变量存储有用信息
3. n==0的时候，返回值是1，而不是0.