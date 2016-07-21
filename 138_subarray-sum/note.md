```
@Copyright:LintCode
@Author:   holiday_0802
@Problem:  http://www.lintcode.com/problem/subarray-sum
@Language: Markdown
@Datetime: 16-06-03 17:26
```

1. hashtable [sum] = index, 当两个index对应的sum相同时，说明之间的几个元素的加和为0. 
2. hashtable[0] = -1, 处理边界条件，case[1, -1]。 返回值为【0,1】