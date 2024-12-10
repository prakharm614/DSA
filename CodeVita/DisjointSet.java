import java.io.*; 
import java.util.*; 

public class DisjointSet {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        int n = s.length();
        
        int[] worth = new int[n];
        for (int i = 0; i < n; i++) {
            worth[i] = sc.nextInt();
        }

        Stack<Character> s1 = new Stack<>();
        s1.push(s.charAt(0));  
        int ans = 0;
        int index = 0; 

        for (int i = 1; i < n; i++) {
            char ch = s.charAt(i);
            char prev = s1.peek(); 

            if (prev == ch) {
                if (worth[i] >= worth[index]) {
                    ans += worth[index]; 
                    index = i;         
                } else {
                    ans += worth[i];    
                }
            } else {
                index = i;              
                s1.push(ch);          
            }
        }

        System.out.println(ans);
    }
}
