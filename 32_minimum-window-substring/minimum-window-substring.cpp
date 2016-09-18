/*
use a hashtable to record the frequency of chars in target,
maintain a window. 
  right: increase index, untill all char in T has included.
  left: after right index is fixed, increase left, if the s[left] not in T, or
     after remove s[left], window still contains all the chars in T.
*/

