package casestudy.iiop;

import javax.naming.*;
import javax.rmi.PortableRemoteObject;

public class RemoteClient {

  public static void main(String[] args) {
    Context ic;
    Object ref;
    AddressBook ab;
    
    try {
      ic = new InitialContext();
      
      ref = ic.lookup("AddressBookService");
      System.out.println("Client: obtained ref to AddressBookServer.");
      
      ab = (AddressBook) PortableRemoteObject.narrow(ref, AddressBook.class);
      
      System.out.println("addres: " + ab.getAddress("hayco"));
    } catch (Exception e) {
      System.out.println("Exception: " + e);
    }
  }
}
