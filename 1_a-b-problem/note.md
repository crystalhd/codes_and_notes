```
@Copyright:LintCode
@Author:   holiday_0802
@Problem:  http://www.lintcode.com/problem/a-b-problem
@Language: Markdown
@Datetime: 16-06-08 16:42
```

方法1：通过bit shift得到每个a和b对应位置的值，加对应进位carry，得到值。注意的是，不可以通过判断a和b是否为0， 而是判断shift是否小于32
方法2：通过两个操作，（a^b)是不考虑进位的相加，(a&b)<< 1 是对应的进位操作，循环直到carry=1结束
两个方法用时都是5ms

推荐第二种方法，因为right shift of a signed negative integer is impelementation-dependent operation.
Visual C++ uses the sign bit to fill vacated bit positions, there is no guarantee that other implementations also do so.