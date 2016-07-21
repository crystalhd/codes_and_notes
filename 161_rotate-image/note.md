```
@Copyright:LintCode
@Author:   holiday_0802
@Problem:  http://www.lintcode.com/problem/rotate-image
@Language: Markdown
@Datetime: 16-06-07 18:43
```

1. matrix的操作，rotate cw 90, == 先沿对角线翻转，然后沿垂直中轴翻转。
2. 沿对角线翻转的时候，i = 0~rows-1; j = 0~i;
3. 如果是ccw rotate 90 == 先沿对角线翻转，然后沿水平中轴翻转