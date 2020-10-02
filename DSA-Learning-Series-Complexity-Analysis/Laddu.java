import java.util.*;
class Laddu
{
	public static void main (String[] args) throws java.lang.Exception
	{
	    Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		while(T-- > 0)
		{
			int activities = sc.nextInt();
			String nationality = sc.next();
			sc.nextLine();
			List<Integer> scoreList = new ArrayList<Integer>(Collections.nCopies(4, 0));
			for(int i=0;i<activities;i++)
			{
				String activity_name = sc.next();				
				//0=CONTEST_WON
				//1=>TOP_CONTRIBUTOR
				//2=>BUG_FOUND
				//3=>CONTEST_HOSTED
				if(activity_name.equalsIgnoreCase("CONTEST_WON") || activity_name.equalsIgnoreCase("BUG_FOUND"))
				{
					int value = sc.nextInt();
					if(activity_name.equalsIgnoreCase("CONTEST_WON"))
					{
						int bonus;
						if(value <= 20)
						{
							bonus = (20-value);
						}
						else
						{
							bonus = 0;
						}
						scoreList.set(0, scoreList.get(0)+300+bonus);
					}
					else if(activity_name.equalsIgnoreCase("BUG_FOUND"))
						scoreList.set(2, scoreList.get(2)+value);
				}
				else {
					if(activity_name.equalsIgnoreCase("TOP_CONTRIBUTOR"))
						scoreList.set(1, scoreList.get(1)+300);
					else if(activity_name.equalsIgnoreCase("CONTEST_HOSTED"))
						scoreList.set(3, scoreList.get(3)+50);
				}
			}
			int totalScore = 0;
			for(int i=0;i<scoreList.size();i++)
				totalScore += scoreList.get(i);
			if(nationality.equals("INDIAN"))
			{
				int redeemable = 200;
				System.out.println(totalScore/redeemable);
			}
			else
			{
				int redeemable = 400;
				System.out.println(totalScore/redeemable);
			}	
        }
        sc.close();
	}
}
