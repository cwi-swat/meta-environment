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

  private IAddressBookEntry getEntry(int id) {
    return (IAddressBookEntry) addressById.get(new Integer(id));
  }

  public int createEntry() {
    int id = createUniqueID();
    IAddressBookEntry entry = new AddressBookEntry();
    addressById.put(new Integer(id), entry);
    return id;
  }

  public void deleteEntry(int id) throws RemoteException {
    System.out.println("delete: " + getEntry(id));
    addressById.remove(new Integer(id));
  }

  public void setName(int id, String name) throws RemoteException {
    IAddressBookEntry entry = getEntry(id);
    addressByName.remove(name);
    addressByName.put(name, new Integer(id));
    entry.setName(name);
    System.out.println("setName -> entry: " + entry);
  }

  public void setAddress(int id, String address) throws RemoteException {
    IAddressBookEntry entry = getEntry(id);
    entry.setAddress(address);
    System.out.println("setAddress -> entry: " + entry);
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
