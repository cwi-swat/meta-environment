package casestudy.iiop;

import javax.naming.Context;
import javax.naming.InitialContext;

public class AddressBookServer {

  public static void main(String[] args) {
    try {
      AddressBookImpl ab = new AddressBookImpl();
      Context initialContext = new InitialContext();
      initialContext.rebind("AddressBookService", ab);
      System.out.println("AddressBookServer running...");
    } catch (Exception e) {
      System.out.println("Trouble: " + e);
    }
  }
}
