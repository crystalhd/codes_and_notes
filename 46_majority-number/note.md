```
@Copyright:LintCode
@Author:   holiday_0802
@Problem:  http://www.lintcode.com/problem/majority-number
@Language: Markdown
@Datetime: 16-06-01 23:52
```

1. 如果用sort，中间的元素即为正确答案。但是用时O(nlogn)，不满足条件O(n)
2. 借助Moore voting algorithm，时刻keep 一个counter，以及一个candidate，如果相等，counter加1， 如果不等，count减1，直到counter为0，换下一个candidate，重置counter为1. basic idear在于抵消掉不一样的element，剩下的那个就是出现次数超过一半的元素。