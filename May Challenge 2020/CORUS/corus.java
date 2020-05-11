import java.util.*;
class  Main{
      public static void main(String[] args) {
          Scanner scan = new Scanner(System.in);
          int t = scan.nextInt();
          while(t-- >0){
          int N= scan.nextInt();
          int Q= scan.nextInt();
          String s = scan.next();
          int arr[] =  new int[26];
          int max=0;
          for(int i=0;i<s.length();i++){
            arr[s.charAt(i)-'a']+=1;
            max= Math.max(max,arr[s.charAt(i)-'a']);
          }
               
          StringBuilder str = new StringBuilder();
          for(int i=0;i<Q;i++){
              int count=0;
              int c = scan.nextInt();
              if(c<=max){
                for(int j :arr){
                    if(j>c) count+=j-c;
                }
              }
              
              str.append(count+"\n");
          }
          System.out.print(str);
   }
}
}
