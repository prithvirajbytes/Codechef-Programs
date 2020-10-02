import java.util.*;
class Carvans
{
    static long getAnswer(int N, List<Long> speeds)
	{
		if (N == 1)
			return 1;
		else
		{
			int count = 1;
			long fs = speeds.get(0);
			for(int i=1;i<speeds.size();i++)
			{
				long cs = speeds.get(i);
				if(cs < fs)
				{
					fs = cs;
					count++;
				}
			}
			return count;
		}
	}
	public static void main (String[] args) throws java.lang.Exception
	{
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		while(T-- > 0)
		{
			int N = sc.nextInt();
			List<Long> speeds = new ArrayList<Long>();
			for(int i=0;i<N;i++)
				speeds.add(sc.nextLong());
			long result = getAnswer(N,speeds);
			System.out.println(result);
        }
        sc.close();
	}
}
