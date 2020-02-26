package lab3;

/**
 * A RabbitModel is used to simulate the growth
 * of a population of rabbits. 
 */
public class RabbitModel2
{
  // TODO - add instance variables as needed
  int x;
  /**
   * Constructs a new RabbitModel.
   */
  public RabbitModel2()
  {
    // TODO
	  x = 0;
	  
  }  
 
  /**
   * Returns the current number of rabbits.
   * @return
   *   current rabbit population
   */
  public int getPopulation()
  {
    // TODO - returns a dummy value so code will compile
    return x;
  }
  
  /**
   * Updates the population to simulate the
   * passing of one year.
   */
  public void simulateYear()
  {
    // TODO
	  x ++;
	  if(x%5 == 0){
		  x = 0;
	  }
  }
  
  /**
   * Sets or resets the state of the model to the 
   * initial conditions.
   */
  public void reset()
  {
    // TODO
	  x = 0;
  }
}