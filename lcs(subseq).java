import java.util.*;

public class Main {

  private static int lcs(String s1, String s2){
    int m = s1.length(), n = s2.length();
    int[][] dp = new int[m+1][n+1];
    int maxLen = 0;
    for(int i = 1; i <= m; i++){
      for(int j = 1; j <=n ; j++){
        if(s1.charAt(i-1)==s2.charAt(j-1)){
            dp[i][j] = dp[i-1][j-1]+1;
        }else{
          dp[i][j] = Math.max(dp[i][j-1],dp[i-1][j]);
        }
        maxLen = Math.max(maxLen,dp[i][j]);
      }
      
    }
    return maxLen;
  }

    public static void main(String[] args) {
      Scanner sc = new Scanner(System.in);
      String s1 = sc.nextLine(), s2 = sc.nextLine();
      int maxLen = lcs(s1,s2);
      System.out.println(maxLen);
    }
}