```
@Copyright:LintCode
@Author:   holiday_0802
@Problem:  http://www.lintcode.com/problem/find-minimum-in-rotated-sorted-array
@Language: Markdown
@Datetime: 16-07-08 16:45
```

mine:
while(start+1< end)
if (num[mid] > num[end]) {
                start = mid;
            } else {
                end = mid;
            }
			
better:
while(start <end)
if(num[mid]<num[end]) 
                end = mid;
            else 
           **     start = mid+1;**