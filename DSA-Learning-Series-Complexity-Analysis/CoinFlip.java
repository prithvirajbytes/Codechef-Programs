import java.util.*;
class CoinFlip
{
	public static void main (String[] args) throws java.lang.Exception
	{
	    Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		while(T-- > 0)
		{
			int G = sc.nextInt();
			while(G-- > 0)
			{
				int I = sc.nextInt();
				int N = sc.nextInt();
				int Q = sc.nextInt();
				int even = N/2;
				int odd = N-even;
				int result = 0;
				if(N%2 == 0)
				{
					//odd position = same
					//even position = reverse
					result = N/2;
				}
				else
				{
					//even position = same
					//odd position = reverse
					if(Q == 1)
					{
						//find no of H
						if(I == 1)
						{
							//initially all are H
							result = N/2;
						}
						else if(I == 2)
						{
							//initially all are T
							result = (N/2)+1;
						}
					}
					else if(Q == 2)
					{
						//find no of T
						if(I == 1)
						{
							//initially all are H
							result = (N/2)+1;
						}
						else if(I == 2)
						{
							//initially all are T
							result = N/2;
						}
					}
				}
				System.out.println(result);
			}
        }
        sc.close();
	}
}
