package lab5;
import static org.junit.Assert.assertEquals;
import org.junit.Test;
import balloon4.Balloon;
public class BalloonTests {
	
	// 1) the pop() method is not popping the balloon if it is over the balloon so the if statement's condition is wrong
	// 2) if the balloon is blown up then popped, the pop() is still allowing the blow() method to add the amount to the balloon.
	// 3) the method blow() is only being allowed to be called once and is being held back by a variable.
	// 4) the deflate() method is not making the radius go to zero.
	
    // margin of error for floating-point comparisons
    private static final double EPSILON = 10e-07;
    
    @Test
    public void testInitialPop()
    {
    	Balloon x = new Balloon(5);
    	assertEquals(false, x.isPopped());
    }
    
    @Test
    public void testInitialRadius()
    {
    	Balloon x = new Balloon(5);
    	assertEquals(0, x.getRadius());
    }
    
	@Test
    public void testInitalRadius()
    {
		Balloon x = new Balloon(5);
	    assertEquals(0, x.getRadius(), EPSILON);
    }
	@Test
	public void testBlow()
	{
		Balloon x = new Balloon(5);
		x.blow(4);
		assertEquals(4, x.getRadius(), EPSILON);
	}
	
	@Test
	public void testDefate()
	{
		Balloon x = new Balloon(5);
		x.blow(4);
		x.deflate();
		assertEquals(0, x.getRadius(), EPSILON);
	}
	
	@Test
	public void testPop()
	{
		Balloon x = new Balloon(5);
		x.blow(4);
		x.pop();
		assertEquals(0,x.getRadius(), EPSILON);
	}
	
	@Test
	public void testIfBalloonPopped()
	{
		Balloon x = new Balloon(5);
		x.blow(6);
		assertEquals(0,x.getRadius(), EPSILON);
	}
	
	@Test
	public void testIsPoppedAfterPop()
	{
		Balloon x = new Balloon(5);
		x.blow(6);
		assertEquals(true, x.isPopped());
	}
	
	@Test
	public void testBlowAfterPop()
	{
		Balloon x = new Balloon(5);
		x.blow(2);
		x.blow(2);
		assertEquals(4, x.getRadius());
	}
	
	@Test
	public void testBlowAfterPop2()
	{
		Balloon x = new Balloon(5);
		x.blow(3);
		x.blow(4);
		assertEquals(0, x.getRadius());
	}
	
	@Test
	public void testIsPoppedAfterDeflated()
	{
		Balloon x = new Balloon(5);
		x.blow(4);
		x.deflate();
		assertEquals(false, x.isPopped());
	}
	
	@Test
	public void testBalloonOver10()
	{
		Balloon x = new Balloon(10);
		x.blow(11);
		assertEquals(true, x.isPopped());
		
	}
	
	@Test
	public void testPopFunction()
	{
		Balloon x = new Balloon(10);
		x.blow(7);
		x.pop();
		assertEquals(true, x.isPopped());
	}
	
	@Test
	public void testConstructorOver10()
	{
		Balloon x = new Balloon(11);
		assertEquals(0, x.getRadius());
		
	}
	
	@Test
	public void testConstructor0Deflate()
	{
		Balloon x = new Balloon(0);
		x.deflate();
		assertEquals(0, x.getRadius());
	}
	
	@Test
	public void testBlowDeflateBlowRadius()
	{
		Balloon x = new Balloon(10);
		x.blow(8);
		x.deflate();
		x.blow(5);
		assertEquals(5, x.getRadius());

	}
	
	@Test
	public void testBlowDeflateBlowIsPopped()
	{
		Balloon x = new Balloon(10);
		x.blow(8);
		x.deflate();
		x.blow(5);
		assertEquals(false, x.isPopped());
	}
	
	@Test
	public void testDeflateEmptyBalloon()
	{
		Balloon x = new Balloon(0);
		x.deflate();
		assertEquals(0, x.getRadius());
	}
	
	@Test
	public void testPopEmptyBalloonGetRadius()
	{
		Balloon x = new Balloon(0);
		x.pop();
		assertEquals(0 , x.getRadius());
	}
	
	@Test
	public void testBlowPopBlow(){
		Balloon x = new Balloon(10);
		x.blow(5);
		x.pop();
		x.blow(3);
		assertEquals(0, x.getRadius());
	}
	
	@Test
	public void testBlowPopBlow2(){
		Balloon x = new Balloon(10);
		x.blow(5);
		x.pop();
		x.blow(3);
		assertEquals(true, x.isPopped());
	}
}
