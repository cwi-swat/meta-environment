import java.rmi.*;
import java.rmi.server.*;
import java.util.*;

public class RMIAddressBookService
  extends UnicastRemoteObject
  implements IAddressBookService
{
  private static int id = 0;
  private static int createUniqueID() { return id++; }

  private Map addressById;
  private Map addressByName;

  public RMIAddressBookService() throws RemoteException {
    super();
    addressById = new HashMap();
    addressByName = new HashMap();
  }

  private AddressBookEntry getEntry(int id) {
    return (AddressBookEntry) addressById.get(new Integer(id));
  }

  public int createEntry() {
    Integer id = new Integer(createUniqueID());
    AddressBookEntry entry = new AddressBookEntry();
    addressById.put(id, entry);
    return id.intValue();
  }

  public void deleteEntry(int id) {
    addressById.remove(new Integer(id));
  }

  public void setName(int id, String name) {
    AddressBookEntry entry = getEntry(id);
    addressByName.remove(name);
    addressByName.put(name, new Integer(id));
    entry.setName(name);
  }

  public void setAddress(int id, String address) {
    getEntry(id).setAddress(address);
  }

  public int findByName(String name) {
    Integer id = (Integer) addressByName.get(name);
    return id == null ? -1 : id.intValue();
  }

  public static final void main(String args[]) {
    String name = "//localhost/IAddressBookService";
    try {
      IAddressBookService service = new RMIAddressBookService();
      Naming.rebind(name, service);
      System.out.println("AddressBookService bound");
    } catch (Exception e) {
      System.err.println("Exception: " + e.getMessage());
      e.printStackTrace();
    }
  }
}
