```
@Copyright:LintCode
@Author:   holiday_0802
@Problem:  http://www.lintcode.com/problem/two-sum
@Language: Markdown
@Datetime: 16-06-03 02:23
```

1. 对于hashtable，防止有重复数字出现，例如[0,4,3,0], 0，在每个num保存进map前，先查看target-num是不是已经在里面了，如果有的话，直接得出结果；没有的话，将新的num保存进去。
2. non-hashtable的做法：需要借助别的struct，将value和index链接起来。
重载操作符！不要忘记两个const
bool operator<(const Node& node1) const
 {
	 return val_ < node1.val_;
 }