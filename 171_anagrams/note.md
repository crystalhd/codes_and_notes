```
@Copyright:LintCode
@Author:   holiday_0802
@Problem:  http://www.lintcode.com/problem/anagrams
@Language: Markdown
@Datetime: 16-06-02 22:45
```

思路正确。
改进方法，hashtable中的value可以不用vector<string>, 而是使用vector<int> 来记录string的index即可。