```
@Copyright:LintCode
@Author:   holiday_0802
@Problem:  http://www.lintcode.com/problem/insertion-sort-list
@Language: Markdown
@Datetime: 16-06-19 20:31
```

insertion sort:
the first element is considered to be sorted.
start with the first new element:
  if the new element is larger than the last sorted element, keep the location, thsi new element is the new lastest sorted element
  if the element is smaller than the last sorted element, compare the sorted one from the latest one backwards, swap these two element,  until find the sorted element is smaller or equal to the new one,
  