package lab5;

public class Basketball
{
	public double diameter;
	public boolean inflated;
	
	public Basketball(double givenDiameter)
	{
		diameter = givenDiameter;
		inflated = false;
	}
	
	public boolean isDribbleable()
	{
		if(inflated == true)
			return true;
		return false;
	}
	
	public double getDiameter()
	{
		return diameter;
	}
	
	public double getCircumference()
	{
		// return 0;
		return diameter * 3.14;
	}
	
	public void inflate()
	{
		inflated = true;
	}
}
