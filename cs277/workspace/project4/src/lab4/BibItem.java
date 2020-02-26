package lab4;

public class BibItem {
	  private String authors;
	  private String title;
	  private String journal;
	  private int year;
	  private int volume;
	  
	  public BibItem(String givenAuthors, String givenTitle, String givenJournal, int givenYear, int givenVolume)
	  {
	    authors = givenAuthors;
	    title = givenTitle;
	    journal = givenJournal;
	    year = givenYear;
	    volume = givenVolume;
	    toString();
	  }

	  public String toString()
	  {
		  // TODO ...
		  String a = "" + authors + ". " + title + ". " + journal + " " + volume + " (" + year + ").";
		  return a;
	  }
}
