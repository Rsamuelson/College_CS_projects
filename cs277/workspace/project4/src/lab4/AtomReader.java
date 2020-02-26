package lab4;

import java.util.Scanner;
import lab2.Atom;

public class AtomReader
{
  public static void main(String[] args)
  {
     Scanner parser = new Scanner("Uranium,U,92,92,146");
     parser.useDelimiter(",");

     // Skip over first two fields.  Notice how we can just ignore the value
     // returned by the next() method?
     parser.next();
     parser.next();
     int protonCount = parser.nextInt();
     int electronCount = parser.nextInt();
     int neutronCount = parser.nextInt();

     Atom u238 = new Atom(protonCount, neutronCount, electronCount);
  }
}