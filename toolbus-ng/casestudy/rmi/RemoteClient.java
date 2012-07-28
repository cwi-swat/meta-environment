package casestudy.rmi;

import java.rmi.Naming;

public class RemoteClient {
  public static void main(String[] args) {
    try {
      AddressBook ab = (AddressBook) Naming.lookup("rmi://localhost/AddressBookService");
      //System.out.println("lookup '"+args[0]+"': " + ab.getAddress(args[0]));

      Address a1 = ab.getAddress("john");
      System.out.println("john : " + a1.getStreet() + " " + a1.getNumber());

      Address a2 = ab.getAddress("guest");
      System.out.println("guest: " + a2.getStreet() + " " + a2.getNumber());

      System.out.println("equal: " + a1.equals(a2));
      System.out.println("a1 == a2: " + ((a1 == a2) ? "yes" : "no"));

    } catch(Exception e) {
      throw new RuntimeException(e);
    }
  }
}
