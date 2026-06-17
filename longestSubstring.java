import java.util.*;

public class Main {
  private static boolean isVowel(char ch){
    ch = Character.toLowerCase(ch);
    return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
  }

  private static int longestSubstring(String s){
    HashMap<Integer,Integer> map = new HashMap<>();
    int value = 0;
    int index = -1;
    int maxLen = 0;
    map.put(0,-1);
    for(int i = 0; i < s.length(); i++){
      char ch = s.charAt(i);
      if(isVowel(ch)){
        value++;
      }else{
        value--;
      }
      if(map.containsKey(value)){
        int len = i - map.get(value);
        if(len > maxLen){
          maxLen = len;
        }
      }
    }
    return maxLen;
  }

    public static void main(String[] args) {
      Scanner sc = new Scanner(System.in);
      String s = sc.next();
      int maxLen = longestSubstring(s);
      System.out.println(maxLen);

    }
}