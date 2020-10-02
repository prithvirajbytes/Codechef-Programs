import java.util.*;
class LAPIN
{
	public static void main (String[] args) throws java.lang.Exception
	{
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		sc.nextLine();
		while(T-- > 0) {
			int[] arr_1 = new int[26];
			int[] arr_2 = new int[26];
			String word = sc.nextLine();
			String word1 = "";
			String word2 = "";
			if (word.length() %2 == 0) {
				for(int i=0;i<(word.length()/2);i++)
				{
					word1 += word.charAt(i);
				}
				for(int i=word.length()/2; i<word.length(); i++)
				{
					word2 += word.charAt(i);
				}
				
			}
			else {
				for(int i=0;i<(word.length()/2);i++)
				{
					word1 += word.charAt(i);
				}
				for(int i=(word.length())/2 + 1; i<word.length(); i++)
				{
					word2 += word.charAt(i);
				}
				
			}
			for(int i=0;i<word1.length();i++)
			{
				int index1 = (int)word1.charAt(i)-97;
				int index2 = (int)word2.charAt(i)-97;
				arr_1[index1]++;
				arr_2[index2]++;
			}
			boolean flag = false;
			for(int i=0;i<arr_1.length;i++)
			{
				if(arr_1[i] != arr_2[i])
				{
					flag=true;
					break;
				}
			}
			if(flag)
				System.out.println("NO");
			else
				System.out.println("YES");
        }
        sc.close();
	}
}
