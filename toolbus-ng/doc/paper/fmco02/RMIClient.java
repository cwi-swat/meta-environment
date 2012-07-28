import java.rmi.Naming;

public class RMIClient {
  public static void main(String[] args) {
    String name = "rmi://localhost/IAddressBookService";
    try {
      IAddressBookService service = (IAddressBookService) Naming.lookup(name);
      int id = service.createEntry();
      service.setName(id, "John Doe");
      service.setAddress(id, "4242 Elm Street");
      service.deleteEntry(id);
    } catch(Exception e) {
      throw new RuntimeException(e);
    }
  }
}

