```
@Copyright:LintCode
@Author:   holiday_0802
@Problem:  http://www.lintcode.com/problem/plus-one
@Language: Markdown
@Datetime: 16-06-02 19:36
```

方法1，依次保存bit, from least signifcant to most significant ,
  then reverse
方法2，直接预留vector的大小，依次更新每个位置上的数字。最后carry为1的话，在vector.begin()处insert 1.
