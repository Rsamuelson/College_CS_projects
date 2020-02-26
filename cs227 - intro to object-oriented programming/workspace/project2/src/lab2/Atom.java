package lab2;
/**
 * Model of a Atom for use in quality control simulations.
 */
public class Atom {
	
	/**
	 * number of protons
	 */
	private int p;
	
	/**
	 * number of neutrons
	 */
	private int n;
	
	/**
	 * number of electrons
	 */
	private int e;
	
	/**
	 * constructor for the Atom class
	 * @param givenProtons
	 * 	number of protons
	 * @param givenNeutrons
	 * 	number of neutrons
	 * @param givenElectrons
	 *  number of electorns
	 */
	public Atom(int givenProtons, int givenNeutrons, int givenElectrons){
		p = givenProtons;
		n = givenNeutrons;
		e = givenElectrons;
	}
	
	/**
	 * returns the atomic mass of the Atom(protons minus the neutrons)
	 * @return
	 * 	the value of the Atomic Mass
	 */
	public int getAtomicMass(){
		int value = p + n;
		return value;
	}
	
	/**
	 * finds the charge of the Atom(protons minus the electrons)
	 * @return 
	 * 	the chargh of the atom
	 */
	public int getAtomicCharge(){
		int charge = p - e;
		return charge;
	}
	
	/**
	 * decreases the protons and the neutrons by 2;
	 */
	public void decay(){
		p = p - 2;
		n = n - 2;
	}
	
}
