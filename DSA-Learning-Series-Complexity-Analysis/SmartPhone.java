import java.util.*;
class SmartPhone
{
	public static void main (String[] args) throws java.lang.Exception
	{
		Scanner sc = new Scanner(System.in);
		long N = sc.nextLong();
		List<Long> budget = new ArrayList<Long>();
		for(int i=0;i<N;i++)
		{
			budget.add(sc.nextLong());
		}
		Collections.sort(budget);
		long max = -1;
		for(int i=0;i<budget.size();i++)
		{
			if (budget.get(i)*(budget.size()-i) > max)
				max = budget.get(i)*(budget.size()-i);
		}
        System.out.print(max);
        sc.close();
	}
}
