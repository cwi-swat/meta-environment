//package casestudy.rmi;

import java.rmi.Naming;

public class RemoteClient {
  public static void main(String[] args) {
    try {
      AddressBook ab = (AddressBook) Naming.lookup("rmi://localhost/AddressBookService");
      //System.out.println("lookup '"+args[0]+"': " + ab.getAddress(args[0]));

      String a1 = ab.getAddress("hayco");
      System.out.println("hayco: " + a1);

      String a2 = ab.getAddress("loge");
      System.out.println("loge : " + a2);

      System.out.println("equal: " + a1.equals(a2));
      System.out.println("a1 == a2: " + ((a1 == a2) ? "yes" : "no"));

    } catch(Exception e) {
      throw new RuntimeException(e);
    }
  }
}
