/*
use a hashtable to record the frequency of chars in target,
maintain a window. 
  right: increase index, untill all char in T has included.
  left: after right index is fixed, increase left, if the s[left] not in T, or
     after remove s[left], window still contains all the chars in T.
two vectors:
	charRecord(256, 0) record the frequency of chars in T
	ocurRecord(256, 0) record the chars occured in the S

record minimum string start, end
bool find = false;
iterate i in 0 : s.size()-1

	if ocurRecord[s[i]] <= charRecord[s[i]] i++; ++length; continue;
	if (length == t.size()) find a string
	  next, update begin. if ocurRecord[s[begin]] > charRecord[s[begin]] ++begin; 
	update minimum length, start, end
			find = true;
	begin ++ ;
	i = end;
	occurRecord[s[begin]] -- ;
	length -- ;
	continue ;

until i = s.size()-1;

result = s.substr(start, end-start+1)

*/

class Solution {
public:    
    /**
     * @param source: A string
     * @param target: A string
     * @return: A string denote the minimum window
     *          Return "" if there is no such a string
     */
    string minWindow(string &s, string &t) {
        // write your code here
        string results = "";
        if (s.size() == 0 || t.size() == 0 || s.size() < t.size()) {
            return results;
        }
        // record the frequency of chars in T
        std::vector<char> charRecord(256, 0);
        for (int i = 0; i < t.size(); ++i) {
            ++charRecord[t[i]];
        }
        std::vector<char> ocurRecord(256, 0);
        int start = 0;
        int end = 0;
        int minStart = 0;
        int minEnd = 0;
        int minlength = s.size();
        bool find = false;
        int length = 0;
        while (end < s.size()) {
            ++ocurRecord[s[end]];
            if (ocurRecord[s[end]] <= charRecord[s[end]]) {
                ++length;
            }
            ++end;
            if (length == t.size()) {
                while (ocurRecord[s[start]] > charRecord[s[start]]) {
                    --ocurRecord[s[start]];
                    ++start;
                }
                if (end-start <= minlength) {
                    minlength = end-start;
                    minStart = start;
                    minEnd = end-1;
                    find = true;
                    std::cerr<<minStart<<" "<<minlength<<";";
                }
                --ocurRecord[s[start]];
                start++;
                --length;
            }
        }
        std::cerr<<minStart<<" "<<minlength<<" ";
        return find == false ? "" : s.substr(minStart, minlength);
    }
};


