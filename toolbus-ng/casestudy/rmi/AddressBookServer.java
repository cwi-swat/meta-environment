package casestudy.rmi;

import java.rmi.Naming;

public class AddressBookServer {
  public AddressBookServer() {
    try {
      AddressBook ab = new AddressBookImpl();
      Naming.bind("rmi://localhost:1099/AddressBookService", ab);
    } catch(Exception e) {
      System.out.println("Trouble: " + e);
    }
  }
  
  public static void main(String[] args) {
    new AddressBookServer();
  }
}
