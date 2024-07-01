class Solution {
  bool backspaceCompare(String s, String t) {
    String ss = processString(s);
    String tt = processString(t);
    return ss == tt;
  }

  String processString(String str) {
    String result = '';
    for (int i = 0; i < str.length; i++) {
      if (str[i] == '#') {
        if (result.isNotEmpty) {
          result = result.substring(0, result.length - 1);
        }
      } else {
        result += str[i];
      }
    }
    return result;
  }
}